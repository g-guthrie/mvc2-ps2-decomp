# Bundled build inputs

`mvc2-ps2-build-inputs.tar.gz` supplies the loaded retail image, exact retail ELF,
MWCCPS2 3.0.3 and 3.0-011126 with support DLLs, Linux/macOS Wibo 1.2.0, and a
SHA-256 manifest. It contains no account credentials or access tokens.

From the repository root:

```sh
.venv/bin/python tools/bootstrap_private_inputs.py
. private/build.env
make split hybrid test report PYTHON="$PYTHON"
```

See `docs/CLOUD_BUILD.md` for dependency setup. The bootstrap verifies the pinned
archive and file hashes before extracting inputs into ignored `private/`.
