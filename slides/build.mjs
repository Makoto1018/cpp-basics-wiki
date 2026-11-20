// 從 slides/src/index.template.html 產生 slides/index.html。
// 模板裡的佔位符會換成 examples/ 裡的真實內容（做好 HTML 跳脫和語法上色）：
//   <!--CODE examples/X.cpp-->        完整程式（第 1 行的「// 出處：…」改放在圖說）
//   <!--OUT examples/X.out-->         實際輸出
//   <!--IN examples/X.in-->           輸入
//   <!--LINE examples/X.cpp N-->      節錄第 N 行（去掉行首縮排）
//   <!--OUTHEAD examples/X.out N-->   輸出的前 N 個字元（無窮迴圈用）
// 用法（在 cpp-basics-wiki/ 底下）：node slides/build.mjs
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const read = f => fs.readFileSync(path.join(root, f), 'utf8').replace(/\r/g, '').replace(/\n$/, '');
const esc = s => s.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;').replace(/"/g, '&quot;');

const KEYWORDS = new Set(['int', 'double', 'bool', 'char', 'return', 'if', 'else', 'while', 'for',
                          'break', 'continue', 'true', 'false']);
const TOKEN = /(\/\/.*$)|("(?:\\.|[^"\\])*")|('(?:\\.|[^'\\])*')|(\bstd::\w+)|([A-Za-z_]\w*)|(\d+(?:\.\d+)?)/g;

function highlightLine(line) {
  if (line.startsWith('#include')) {
    return `<span class="p">#include</span><span class="s">${esc(line.slice('#include'.length))}</span>`;
  }
  let out = '', last = 0, m;
  TOKEN.lastIndex = 0;
  while ((m = TOKEN.exec(line)) !== null) {
    out += esc(line.slice(last, m.index));
    const [tok, comment, str, chr, stdName, ident, num] = m;
    if (comment) out += `<span class="c">${esc(tok)}</span>`;
    else if (str || chr) out += `<span class="s">${esc(tok)}</span>`;
    else if (stdName) out += `<span class="t">${esc(tok)}</span>`;
    else if (ident) out += KEYWORDS.has(tok) ? `<span class="k">${esc(tok)}</span>` : esc(tok);
    else if (num) out += `<span class="n">${esc(tok)}</span>`;
    last = m.index + tok.length;
  }
  return out + esc(line.slice(last));
}
const highlight = text => text.split('\n').map(highlightLine).join('\n');

const errors = [];
const expanders = {
  CODE(file) {
    const lines = read(file).split('\n');
    if (!lines[0].startsWith('// 出處：')) errors.push(`${file} 第 1 行不是出處註解`);
    const body = lines.slice(1);
    const counted = body.filter(l => !l.startsWith('// 示範：')).length;
    if (counted > 15) errors.push(`${file} 有 ${counted} 行，超過 15 行`);
    return `<figure class="code"><div class="fname">${esc(file)}</div>` +
           `<pre class="src" data-file="${esc(file)}">${highlight(body.join('\n'))}</pre>` +
           `<figcaption>${esc(lines[0].replace(/^\/\/ /, ''))}</figcaption></figure>`;
  },
  OUT: file => `<pre class="io" data-out="${esc(file)}">${esc(read(file))}</pre>`,
  IN: file => `<pre class="io" data-in="${esc(file)}">${esc(read(file))}</pre>`,
  LINE(file, n) {
    const line = read(file).split('\n')[n - 1];
    if (line === undefined) { errors.push(`${file} 沒有第 ${n} 行`); return ''; }
    return `<pre class="src solo" data-file="${esc(file)}" data-line="${n}">${highlightLine(line.trimStart())}</pre>` +
           `<div class="iolabel">${esc(file)} 第 ${n} 行</div>`;
  },
  OUTHEAD: (file, n) => `<pre class="io" data-outhead="${esc(file)}">${esc(read(file).slice(0, n))}</pre>`,
};

const template = fs.readFileSync(path.join(root, 'slides/src/index.template.html'), 'utf8');
const html = template.replace(/<!--(CODE|OUT|IN|LINE|OUTHEAD) (\S+?)(?: (\d+))?-->/g,
  (_, kind, file, n) => expanders[kind](file, n === undefined ? undefined : Number(n)));

if (errors.length) { console.error('❌ 產生失敗：\n  ' + errors.join('\n  ')); process.exit(1); }
fs.writeFileSync(path.join(root, 'slides/index.html'), html);
const count = (html.match(/<section class="slide">/g) || []).length;
console.log(`📝 slides/index.html：${count} 張投影片`);
