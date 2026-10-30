// Run the app's --script in the browser (Playwright; see BOOT_NOTES "Fidelity pass"): node port/tools/web_script.js URL OUTDIR SCRIPT [PROFILE_DIR] [ARGS]
// Shots the script writes (/shots/NAME.png in MEMFS) are copied to OUTDIR; every console line goes to OUTDIR/console.log.
// PROFILE_DIR (or '-') keeps IndexedDB between runs (memory-card persistence tests).
const { chromium } = require('/opt/node22/lib/node_modules/playwright');
const fs = require('fs');
const [url, outDir, scriptFile, profile, extra] = process.argv.slice(2);
const maxSec = +(process.env.MAXSEC || 580);
(async () => {
  fs.mkdirSync(outDir, { recursive: true });
  const LOG = outDir + '/console.log'; fs.writeFileSync(LOG, '');
  const script = fs.readFileSync(scriptFile, 'utf8').split('\n').map(l => l.replace(/#.*/, '').trim()).filter(Boolean).join(';');
  const args = ['--use-gl=angle', '--use-angle=swiftshader', '--enable-unsafe-swiftshader', '--autoplay-policy=no-user-gesture-required'];
  let ctx, browser;
  if (profile && profile !== '-') ctx = await chromium.launchPersistentContext(profile, { headless: true, args, viewport: { width: 960, height: 720 } });
  else { browser = await chromium.launch({ headless: true, args }); ctx = await browser.newContext({ viewport: { width: 960, height: 720 } }); }
  const page = await ctx.newPage();
  let done = false, crashed = false, state = '';
  const pending = [];
  page.on('console', m => {
    const t = m.text(); fs.appendFileSync(LOG, t + '\n');
    const s = /frame (\d+): game state g\[0\.\.2\] = (\d+) (\d+) (\d+)/.exec(t);
    if (s) state = s[2] + '/' + s[3] + '/' + s[4];
    const w = /wrote (\/shots\/[^ ]+\.png)/.exec(t);
    if (w) pending.push(w[1]);
    if (/script:|memory card|CPU pick|error|abort|Abort|RuntimeError/i.test(t)) console.log('[page]', t.slice(0, 200));
    if (/script: done/.test(t)) done = true;
  });
  page.on('crash', () => { crashed = true; console.log('[crash] state', state); });
  page.on('pageerror', e => console.log('[pageerror]', e.message.slice(0, 300)));
  let q = '?script=' + encodeURIComponent(script);
  if (extra) q += '&args=' + encodeURIComponent(extra);
  await page.goto(url + q);
  const t0 = Date.now();
  while ((!done || pending.length) && !crashed && Date.now() - t0 < maxSec * 1000) {
    while (pending.length) {
      const p = pending.shift();
      try {
        const b64 = await page.evaluate(p => { const d = Module.FS.readFile(p); let s = ''; for (let i = 0; i < d.length; i += 0x8000) s += String.fromCharCode.apply(null, d.subarray(i, i + 0x8000)); Module.FS.unlink(p); return btoa(s); }, p);
        fs.writeFileSync(outDir + '/' + p.replace('/shots/', ''), Buffer.from(b64, 'base64'));
        console.log('shot', p, 'state', state, ((Date.now() - t0) / 1000).toFixed(0) + 's');
      } catch (e) { console.log('shot read failed', p, e.message.slice(0, 100)); }
    }
    await page.waitForTimeout(500);
  }
  await page.waitForTimeout(1500); // let a pending memory-card write reach IndexedDB
  console.log(done ? 'done' : crashed ? 'CRASHED' : 'TIMEOUT', 'state', state, ((Date.now() - t0) / 1000).toFixed(0) + 's');
  await ctx.close(); if (browser) await browser.close();
})().catch(e => { console.error(e); process.exit(1); });
