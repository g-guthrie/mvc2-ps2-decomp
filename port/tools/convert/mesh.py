#!/usr/bin/env python3
"""MvC2 PS2 POL mesh packs (STGxxPOL, DMxxPOL, EFKYPOL ...) -> OBJ/MTL/PNG and a
reference software render. Stdlib only; contains no asset bytes.

Format (see port/docs/ASSET_FORMATS.md section 6 for the full description and
the decomp functions each field comes from):

  file header: u32 off[3], made absolute by func_0016F4D0
    off[0] -> model container (func_003F1F10 masks 1 = meshes, 2 = materials,
              4 = texture table)
    off[1] -> node container (type 0 = root list, others = nodes)
    off[2] -> u32 per-mesh draw flags (func_00415A00 / func_001537D0)
  container: {u32 mask, u32 count, u32 size} then `count` chunks, each
             {u32 type, u32 count, u32 size, ...} (size includes the header)
  mesh chunk (type & 0xFF == 2, (type & 0xFFC3FF00) = attribute set):
    sub-chunks keyed by type: 0x100 strips {u32 n|0x80000000 flag, u32 idx[n]}...,
    0x200 material list (u32 x count, indices into the material table),
    0x400 per-strip local material (u32 x nstrips), 0x800 positions (3 f32),
    0x1000 normals (3 f32), 0x4000 UV (2 f32), 0x8000 colour (4 f32 R,G,B,A in 0..255)

usage:
  mesh.py ISO OUTDIR STAGE              e.g. mesh.py $ISO $OUT/mesh 0  (STG00POL/TEX)
  mesh.py ISO OUTDIR STAGE --render     also write a reference render (slow, pure Python)
  mesh.py ISO OUTDIR STAGE --info       print the structure only
  options: --roots all|0,3,...  (default all), --size WxH (render size, default 640x480)
"""
import math, os, struct, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from iso import Iso
from afs import Afs
import png
import tim2
import textures


def _u32(d, o):
    return struct.unpack_from('<I', d, o)[0]


def chunks(d, base):
    """Children of a container at `base`: list of (offset, type, count, size)."""
    out = []
    o = base + 12
    for _ in range(_u32(d, base + 4)):
        t, n, sz = struct.unpack_from('<III', d, o)
        out.append((o, t, n, sz))
        o += sz
    return out


class Pol:
    def __init__(self, d):
        self.d = d
        self.off = struct.unpack_from('<3I', d, 0)
        top = {t: (o, n, sz) for o, t, n, sz in chunks(d, self.off[0])}
        self.meshes = [self._mesh(o, t) for o, t, n, sz in chunks(d, top[1][0])] if 1 in top else []
        self.materials = [self._material(o) for o, t, n, sz in chunks(d, top[2][0])] if 2 in top else []
        self.textures = []  # func_003F1D10: chunk + 0xC = {u32 id, u32 w, u32 h, ...}
        if 4 in top:
            for o, t, n, sz in chunks(d, top[4][0]):
                self.textures.append(struct.unpack_from('<3I', d, o + 12))
        self.flags = list(struct.unpack_from('<%dI' % len(self.meshes), d, self.off[2]))
        self.roots, self.nodes = [], []
        for o, t, n, sz in chunks(d, self.off[1]):
            if t == 0:
                self.roots = list(struct.unpack_from('<%dI' % n, d, o + 12))
            elif t != 0:
                self.nodes.append(self._node(o + 12))

    # func_003F2EB0 / func_003F2BF0 (+ the sub-chunk accessors func_003F1FF0..func_003F2590)
    def _mesh(self, o, t):
        d = self.d
        sub = {st: (so, sn, ssz) for so, st, sn, ssz in chunks(d, o)}
        m = dict(type=t, attr=t & 0xFFC3FF00, strips=[], matlist=[], pos=[], nrm=[], uv=[], col=[])
        if 0x100 in sub:
            so, sn, _ = sub[0x100]
            q = so + 12
            for _ in range(sn):
                w = _u32(d, q)
                n = w & 0x7FFFFFFF
                m['strips'].append(dict(flag=w >> 31, idx=list(struct.unpack_from('<%dI' % n, d, q + 4))))
                q += 4 + 4 * n
        if 0x200 in sub:
            so, sn, _ = sub[0x200]
            m['matlist'] = list(struct.unpack_from('<%dI' % sn, d, so + 12))
        if 0x400 in sub:
            so, sn, _ = sub[0x400]
            loc = list(struct.unpack_from('<%dI' % sn, d, so + 12))
        else:
            loc = [0] * len(m['strips'])
        # func_003F3700: only a mesh whose strips use different values gets per-strip
        # materials (flag 0x400000); otherwise every strip uses local slot 0.
        m['multi'] = len(set(loc)) > 1
        for s, l in zip(m['strips'], loc):
            s['mat'] = l if m['multi'] else 0
        for key, name, n in ((0x800, 'pos', 3), (0x1000, 'nrm', 3), (0x4000, 'uv', 2), (0x8000, 'col', 4)):
            if key in sub:
                so, sn, _ = sub[key]
                m[name] = [struct.unpack_from('<%df' % n, d, so + 12 + 4 * n * i) for i in range(sn)]
        m['kind'] = 0x35 if m['attr'] == 0xDF00 else 0x25 if m['attr'] == 0x9F00 else m['attr']
        return m

    # func_003F1C10 (record + 0xC): f0..fC -> mat+0x24, f10..1C -> mat+0x04 (diffuse,
    # used by the material-colour programs), f20..2C -> mat+0x14, f30 -> int power,
    # w34 = textured, w100 = texture-table index.
    def _material(self, o):
        b = o + 12
        f = struct.unpack_from('<13f', self.d, b)
        return dict(c0=f[0:4], diffuse=f[4:8], c2=f[8:12], power=f[12],
                    textured=_u32(self.d, b + 0x34), tex=_u32(self.d, b + 0x100))

    # func_003F1730 / func_003DEAF0: {u16 id, ..., s32 child, s32 sibling,
    #   f32 scale[4], f32 rot[4] (radians, X then Y then Z), f32 trans[4], u16 mesh(0xFFFF none)}
    def _node(self, b):
        d = self.d
        child, sib = struct.unpack_from('<ii', d, b + 8)
        sc = struct.unpack_from('<3f', d, b + 0x10)
        rot = struct.unpack_from('<3f', d, b + 0x20)
        tr = struct.unpack_from('<3f', d, b + 0x30)
        mesh = struct.unpack_from('<H', d, b + 0x40)[0]
        return dict(id=struct.unpack_from('<H', d, b)[0], child=child, sibling=sib,
                    scale=sc, rot=rot, trans=tr, mesh=-1 if mesh == 0xFFFF else mesh)

    def texture_index(self, mat):
        m = self.materials[mat]
        if not m['textured'] or m['tex'] >= len(self.textures):
            return None
        return self.textures[m['tex']][0]


# ---- 4x4 row-vector maths (v' = v * M), as the VU0 helpers -------------------
def mident():
    return [1.0, 0, 0, 0, 0, 1.0, 0, 0, 0, 0, 1.0, 0, 0, 0, 0, 1.0]


def mmul(a, b):  # func_003DE160 / func_003F3C40: out = a * b
    return [sum(a[r * 4 + k] * b[k * 4 + c] for k in range(4)) for r in range(4) for c in range(4)]


def node_local(n):
    """func_003DEAF0: scale, then rotations X, Y, Z (func_003F3BE0), then translate."""
    m = mident()
    m[0], m[5], m[10] = n['scale']
    for axis, a in enumerate(n['rot']):
        if a:
            c, s = math.cos(a), math.sin(a)
            r = mident()
            i, j = [(1, 2), (0, 2), (0, 1)][axis]
            r[i * 4 + i] = c; r[j * 4 + j] = c
            if axis == 1:
                r[i * 4 + j] = -s; r[j * 4 + i] = s
            else:
                r[i * 4 + j] = s; r[j * 4 + i] = -s
            m = mmul(m, r)
    m[12], m[13], m[14] = n['trans']
    return m


def walk_tree(pol, root, objm):
    """func_001538B0: the game's node walk. The first node uses the object matrix
    as is; a child gets local * (previous matrix); when a node has no child the
    walk moves to its sibling with local * object matrix (it never climbs back).
    Yields (mesh index, matrix)."""
    n = root
    first = True
    parent = objm
    buf = None
    while True:
        node = pol.nodes[n]
        buf = list(parent) if first else mmul(node_local(node), parent)
        first = False
        if node['mesh'] >= 0:
            yield node['mesh'], buf
        if node['child'] >= 0:
            n, parent = node['child'], buf
        else:
            if node['sibling'] < 0:
                return
            n, parent = node['sibling'], objm


# ---- camera (func_00122DA0 defaults, func_00413F50, func_003DD360, func_003DD5D0) ----
def battle_camera(far=120000.0, target_dy=1):
    """Battle camera at its initial state: eye (0, 95, 320/tan(21.5 deg)), target
    (0, 95 - 240 * n * -0.41, 0), up (0, 1, 0), horizontal FOV 43 degrees,
    near 1, far 120000. Returns (view, proj) row-vector matrices."""
    hf = 43.0
    eye = (0.0, 95.0, 320.0 / math.tan(math.radians(hf / 2)))
    at = (0.0, 95.0 - 240.0 * target_dy * -0.41, 0.0)
    return look_at(eye, at, (0.0, 1.0, 0.0)), perspective(far, 1.0, hf)


def look_at(e, at, up):  # func_003DDF20
    def norm(v):
        l = math.sqrt(sum(x * x for x in v)) or 1.0
        return [x / l for x in v]

    def cross(a, b):  # func_003DE5C0
        return [a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]]
    C = norm([-(at[i] - e[i]) for i in range(3)])
    B = norm(up)
    X = norm(cross(B, C))
    Y = cross(C, X)
    dot = lambda a, b: sum(a[i] * b[i] for i in range(3))
    return [X[0], Y[0], C[0], 0, X[1], Y[1], C[1], 0, X[2], Y[2], C[2], 0,
            -dot(e, X), -dot(e, Y), -dot(e, C), 1.0]


def perspective(far, near, hfov_deg):
    """func_00413F50 -> func_003DD2E0 -> func_003DD360 (aspect 1.0; the viewport
    matrix then divides x by 4/3)."""
    t = 2.0 * math.atan(240.0 / (320.0 / math.tan(math.radians(hfov_deg / 2))))
    cot = 1.0 / math.tan(t / 2)
    m = mident()
    m[0] = cot; m[5] = cot
    m[10] = -(far + near) / (far - near); m[11] = -1.0
    m[14] = -(2.0 * far * near) / (far - near); m[15] = 0.0
    return m


def viewport_to_480(ndc):
    """func_003DD5D0 with the battle viewport {0, -16, 640, 480, 0.0, 1.0}, in the
    port's 640x480 space: x = 320 + ndc.x * 320 / 1.333333 ... -> 240, y = 224 - ndc.y * 240.
    Depth: GS z = Zs * (0.5 - 0.5 * ndc.z), larger = nearer."""
    x, y, z = ndc
    return (320.0 + x * 320.0 / 1.333333, 224.0 - y * 240.0, z)


# ---- textures ---------------------------------------------------------------
def load_texpack(raw):
    d, _ = textures.decode_pack(raw)
    out = []
    for w, h, fl, off, attr in textures.records(d):
        if fl >> 16 == 1 and d[off:off + 4] == b'TIM2':
            out.append(tim2.parse(d, off)[0])
        else:
            out.append(None)
    return out


# ---- OBJ export -----------------------------------------------------------------
def write_obj(pol, texs, outdir, stem, roots):
    os.makedirs(outdir, exist_ok=True)
    used = set()
    lines = ['# MvC2 %s: converted from the user\'s disc by port/tools/convert/mesh.py' % stem,
             'mtllib %s.mtl' % stem]
    vbase = tbase = 1
    for ri in roots:
        for mi, m4 in walk_tree(pol, pol.roots[ri], mident()):
            m = pol.meshes[mi]
            lines.append('o root%02d_mesh%03d_flags%x' % (ri, mi, pol.flags[mi]))
            for k, p in enumerate(m['pos']):
                x, y, z = [p[0] * m4[c] + p[1] * m4[4 + c] + p[2] * m4[8 + c] + m4[12 + c] for c in range(3)]
                if m['col']:
                    c = m['col'][k]
                    lines.append('v %.5f %.5f %.5f %.4f %.4f %.4f' % (x, y, z, min(c[0], 255) / 255,
                                                                     min(c[1], 255) / 255, min(c[2], 255) / 255))
                else:
                    lines.append('v %.5f %.5f %.5f' % (x, y, z))
            for uv in m['uv']:
                lines.append('vt %.6f %.6f' % (uv[0], 1.0 - uv[1]))
            cur = None
            for s in m['strips']:
                mat = m['matlist'][s['mat']] if m['matlist'] else 0
                if mat != cur:
                    lines.append('usemtl mat%03d' % mat)
                    used.add(mat)
                    cur = mat
                idx = s['idx']
                for j in range(len(idx) - 2):
                    a, b, c = idx[j], idx[j + 1], idx[j + 2]
                    if a == b or b == c or a == c:
                        continue
                    if j & 1:
                        a, b = b, a
                    if m['uv']:
                        lines.append('f %d/%d %d/%d %d/%d' % (a + vbase, a + tbase, b + vbase, b + tbase,
                                                             c + vbase, c + tbase))
                    else:
                        lines.append('f %d %d %d' % (a + vbase, b + vbase, c + vbase))
            vbase += len(m['pos'])
            tbase += len(m['uv'])
    open(os.path.join(outdir, stem + '.obj'), 'w').write('\n'.join(lines) + '\n')
    mtl = []
    for mat in sorted(used):
        mm = pol.materials[mat]
        mtl.append('newmtl mat%03d' % mat)
        mtl.append('Kd %.4f %.4f %.4f' % tuple(mm['diffuse'][:3]))
        mtl.append('d %.4f' % mm['diffuse'][3])
        ti = pol.texture_index(mat)
        if ti is not None and ti < len(texs) and texs[ti] is not None:
            mtl.append('map_Kd tex%03d.png' % ti)
    open(os.path.join(outdir, stem + '.mtl'), 'w').write('\n'.join(mtl) + '\n')
    for i, p in enumerate(texs):
        if p is not None:
            png.write_rgba(os.path.join(outdir, 'tex%03d.png' % i), p['w'], p['h'], p['rgba'])


# ---- reference software renderer --------------------------------------------------
BLEND_SRC = [0, 1, 0, 0, 2, 0x30, 0x40, 0x50]   # D_00444880
BLEND_DST = [0, 0x10, 0, 0, 2, 0x30, 0x40, 0x50]  # D_004448A0


def mesh_blend(flags):
    """func_001537D0 -> func_00153A40: state 0x5D from the mesh flags."""
    if flags & 0x100:
        return BLEND_SRC[(flags >> 16) & 7] | BLEND_DST[(flags >> 19) & 7]
    return BLEND_SRC[1] | BLEND_DST[0]


def stage_format(pol, mi, b34=4, b30=1):
    """func_00415A00 + func_00415590 at a stage load (states 1 = 2 = 0 first):
    the format word D_004C2AD4 a mesh is built with, its vertex key, and the
    VU1 descriptor table index func_003E0F60 picks (None = not drawable)."""
    fl = pol.flags[mi]
    a = 1 if fl & 1 else 2
    b = 1 if fl & 2 else 0
    fmt = 0x20000 | (0 if a == 1 else 2) | (0x4000 if b else 0)
    if b34 & 4 and fl & 4 and b:
        fmt |= 0x8000
    if b30 and a == 1 and b == 1:
        fmt |= 0x8000 | 0x40
    m = pol.meshes[mi]
    key = 0x21000 | (0x400000 if m['multi'] else 0) | (0x35 if m['attr'] == 0xDF00 else 0x25)
    return fmt, key, DESC.get((fmt, key & 0xFF))


# func_003E0F60 for the unlit, top-byte-0 formats a POL build can produce
DESC = {(0x0, 0x35): 11, (0x0, 0x25): 12, (0x2, 0x35): 13, (0x2, 0x25): 14,
        (0x20000, 0x35): 15, (0x20000, 0x25): 16, (0x20002, 0x35): 17, (0x20002, 0x25): 18,
        (0x8000, 0x35): 23, (0x8002, 0x35): 24, (0x28000, 0x35): 26, (0x28002, 0x35): 27,
        (0x4002, 0x35): 32, (0x24002, 0x35): 33, (0x4000, 0x35): 34, (0x24000, 0x35): 35,
        (0xC002, 0x35): 40, (0x2C002, 0x35): 41, (0xC000, 0x35): 42, (0x2C000, 0x35): 43,
        (0x28040, 0x35): 44, (0x2C040, 0x35): 45}


def render(pol, texs, roots, W=640, H=480, modulate=(1.0, 1.0, 1.0, 1.0)):
    """Independent pure-Python rasteriser of the stage with the battle camera.
    Colour: vertex (0.5 * byte, truncated by ftoi0 after the 0x66 modulate) or
    material diffuse * 128 (clamped), then GS MODULATE tex * c / 128. Blend from
    the mesh flags, Z test GEQUAL with larger = nearer, alpha test a != 0.
    No fog (the stage fog state is not reproduced), nearest sampling, repeat wrap."""
    view, proj = battle_camera()
    vp = mmul(view, proj)
    sx, sy = W / 640.0, H / 480.0
    color = bytearray(W * H * 4)
    for i in range(W * H):
        color[4 * i + 3] = 255
    depth = [-1e30] * (W * H)
    draws = []
    for ri in roots:
        for mi, m4 in walk_tree(pol, pol.roots[ri], mident()):
            draws.append((mi, m4))
    tris = 0
    for mi, m4 in draws:
        m = pol.meshes[mi]
        fl = pol.flags[mi]
        if stage_format(pol, mi)[2] is None:
            continue  # no VU1 program for this format: the game cannot draw it either
        vcol = bool(fl & 1)
        blend = mesh_blend(fl)
        mod = list(modulate)
        if fl & 0x200:
            mod[3] = math.floor(mod[3] * 255 / 2) / 255  # func_001538B0 halves 0x66 alpha
        mvp = mmul(m4, vp)
        clip = []
        for p in m['pos']:
            clip.append([p[0] * mvp[k] + p[1] * mvp[4 + k] + p[2] * mvp[8 + k] + mvp[12 + k] for k in range(4)])
        for s in m['strips']:
            mat = m['matlist'][s['mat']] if m['matlist'] else 0
            ti = pol.texture_index(mat)
            tex = texs[ti] if ti is not None and ti < len(texs) else None
            if vcol:
                matc = None
            else:
                dfs = pol.materials[mat]['diffuse']
                matc = [min(128.0, dfs[k] * 128.0) for k in range(3)] + [dfs[3] * 128.0]
                matc = [int(matc[k] * mod[k]) for k in range(4)]
            idx = s['idx']
            for j in range(len(idx) - 2):
                tri = (idx[j], idx[j + 1], idx[j + 2])
                vs = []
                for t in tri:
                    if matc is not None:
                        col = matc
                    else:
                        c = m['col'][t]
                        bb = [int(c[k]) & 0xFF for k in range(4)]
                        col = [int(0.5 * bb[k] * mod[k]) for k in range(4)]
                    uv = m['uv'][t] if m['uv'] else (0.0, 0.0)
                    vs.append((clip[t], col, uv))
                poly = _clip_near(vs)
                for k in range(1, len(poly) - 1):
                    tv = [poly[0], poly[k], poly[k + 1]]
                    sv = []
                    for c, _, _ in tv:
                        w = c[3]
                        x, y, z = viewport_to_480((c[0] / w, c[1] / w, c[2] / w))
                        sv.append((x * sx, y * sy, -z, 1.0 / w))
                    _raster(color, depth, W, H, sv, [t[1] for t in tv], [t[2] for t in tv], tex, blend)
                tris += 1
    return color, tris


def _clip_near(vs):
    """Sutherland-Hodgman against the near plane z >= -w (GL clip space);
    the game's clipping programs (desc 19/44-46) clip, the others drop the
    triangle through ADC (see ASSET_FORMATS.md 6.6)."""
    def inside(v):
        return v[0][2] + v[0][3] >= 1e-5

    def lerp(a, b):
        da, db = a[0][2] + a[0][3], b[0][2] + b[0][3]
        t = da / (da - db)
        mix = lambda x, y: [x[i] + (y[i] - x[i]) * t for i in range(len(x))]
        return (mix(a[0], b[0]), mix(a[1], b[1]), mix(a[2], b[2]))
    out = []
    for i in range(len(vs)):
        a, b = vs[i], vs[(i + 1) % len(vs)]
        if inside(a):
            out.append(a)
            if not inside(b):
                out.append(lerp(a, b))
        elif inside(b):
            out.append(lerp(a, b))
    return out


def _raster(color, depth, W, H, v, cols, uvs, tex, blend):
    (x0, y0, z0, q0), (x1, y1, z1, q1), (x2, y2, z2, q2) = v
    area = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0)
    if abs(area) < 1e-9:
        return
    minx = max(0, int(math.floor(min(x0, x1, x2))))
    maxx = min(W - 1, int(math.ceil(max(x0, x1, x2))))
    miny = max(0, int(math.floor(min(y0, y1, y2))))
    maxy = min(H - 1, int(math.ceil(max(y0, y1, y2))))
    if minx > maxx or miny > maxy:
        return
    inv = 1.0 / area
    if tex is not None:
        tw, th, trgba = tex['w'], tex['h'], tex['rgba']
    src, dst = blend & 0xF, blend >> 4
    for py in range(miny, maxy + 1):
        cy = py + 0.5
        for px in range(minx, maxx + 1):
            cx = px + 0.5
            w0 = ((x1 - cx) * (y2 - cy) - (x2 - cx) * (y1 - cy)) * inv
            w1 = ((x2 - cx) * (y0 - cy) - (x0 - cx) * (y2 - cy)) * inv
            w2 = 1.0 - w0 - w1
            if w0 < 0 or w1 < 0 or w2 < 0:
                continue
            z = w0 * z0 + w1 * z1 + w2 * z2
            k = py * W + px
            if z < depth[k]:
                continue
            q = w0 * q0 + w1 * q1 + w2 * q2
            c = [w0 * cols[0][i] + w1 * cols[1][i] + w2 * cols[2][i] for i in range(4)]
            if tex is not None:
                u = (w0 * uvs[0][0] * q0 + w1 * uvs[1][0] * q1 + w2 * uvs[2][0] * q2) / q
                vv = (w0 * uvs[0][1] * q0 + w1 * uvs[1][1] * q1 + w2 * uvs[2][1] * q2) / q
                tx = int(math.floor(u * tw)) % tw
                ty = int(math.floor(vv * th)) % th
                o = 4 * (ty * tw + tx)
                ta = (trgba[o + 3] + 1) // 2  # back to GS 0..128
                r = trgba[o] * c[0] / 128.0
                g = trgba[o + 1] * c[1] / 128.0
                b = trgba[o + 2] * c[2] / 128.0
                a = ta * c[3] / 128.0
            else:
                r, g, b, a = c[0] * 2, c[1] * 2, c[2] * 2, c[3]
            if a <= 0:
                continue  # GS TEST: alpha != 0
            r, g, b = min(r, 255.0), min(g, 255.0), min(b, 255.0)
            af = min(a / 128.0, 1.0 * 255 / 128)
            o = 4 * k
            dr, dg, db = color[o], color[o + 1], color[o + 2]
            fs = {0: 0.0, 1: 1.0, 2: af, 3: 1.0 - af}.get(src, 1.0)
            fd = {0: 0.0, 1: 1.0, 2: af, 3: 1.0 - af}.get(dst, 0.0)
            color[o] = int(max(0, min(255, r * fs + dr * fd)))
            color[o + 1] = int(max(0, min(255, g * fs + dg * fd)))
            color[o + 2] = int(max(0, min(255, b * fs + db * fd)))
            depth[k] = z


def info(pol):
    print('meshes %d materials %d textures %d nodes %d roots %d' % (
        len(pol.meshes), len(pol.materials), len(pol.textures), len(pol.nodes), len(pol.roots)))
    from collections import Counter
    print('mesh types', Counter(hex(m['type']) for m in pol.meshes))
    print('mesh flags', Counter(hex(f) for f in pol.flags))
    print('descriptors (stage load)', Counter(stage_format(pol, i)[2] for i in range(len(pol.meshes))))
    nv = sum(len(m['pos']) for m in pol.meshes)
    nt = sum(max(0, len(s['idx']) - 2) for m in pol.meshes for s in m['strips'])
    print('vertices %d strip triangles %d' % (nv, nt))
    cmax = max((max(c) for m in pol.meshes for c in m['col']), default=0)
    print('max colour component %.1f' % cmax)
    for ri, r in enumerate(pol.roots):
        ms = [mi for mi, _ in walk_tree(pol, r, mident())]
        lo = [1e9] * 3; hi = [-1e9] * 3
        for mi in ms:
            for p in pol.meshes[mi]['pos']:
                for k in range(3):
                    lo[k] = min(lo[k], p[k]); hi[k] = max(hi[k], p[k])
        print('root %2d node %3d meshes %3d bbox (%s)-(%s)' % (
            ri, r, len(ms), ','.join('%.0f' % x for x in lo), ','.join('%.0f' % x for x in hi)))


def main():
    a = sys.argv[1:]
    iso, outdir, stage = a[0], a[1], int(a[2], 0)
    roots = 'all'
    W, H = 640, 480
    if '--roots' in a:
        roots = a[a.index('--roots') + 1]
    if '--size' in a:
        W, H = map(int, a[a.index('--size') + 1].split('x'))
    af = Afs(Iso(iso), 2)
    pid, tid = 801 + 2 * stage, 802 + 2 * stage  # D_00446860 / D_00446810
    pol = Pol(af.read(pid))
    stem = os.path.splitext(af.name(pid))[0].lower()
    if '--info' in a:
        info(pol)
        return
    texs = load_texpack(af.read(tid))
    rl = list(range(len(pol.roots))) if roots == 'all' else [int(x) for x in roots.split(',')]
    write_obj(pol, texs, os.path.join(outdir, stem), stem, rl)
    print('wrote', os.path.join(outdir, stem, stem + '.obj'))
    if '--render' in a:
        img, n = render(pol, texs, rl, W, H)
        out = os.path.join(outdir, stem, stem + '_ref.png')
        png.write_rgba(out, W, H, img)
        print('wrote', out, n, 'triangles')


if __name__ == '__main__':
    main()
