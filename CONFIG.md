# 🚀 Mini C++ Project – Group Development Setup

This project is a collaborative C++ application built using modern tooling including **CMake**, **Clang-format**, and **VS Code** for efficient group development and maintenance.

---

## 🛠️ Project Structure

```
Mini_Project/
├── include/            # Header files
├── src/                # Source code files
├── build/              # Build output (ignored by Git)
├── .vscode/            # Editor settings (local only)
├── .clang-format       # Code style configuration
├── CMakeLists.txt      # Build configuration
├── .gitignore          # Files/folders to exclude from Git
└── README.md           # Setup and usage instructions
```

---

## 🔧 Project Setup (For All Team Members)

### 1. 🔁 Clone the Repository
```bash
git clone https://github.com/<your-username>/<your-repo>.git
cd Mini_Project
```

### 2. 📦 Install Required Tools

| Tool           | Version   | Description                          |
|----------------|-----------|--------------------------------------|
| [VS Code](https://code.visualstudio.com/) | Latest    | Code editor                          |
| [CMake](https://cmake.org/download/)     | ≥ 3.10     | Build system generator               |
| [Clang/LLVM](https://releases.llvm.org/) | ≥ 13.0     | Formatter and compiler (optional)    |
| [MinGW](https://www.mingw-w64.org/)      | ≥ 9.x      | GCC compiler for Windows             |
| [Git](https://git-scm.com/)              | Latest     | Version control                      |

> ✅ Tip: Install `LLVM` using:
> ```powershell
> winget install LLVM.LLVM
> ```

---

## 💻 VS Code Configuration

Install the following extensions:

- **C/C++** — [ms-vscode.cpptools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- **CMake Tools** — [ms-vscode.cmake-tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
- **Code Runner** — [formulahendry.code-runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)
- **Clang-Format** — [xaver.clang-format](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format)
---

## 🧰 Build & Run

### 🔨 Step 1: Generate Build Files
```bash
mkdir build
cd build
cmake ..
```

### 🛠️ Step 2: Build the Project
```bash
cmake --build .
```

### ▶️ Step 3: Run the Executable
```bash
./MiniProject     # Linux/macOS
MiniProject.exe   # Windows
```

---

## 🎯 Format Code (Clang-Format)

### Automatically format on save:
```json
// .vscode/settings.json
{
    "editor.formatOnSave": true,
    "clang-format.executable": "C:/Program Files/LLVM/bin/clang-format.exe",
    "clang-format.style": "file"
}
```

### Manually format via terminal:
```bash
clang-format -i src/*.cpp include/*.hpp
```

> 📄 You must have `.clang-format` at the project root.

---

## 📦 Dependencies Summary

| Tool/Lib   | Purpose                      |
|------------|------------------------------|
| `g++` or `clang++` | Compile C++ code         |
| `CMake`    | Project configuration & build |
| `clang-format` | Code style consistency     |

---

## 🤝 Contribution Guide

- Use meaningful branch names: `feature/login`, `bugfix/overflow`
- Commit message convention:  
  `feat: add train booking logic`  
  `fix: resolve memory leak`
- Always `pull` before pushing.
- Run `clang-format` before committing.

---

## 📁 Example Commit Flow

```bash
git checkout -b feature/payment-module
# Make your changes...

git add .
git commit -m "feat: add payment module with dummy data"
git push origin feature/payment-module
```

---

## 💬 Team Members

| Name           | Role                 |
|----------------|----------------------|
| Ramzan Khan    | Lead Developer       |
| Tanay Pradhan  | Core Developer       |
| Trinav Mandal  | Documentations       |


---

## 📝 License

This project is licensed under the [MIT License](./LICENSE).


---

## 🙌 Acknowledgments

Thanks to all contributors, VS Code, LLVM, and CMake for excellent tooling!