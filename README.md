# TEAM BGH Text Editor

A lightweight, console-based text editor written in C. It supports live character 
input, backspace deletion, multi-line text, and an **undo feature** powered by a 
stack data structure — all running in a simple terminal interface.

---

## 📖 Description

TEAM BGH Text Editor is a beginner-friendly console text editor built entirely in C. 
It demonstrates core data structure concepts — particularly **stacks** — by saving 
the text buffer's state after every keystroke, allowing users to undo their last 
action at any time. The editor supports character-by-character input without 
pressing Enter, backspace-based deletion, multi-line text entry, and full-screen 
redraws for a clean editing experience.

---

## ✨ Features

- 🖊️ Real-time typing — no need to press Enter to register input
- ⌫ Backspace support for deleting characters
- ↩️ Multi-line text entry
- 🔄 Undo functionality using a stack of saved states
- 🧹 Clean screen redraw after undo/backspace
- 🚪 Simple exit with ESC key

---

## 🎮 Controls

| Key         | Action                     |
|-------------|-----------------------------|
| Any letter/number/symbol | Types the character |
| `Enter`     | Inserts a new line          |
| `Backspace` | Deletes the last character  |
| `Ctrl + Z`  | Undo last action            |
| `ESC`       | Exit the editor             |

---

## 🛠️ Build & Run Instructions

### Requirements
- Windows OS (uses `conio.h` and `system("cls")`)
- Code::Blocks (or any C compiler like MinGW/GCC on Windows)

### Steps
1. Clone the repository:
```bash
   git clone https://github.com/<your-username>/team-bgh-text-editor.git
   cd team-bgh-text-editor
```
2. Open the `.c` file in **Code::Blocks** (or compile via terminal):
```bash
   gcc text_editor.c -o text_editor.exe
```
3. Run the compiled program:
```bash
   text_editor.exe
```
4. Start typing! Use `Ctrl+Z` to undo, and `ESC` to exit.

> ⚠️ **Note:** This program uses `conio.h`, which is Windows-specific. It will 
> **not** compile as-is on Linux/macOS without modification (e.g., using `ncurses` 
> or termios-based alternatives).

---

## ⚙️ How It Works (Algorithm Summary)

1. The program continuously reads one keystroke at a time using `getch()`.
2. Before every text modification (typing, backspace, or newline), the **current 
   state of the text buffer is pushed onto a stack**.
3. Pressing `Ctrl+Z` pops the last saved state off the stack and restores it as 
   the current text — effectively undoing the last change.
4. The screen is redrawn after undo/backspace operations to reflect the updated text.
5. Pressing `ESC` exits the program and prints a closing message.

For detailed algorithm and pseudocode, see [`ALGORITHM.md`](ALGORITHM.md).

---

## 📉 Known Limitations

- **Memory usage:** Every keystroke stores a *full copy* of the text buffer in the 
  undo stack (`stack[MAX][MAX]`), which is inefficient for large amounts of text.
- **Platform-locked:** Relies on `conio.h` and `system("cls")`, so it only works 
  on Windows/Code::Blocks environments.
- **No redo functionality** — once undone, an action cannot be redone.
- **Fixed buffer size** — limited to `MAX = 1000` characters and undo states.

---

## 🚀 Future Improvements

- [ ] Add **redo** functionality
- [ ] Store undo history as diffs/operations instead of full text snapshots (reduce memory usage)
- [ ] Add **file save/load** support
- [ ] Cross-platform support (replace `conio.h` with `ncurses` or termios)
- [ ] Add cursor movement (arrow keys) for mid-text editing
- [ ] Syntax highlighting or line numbering

---

## 👥 Contributors

- TEAM BGH

---

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).
