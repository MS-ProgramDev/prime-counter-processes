# Prime Counter – Process-based Implementation in C (Linux)

This project is an academic exercise in systems programming, focusing on process management and inter-process communication in C on Linux.

It implements three different execution modes for counting prime numbers in a given range.

---

##  Modes of Operation

- **Single Mode:**  
  A single process calculates all primes in the specified range.

- **Child Mode:**  
  The main process forks multiple child processes. Each child handles a portion of the range and returns the result via `exit()`.

- **Exec Mode:**  
  Similar to child mode, but each child process executes a separate program (`count_primes`) using `execv()`.

---

##  Technologies Used

- **C (POSIX)**
- **Linux system calls:** `fork()`, `execv()`, `waitpid()`
- **Makefile** for compilation
- Modular structure (`.c` and `.h` files)
- Command-line arguments and range validation

---

##  Project Structure

```bash
.
├── ex1_q1.c           # Main program handling all modes
├── count_primes.c     # Executable for use with execv
├── my_libary_fun.c    # Utility functions for prime calculations
├── my_libary_fun.h    # Header file
├── Makefile           # Build file for compilation
└── README.md          # This documentation
```

---

##  Build Instructions

To compile the project, run:

```bash
make
```

This will generate two executables:
- `ex1_q1`
- `count_primes`

---

##  Usage Examples

### Single Mode
```bash
./ex1_q1 single 1 100
```

### Child Mode (4 children)
```bash
./ex1_q1 child 1 100 4
```

### Exec Mode (4 processes via execv)
```bash
./ex1_q1 exec 1 100 4
```

All modes print the total number of primes found in the given range.

---

##  Author

**Maor Sapo**  
Third-year Computer Science student, passionate about system-level programming, C++, and Linux environments.

---

##  License

This project is for academic use and demonstration only.
