# My Shell - Unix Command Interpreter

A custom Unix shell implementation in C. This project implements a functional command-line interpreter with support for built-in commands, external program execution, and advanced features like pipes and redirections.

## 📋 Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Advanced Features](#advanced-features)
- [Examples](#examples)
- [Project Structure](#project-structure)
- [Testing](#testing)
- [Known Limitations](#known-limitations)
- [Contributing](#contributing)
- [License](#license)

---

## ✨ Features

### Minishell1 (Basic Shell)
- ✅ Interactive command prompt
- ✅ External command execution (ls, cat, grep, etc.)
- ✅ PATH resolution for commands
- ✅ Environment variable management
- ✅ Built-in commands (cd, env, setenv, unsetenv, exit)
- ✅ Error handling with appropriate messages
- ✅ Exit status management

### Minishell2 (Advanced Shell)
- 🚧 Command separators (`;`)
- 🚧 Pipes (`|`)
- 🚧 Input/Output redirections (`<`, `>`, `>>`)
- 🚧 Here document (`<<`)
- 🚧 Error output redirection (`2>`, `2>&1`)

---

## 🔧 Requirements

### System
- Linux or Unix-like operating system
- GCC compiler
- Make

## 🚀 Installation

### Clone the repository
```bash
git clone https://github.com/saltyycode/my_sh.git
cd my_sh
```

### Compile the project
```bash
make
```

### Clean build files
```bash
make clean      # Remove object files
make fclean     # Remove all generated files
make re         # Recompile from scratch
```

---

## 💻 Usage

### Interactive mode
```bash
./my_sh
```

The shell will display a prompt and wait for commands:
```bash
My_SH $> ls -l
My_SH $> cd /tmp
My_SH $> pwd
/tmp
My_SH $> exit
```

### Non-interactive mode (piped input)
```bash
echo "ls -l" | ./my_sh
```

### Exit the shell
- Type `exit` or `exit [code]`
- Press `Ctrl+D` (EOF)

---

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Code style
- Follow the Epitech coding style
- Maximum 80 characters per line
- Functions should not exceed 20 lines
- Declare all variables at the beginning of functions
- Use meaningful variable names

---

## 👥 Authors

- **Clément / SaltyyCode** - [GitHub](https://github.com/saltyycode) - [Portfolio](https://saltyycode.github.io/)

---