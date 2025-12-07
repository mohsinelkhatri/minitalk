<h1 align="center">📡 Minitalk – Signal-Based Communication (42 / 1337 School)</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/Signals-SIGUSR1/SIGUSR2-green?style=for-the-badge">
  <img src="https://img.shields.io/badge/Status-Mandatory%20+%20Bonus-purple?style=for-the-badge">
</p>

<p style="font-size:16px;">
<strong>Minitalk</strong> is a communication project using UNIX signals (<code>SIGUSR1</code> and <code>SIGUSR2</code>) to send messages bit-by-bit between a client and a server.  
This README includes both <strong>mandatory</strong> and <strong>bonus</strong> requirements.
</p>

<hr>

<h2 align="center">📌 Project Overview</h2>

<p>
The goal of Minitalk is to implement a small data transfer protocol using only:
</p>

<ul>
  <li><code>SIGUSR1</code> → represents bit <strong>0</strong></li>
  <li><code>SIGUSR2</code> → represents bit <strong>1</strong></li>
</ul>

<p>Your program includes two executables:</p>

<ul>
  <li>🖥️ <strong>server</strong> → receives bits and prints characters</li>
  <li>📨 <strong>client</strong> → sends a string to the server via signals</li>
</ul>

<p>The server prints its PID on startup, and the client uses that PID to send messages.</p>

<hr>

<h2 align="center">📁 Project Structure</h2>

<pre style="background:#1e1e1e; color:#00e676; padding:15px; border-radius:8px;">
minitalk/
│
├── client.c
├── server.c
├── utils.c
├── mini_talk.h
│
├── client_bonus.c
├── server_bonus.c
├── utils_bonus.c
├── mini_talk_bonus.h
│
└── Makefile
</pre>

<hr>

<h2 align="center">🧠 How Communication Works</h2>

<h3>1️⃣ Client encodes characters into bits</h3>
<p>
Each character (8 bits) is converted into individual bits.  
- <code>SIGUSR1</code> = 0  
- <code>SIGUSR2</code> = 1  
</p>

<h3>2️⃣ Client sends signals to server</h3>
<p>
Signals are sent using <code>kill(server_pid, SIG)</code> with a short delay (usleep).
</p>

<h3>3️⃣ Server reconstructs characters</h3>
<p>
The server catches signals using <code>sigaction</code> and rebuilds characters bit-by-bit.
</p>

<h3>4️⃣ Server prints the final string</h3>

<hr>

<h2 align="center">📜 Mandatory Features</h2>

<ul>
  <li>Server prints its PID when launched</li>
  <li>Client sends a string to the server</li>
  <li>Server prints the received message</li>
  <li>Reliable bit-by-bit transfer</li>
  <li>No memory leaks</li>
  <li>Use only <code>SIGUSR1</code> and <code>SIGUSR2</code></li>
</ul>

<hr>

<h2 align="center">✨ Bonus Features</h2>

<p>You successfully implemented the bonus part. It includes:</p>

<ul>
  <li>🔁 <strong>Client receives confirmation</strong> from server</li>
  <li>🔤 <strong>Support for Unicode characters</strong> (multi-byte)</li>
  <li>🧱 <strong>Better signal handling</strong> with <code>sigaction</code></li>
  <li>📩 <strong>Message acknowledgment</strong> (server → client)</li>
</ul>

<hr>

<h2 align="center">🛠 Explanation of Your Files</h2>

<h3>📨 client.c</h3>
<p>Sends a classic (ASCII) message to the server bit-by-bit.</p>

<h3>🖥️ server.c</h3>
<p>Receives bits and prints the decoded ASCII message.</p>

<h3>🔧 utils.c</h3>
<p>Helper functions: ft_atoi, ft_putstr, bit manipulation helpers.</p>

<hr>

<h3>📨 client_bonus.c</h3>
<p>
Bonus client:
<ul>
  <li>Handles wide chars / Unicode</li>
  <li>Waits for server acknowledgment</li>
  <li>More robust communication</li>
</ul>
</p>

<h3>🖥️ server_bonus.c</h3>
<p>
Bonus server:
<ul>
  <li>Sends feedback to client after each char</li>
  <li>Improved signal handling</li>
  <li>Manages multi-byte sequences</li>
</ul>
</p>

<h3>🔧 utils_bonus.c</h3>
<p>Utility functions for handling Unicode and acknowledgments.</p>

<h3>📄 mini_talk.h / mini_talk_bonus.h</h3>
<p>
Header files containing:
<ul>
  <li>Function prototypes</li>
  <li>Data structures</li>
  <li>Signal macros</li>
</ul>
</p>

<hr>

<h2 align="center">🚀 Compilation</h2>

<pre style="background:#1e1e1e; color:white; padding:12px; border-radius:8px;">
# Mandatory
make

# Bonus
make bonus

# Clean
make clean
make fclean
make re
</pre>

<hr>

<h2 align="center">📌 How to Use (Mandatory)</h2>

<h3>1️⃣ Run server</h3>

<pre style="background:#1e1e1e; color:white; padding:12px; border-radius:8px;">
./server
# Output: Server PID: 12345
</pre>

<h3>2️⃣ Send message with client</h3>

<pre style="background:#1e1e1e; color:white; padding:12px; border-radius:8px;">
./client 12345 "Hello 42!"
</pre>

<hr>

<h2 align="center">🎉 Bonus Usage</h2>

<h3>1️⃣ Run bonus server</h3>
<pre style="background:#1e1e1e; color:white; padding:12px; border-radius:8px;">
./server_bonus
</pre>

<h3>2️⃣ Send message with bonus client</h3>
<pre style="background:#1e1e1e; color:white; padding:12px; border-radius:8px;">
./client_bonus 12345 "Hello 🌍"
</pre>

<p>Server acknowledges each character → client prints confirmation.</p>

<hr>

<h2 align="center">📚 Learning Outcomes</h2>

<ul>
  <li>Mastering UNIX signals</li>
  <li>Bitwise manipulation</li>
  <li>Reliable client-server communication</li>
  <li>Using <code>sigaction</code> and signal masks</li>
  <li>Handling asynchronous events</li>
  <li>Unicode processing (bonus)</li>
</ul>

<hr>

<h2 align="center">📜 License</h2>

<p style="font-size:16px;">
This README is provided for students of <strong>42 Network / 1337 School</strong>.  
Feel free to use, modify, and improve it for your Minitalk project.
</p>

<hr>

<h1 align="center">🚀 Good Luck! Enjoy Building Your Signal-Based Messenger ⚡</h1>
