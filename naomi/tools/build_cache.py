"""Cache compiler artifacts, never verification decisions or reconstructed ROMs."""
import hashlib
import json
import os
from pathlib import Path
import shutil
import tempfile


def digest(blob):
    return hashlib.sha256(blob).hexdigest()


def shared_inputs(root):
    paths = [root / 'config/compiler.json']
    paths += [root / 'tools' / name for name in ('build.py', 'core.py', 'build_cache.py')]
    paths += sorted((root / 'src/include').glob('*.h'))
    paths += sorted(p for p in (root / 'toolchain').rglob('*')
                    if p.is_file() and 'naomi-sdk/lib' not in p.as_posix())
    return digest(json.dumps([(str(p.relative_to(root)), digest(p.read_bytes()))
                              for p in paths], separators=(',', ':')).encode())


def unit_key(root, unit, shared):
    path = root / unit.get('source', unit.get('library', ''))
    return digest(json.dumps({'schema': 1, 'shared': shared, 'unit': unit,
                              'content': digest(path.read_bytes())},
                             sort_keys=True, separators=(',', ':')).encode())


def prepare_work(root, work, unit=None):
    work.mkdir(parents=True, exist_ok=True)
    files = list((root / 'toolchain/hitachi-shc-5.1r08').iterdir())
    if unit and 'library' in unit:
        files.append(root / unit['library'])
    for source in files:
        destination = work / source.name
        if not destination.exists():
            # Private compiler scratch directories, shared immutable executables.
            try:
                os.link(source, destination)
            except OSError:
                shutil.copy2(source, destination)


class ArtifactCache:
    def __init__(self, root, shared, clean=False):
        self.root, self.shared, self.clean = root, shared, clean
        self.directory = root / 'build/cache'
        self.directory.mkdir(parents=True, exist_ok=True)

    def compile(self, unit, work, compiler):
        key = unit_key(self.root, unit, self.shared)
        entry = self.directory / key
        stem = unit['id']
        if not self.clean:
            try:
                manifest = json.loads((entry / 'manifest.json').read_text())
                if manifest['key'] != key:
                    raise ValueError('Cache key mismatch')
                files = manifest['files']
                if not isinstance(files, dict):
                    raise ValueError('Invalid cache manifest')
                if not {stem + '.elf', stem + '.map'}.issubset(files):
                    raise ValueError('Incomplete cache entry')
                blobs = {}
                for name, expected in files.items():
                    if Path(name).name != name or not name.startswith(stem + '.'):
                        raise ValueError('Invalid cache artifact path')
                    blob = (entry / name).read_bytes()
                    if digest(blob) != expected:
                        raise ValueError('Corrupt cache artifact')
                    blobs[name] = blob
                work.mkdir(parents=True, exist_ok=True)
                for name, blob in blobs.items():
                    (work / name).write_bytes(blob)
                return blobs[stem + '.elf'], blobs[stem + '.map'].decode(), True
            except (OSError, ValueError, KeyError, TypeError):
                pass  # Missing/corrupt artifacts require a genuine compilation.
        prepare_work(self.root, work, unit)
        elf, link = compiler(unit, work, [])
        with tempfile.TemporaryDirectory(prefix='cache-write-', dir=self.directory) as temporary:
            staged = Path(temporary)
            files = {}
            for suffix in ('.elf', '.map', '.src', '.log', '.lnk', '.c'):
                source = work / (stem + suffix)
                if source.exists():
                    blob = source.read_bytes()
                    (staged / source.name).write_bytes(blob)
                    files[source.name] = digest(blob)
            (staged / 'manifest.json').write_text(json.dumps({'key': key, 'files': files}))
            # The build owns the output lock; readers see only complete entries.
            if entry.exists():
                shutil.rmtree(entry)
            staged.rename(entry)
        return elf, link, False
