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
git clone [https://github.com/alifoo/dsa_hkc.git](https://github.com/alifoo/dsa_hkc.git)
cd dsa_hkc

# 2. Create a build directory
mkdir build
cd build

# 3. Configure and build the project
cmake ..
make

# 4. (Optional) Install the library system-wide
sudo make install
```
This will install `libdsa_hkc.a` into `/usr/local/lib` and `dsa_hkc.h` into `/usr/local/include`.

---

## How to Use

Once the library is installed, you can include the header in your own C projects and link against it during compilation.

**`example.c`**
```c
#include <stdio.h>
#include <dsa_hkc.h>

int main() {
    // 1. Initialize the table
    init_hash_table();

    // 2. Create some data
    person marcos = {.name = "Marcos", .age = 18};
    person rafa = {.name = "Rafa", .age = 20};

    // 3. Insert data into the table
    hash_table_insert(&marcos);
    hash_table_insert(&rafa);
    printf("Table after inserts:\n");
    print_table();

    // 4. Look up a person
    person *tmp = hash_table_lookup("Marcos");
    if (tmp == NULL) {
        printf("\nMarcos was not found!\n");
    } else {
        printf("\nFound %s, age %d.\n", tmp->name, tmp->age);
    }

    return 0;
}
```

**Compile your program:**
```bash
# The -ldsa_hkc flag tells the compiler to link our library
gcc example.c -ldsa_hkc -o my_app
```

---

## Contributing

We welcome contributions! Please feel free to fork the repository, make your
changes, and submit a pull request.

---

### License

This project is licensed under the MIT License. See the `LICENSE` file for details.
