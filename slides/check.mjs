// 簡報檢查（tutorial 3.4）：不信任 build.mjs，直接解析產生出來的 slides/index.html，
// 把每個程式碼／輸出區塊「去掉 HTML 標籤、還原跳脫字元」後，和 examples/ 的檔案比對。
// 另外檢查：每張都有來源標籤、標籤裡的 wiki 路徑存在、程式碼 ≤ 15 行、沒有未取代的佔位符。
// 用法（在 cpp-basics-wiki/ 底下）：node slides/check.mjs
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const read = f => fs.readFileSync(path.join(root, f), 'utf8').replace(/\r/g, '').replace(/\n$/, '');
const html = fs.readFileSync(path.join(root, 'slides/index.html'), 'utf8');
const unescape = s => s.replace(/<[^>]*>/g, '')
  .replace(/&lt;/g, '<').replace(/&gt;/g, '>').replace(/&quot;/g, '"').replace(/&#39;/g, "'").replace(/&amp;/g, '&');

let ok = 0; const bad = [];
const check = (cond, msg) => { if (cond) ok++; else bad.push(msg); };

// 1. 程式碼與輸出區塊
const manual = [];
for (const m of html.matchAll(/<pre class="([^"]*)"([^>]*)>([\s\S]*?)<\/pre>/g)) {
  const attrs = Object.fromEntries([...m[2].matchAll(/data-(\w+)="([^"]*)"/g)].map(a => [a[1], a[2]]));
  const text = unescape(m[3]);
  if (attrs.file && attrs.line) {
    const want = read(attrs.file).split('\n')[Number(attrs.line) - 1].trimStart();
    check(text === want, `${attrs.file} 第 ${attrs.line} 行的節錄不一致`);
  } else if (attrs.file) {
    const want = read(attrs.file).split('\n').slice(1).join('\n');
    check(text === want, `${attrs.file} 的程式碼和檔案不一致`);
    const lines = text.split('\n').filter(l => !l.startsWith('// 示範：')).length;
    check(lines <= 15, `${attrs.file} 在投影片上有 ${lines} 行，超過 15 行`);
  } else if (attrs.out) {
    check(text === read(attrs.out), `${attrs.out} 的輸出和檔案不一致`);
  } else if (attrs.in) {
    check(text === read(attrs.in), `${attrs.in} 的輸入和檔案不一致`);
  } else if (attrs.outhead) {
    check(text.length > 0 && read(attrs.outhead).startsWith(text), `${attrs.outhead} 的節錄輸出不是檔案的開頭`);
  } else {
    manual.push(text.split('\n')[0]);
  }
}

// 2. 每張投影片都有來源標籤，而且標籤裡的 wiki 路徑存在
const slides = [...html.matchAll(/<section class="slide">([\s\S]*?)<\/section>/g)].map(s => s[1]);
slides.forEach((s, k) => {
  const label = s.match(/<span class="srclabel">([^<]*)<\/span>/);
  check(label, `第 ${k + 1} 張沒有來源標籤`);
  if (!label) return;
  for (const p of label[1].matchAll(/wiki\/[\w\-\/]+\.md/g)) {
    check(fs.existsSync(path.join(root, p[0])), `第 ${k + 1} 張的來源 ${p[0]} 不存在`);
  }
});

// 3. 沒有殘留的佔位符；計數和實際張數一致
check(!/<!--(CODE|OUT|IN|LINE|OUTHEAD) /.test(html), '還有沒取代的佔位符');
const declared = html.match(/<span id="count">1 \/ (\d+)<\/span>/);
check(declared && Number(declared[1]) === slides.length, `頁碼寫 ${declared && declared[1]} 張，實際有 ${slides.length} 張`);

console.log(`投影片 ${slides.length} 張；檢查項目通過 ${ok}，失敗 ${bad.length}`);
if (manual.length) console.log(`⚠️ 沒有對應檔案、需要人工確認的區塊 ${manual.length} 個：` + manual.map(t => `「${t}…」`).join('、'));
bad.forEach(b => console.log('❌ ' + b));
process.exit(bad.length ? 1 : 0);
