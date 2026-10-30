/* App-shell cache so the installed PWA starts offline.  The disc image is NOT
 * cached here (it lives in IndexedDB, see shell.html).  Network first, so a
 * new build is picked up as soon as it is reachable (mvc2.js and mvc2.wasm
 * must come from the same build); the cache answers when offline.  The
 * shell is precached at install so the first offline start works even for
 * files the first visit did not request (icons). */
const CACHE = 'mvc2-port-v2';
const SHELL = ['./', 'mvc2.html', 'mvc2.js', 'mvc2.wasm', 'manifest.webmanifest',
               'icon-32.png', 'icon-180.png', 'icon-192.png', 'icon-512.png', 'icon-maskable-512.png'];
self.addEventListener('install', e => {
  e.waitUntil(caches.open(CACHE)
    .then(c => Promise.all(SHELL.map(u => c.add(u).catch(() => {}))))   /* one missing file must not fail the install */
    .then(() => self.skipWaiting()));
});
self.addEventListener('activate', e => {
  e.waitUntil(caches.keys().then(ks => Promise.all(ks.filter(k => k.startsWith('mvc2-port-') && k !== CACHE).map(k => caches.delete(k))))
    .then(() => self.clients.claim()));
});
self.addEventListener('fetch', e => {
  const req = e.request;
  if (req.method !== 'GET' || new URL(req.url).origin !== location.origin) return;
  e.respondWith(fetch(req).then(r => {
    if (r.ok) { const copy = r.clone(); caches.open(CACHE).then(c => c.put(req, copy)); }
    return r;
  }).catch(async () => (await caches.match(req, { ignoreSearch: true }))
      || (req.mode === 'navigate' ? caches.match('mvc2.html') : undefined)
      || Response.error()));
});
