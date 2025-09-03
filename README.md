# DSA Hacking Club - C library for Data Structures and Algorithms

[![Build Status](https://github.com/alifoo/dsa_hkc/actions/workflows/main.yml/badge.svg)](https://github.com/alifoo/dsa_hkc/actions)

This is a collective library built to easily implement data structures and
algorithms in C, made by two students of the Pontifical Catholic University of
Paraná (PUCPR).

## Requirements

* A C Compiler (like GCC or Clang)
* CMake (version 3.10 or higher)
* `make`

---

## How to Build and Install

Clone the repository and use CMake to build the project.

```bash
# 1. Clone the repository
git clone https://github.com/alifoo/dsa_hkc.git
cd dsa_hkc

# 2. Configure and build the project
mkdir build
cd build
cmake ..
make

# 3. Install the library system-wide
sudo make install
```
The `install` command copies the library (`libdsa_hkc.a`), the main header (`dsa_hkc.h`), and the CMake configuration files to a standard location (`/usr/local/`), making the library available to other projects.

---

## How to Use

Once the library is installed, you can use it in your own projects. Here are the two recommended methods.

### Method 1: Using CMake

This is the easiest and most portable way to use the library. Create a `CMakeLists.txt` for your own project and use `find_package()` to automatically locate and link the library.

**1. Your Project's `CMakeLists.txt`:**
```cmake
cmake_minimum_required(VERSION 3.10)
project(MyAwesomeApp C)

# Find the DsaHkc library
find_package(DsaHkc 1.0 REQUIRED)

# Add your executable
add_executable(my_app main.c)

# Link the library to your executable
target_link_libraries(my_app PRIVATE DsaHkc::dsa_hkc)
```

**2. Your Project's `main.c`:**
```c
#include <stdio.h>
#include <dsa_hkc.h>

int main() {
    // Initialize the table
    init_hash_table();

    // Create and insert data
    person marcos = {.name = "Marcos", .age = 18};
    hash_table_insert(&marcos);
    print_table();

    // Look up data
    person *tmp = hash_table_lookup("Marcos");
    if (tmp != NULL) {
        printf("\nFound %s, age %d.\n", tmp->name, tmp->age);
    }

    return 0;
}
```

**3. Build Your Project:**
When you run CMake, you may need to provide a hint to help it find the library in `/usr/local`.

```bash
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=/usr/local ..
make
./my_app
```

### Method 2: Manual Compilation (Using Flags)

If you are not using CMake, you can compile your program by manually telling the compiler where to find the library's header and library files.

```bash
# Compile main.c, providing paths for the header (-I) and library (-L),
# and linking the library (-l)
gcc main.c -I/usr/local/include -L/usr/local/lib -ldsa_hkc -o my_app
```

---

## Contributing

We welcome contributions! Please feel free to fork the repository, make your
changes, and submit a pull request.

---

### License

This project is licensed under the MIT License. See the `LICENSE` file for details.
