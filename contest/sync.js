/**
 * Collaborative Code Editor - VS Code Live Sync Script
 * 
 * Instructions:
 * 1. Save this file as `sync.js` in your local project folder.
 * 2. Run it in your VS Code terminal:
 *    node sync.js <file-to-watch>
 * 
 * Example:
 *    node sync.js my_code.py
 */

const fs = require('fs');
const http = require('http');
const https = require('https');
const path = require('path');

// Pre-filled room configuration
const ROOM_ID = 'rwels5';
const USERNAME = 'ellssol';
const USER_ID = 'user-bq3we2p';
const DEFAULT_APP_URL = 'https://ais-dev-vrtzm5opp556n4pwwpnmlj-149834029721.asia-east1.run.app';
const SHARED_APP_URL = 'https://ais-pre-vrtzm5opp556n4pwwpnmlj-149834029721.asia-east1.run.app';

// Argument parsing
let filePath = null;
let appUrl = DEFAULT_APP_URL;
let cookie = null;

for (let i = 2; i < process.argv.length; i++) {
  const arg = process.argv[i];
  if (arg === '--url' || arg === '-u') {
    appUrl = process.argv[++i];
  } else if (arg === '--cookie' || arg === '-c') {
    cookie = process.argv[++i];
  } else if (!arg.startsWith('-')) {
    filePath = arg;
  }
}

if (!filePath) {
  console.error('\x1b[31mError: Please specify a file to watch.\x1b[0m');
  console.log('\nUsage:\n  node sync.js <file_path> [--url <app_url>] [--cookie <cookie_string>]\n');
  process.exit(1);
}

const absolutePath = path.resolve(filePath);
if (!fs.existsSync(absolutePath)) {
  console.error(`\x1b[31mError: File not found: ${filePath}\x1b[0m`);
  process.exit(1);
}

function detectLanguage(ext) {
  const map = {
    '.js': 'javascript',
    '.ts': 'typescript',
    '.jsx': 'javascript',
    '.tsx': 'typescript',
    '.py': 'python',
    '.cpp': 'cpp',
    '.cc': 'cpp',
    '.h': 'cpp',
    '.java': 'java',
    '.html': 'html',
    '.css': 'css',
    '.json': 'json',
    '.md': 'markdown',
    '.rs': 'rust',
    '.go': 'go',
    '.sh': 'shell',
    '.yaml': 'yaml',
    '.yml': 'yaml',
    '.sql': 'sql',
    '.cs': 'csharp',
    '.php': 'php',
    '.rb': 'ruby'
  };
  return map[ext.toLowerCase()] || 'javascript';
}

const fileExt = path.extname(absolutePath);
const language = detectLanguage(fileExt);

console.log(`\x1b[36m🚀 VS Code Live Sync Started!\x1b[0m`);
console.log(`Watching: \x1b[33m${path.basename(absolutePath)}\x1b[0m (${language})`);
console.log(`Room ID: \x1b[35m${ROOM_ID}\x1b[0m | User: \x1b[32m${USERNAME}\x1b[0m`);
console.log(`App URL: ${appUrl}`);
if (appUrl.includes('-dev-')) {
  console.log(`\x1b[33m⚠️  Note: You are syncing to a private Development App URL.`);
  console.log(`If sync fails with 302 Found, re-run with: --url ${SHARED_APP_URL}\x1b[0m`);
}
console.log(`\x1b[90mPress Ctrl+C to stop watching and syncing.\x1b[0m\n`);

function syncCode() {
  let content;
  try {
    content = fs.readFileSync(absolutePath, 'utf8');
  } catch (err) {
    console.error(`Error reading file: ${err.message}`);
    return;
  }

  const payload = JSON.stringify({
    roomId: ROOM_ID,
    username: USERNAME,
    userId: USER_ID,
    code: content,
    language: language
  });

  const parsedUrl = new URL(appUrl.endsWith('/') ? appUrl + 'api/sync' : appUrl + '/api/sync');
  const isHttps = parsedUrl.protocol === 'https:';
  const requester = isHttps ? https : http;

  const options = {
    hostname: parsedUrl.hostname,
    port: parsedUrl.port || (isHttps ? 443 : 80),
    path: parsedUrl.pathname,
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
      'Content-Length': Buffer.byteLength(payload)
    }
  };

  if (cookie) {
    options.headers['Cookie'] = cookie;
  }

  const req = requester.request(options, (res) => {
    let responseData = '';
    res.on('data', (chunk) => { responseData += chunk; });
    res.on('end', () => {
      if (res.statusCode === 200) {
        const now = new Date().toLocaleTimeString();
        console.log(`\x1b[32m[${now}] Synced successfully! (${Buffer.byteLength(content)} bytes)\x1b[0m`);
      } else if (res.statusCode === 302 || res.statusCode === 301 || res.statusCode === 307) {
        console.error(`\x1b[31mSync failed: Status ${res.statusCode} (Redirect)\x1b[0m`);
        console.log('\n\x1b[33m⚠️  Why this happens:\x1b[0m');
        console.log('The Development App URL is private and requires browser authentication. The proxy redirects external CLI requests to a login page.');
        console.log('\n\x1b[32m💡 How to resolve this:\x1b[0m');
        console.log('Option 1: Sync using the public Shared App URL (Highly Recommended & Easiest):');
        console.log(`  \x1b[36mnode sync.js ${filePath} --url ${SHARED_APP_URL}\x1b[0m`);
        console.log('\nOption 2: Pass your browser Cookie header to bypass authentication:');
        console.log(`  \x1b[36mnode sync.js ${filePath} --cookie "your_cookie_value"\x1b[0m`);
        console.log('  (Copy the \x1b[35mCookie\x1b[0m header value from browser DevTools Network tab for any app request)\n');
      } else {
        console.error(`\x1b[31mSync failed: Status ${res.statusCode} - ${responseData}\x1b[0m`);
      }
    });
  });

  req.on('error', (err) => {
    console.error(`\x1b[31mNetwork error syncing: ${err.message}\x1b[0m`);
  });

  req.write(payload);
  req.end();
}

syncCode();

let fsWait = false;
fs.watch(absolutePath, (event, filename) => {
  if (filename) {
    if (fsWait) return;
    fsWait = setTimeout(() => {
      fsWait = false;
    }, 150);
    
    if (event === 'change') {
      syncCode();
    }
  }
});
