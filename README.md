*This project has been created as part of the 42 curriculum by vpoka.*

# CPP02 — Ad-hoc Polymorphism and Operator Overloading

A C++98 project from the 42 curriculum focused on fixed-point arithmetic, operator overloading, and the Orthodox Canonical class form.

## Table of contents

- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)
- [What this project demonstrates](#what-this-project-demonstrates)
- [Technical constraints](#technical-constraints)
- [Repository structure](#repository-structure)
- [Focus areas by exercise](#focus-areas-by-exercise)
- [Status](#status)

## Description

CPP02 is the third module of the 42 C++ Common Core sequence. Its purpose is to introduce object-oriented programming in C++98 by building one small class step by step: a fixed-point number, a numeric type missing from C++.

Along the way the module covers the Orthodox Canonical class form (default constructor, copy constructor, copy assignment operator, and destructor) and ad-hoc polymorphism through operator overloading.

This module is split into four exercises:

* **ex00 — My First Class in Orthodox Canonical Form**
  Create the `Fixed` class with raw-bit storage and a constant fractional-bit count, and observe every canonical operation through logged messages.
* **ex01 — Towards a more useful fixed-point number class**
  Add integer and floating-point conversions, `toFloat`/`toInt`, and a `<<` stream insertion overload.
* **ex02 — Now we're talking**
  Overload comparison, arithmetic, and increment/decrement operators, and add static `min`/`max` helpers.
* **ex03 — BSP**
  Add an immutable `Point` class and a `bsp` function that decides whether a point lies strictly inside a triangle.

| Exercise | Executable | Main types |
| --- | --- | --- |
| [ex00](ex00/) — My First Class in Orthodox Canonical Form | `ex00` | `Fixed` |
| [ex01](ex01/) — Towards a more useful fixed-point number class | `ex01` | `Fixed` |
| [ex02](ex02/) — Now we're talking | `ex02` | `Fixed` |
| [ex03](ex03/) — BSP | `ex03` | `Fixed`, `Point`, `bsp()` |

## Instructions

### Prerequisites

- A C++ compiler available as `c++`, supporting `-std=c++98`.
- GNU Make and standard Unix shell utilities. The Makefiles use `-Wall -Wextra -Werror -std=c++98`; no external libraries are required.
- From ex01 on, `roundf` (from `<cmath>`) is the only extra function allowed by the subject.

The repository does not specify minimum compiler or Make versions.

### Build

Run these commands from the repository root. Each exercise has its own Makefile; there is no root Makefile.

```bash
make -C ex00
make -C ex01
make -C ex02
make -C ex03
```

Each Makefile provides `all`, `clean` (remove the `build/` directory), `fclean` (also remove the executable), `re` (rebuild), and `run` (rebuild, then execute). For example:

```bash
make -C ex00 clean
make -C ex01 fclean
make -C ex02 re
make -C ex03 run
```

Object files and generated dependency files live in a `build/` directory inside each exercise. The executable is named after the exercise: `ex00`, `ex01`, `ex02`, `ex03`.

### Run

None of the programs take arguments (`int main(void)`). From the repository root:

```bash
./ex00/ex00
./ex01/ex01
./ex02/ex02
./ex03/ex03
```

### ex00 — My First Class in Orthodox Canonical Form

```bash
make -C ex00 && ./ex00/ex00
```

The `Fixed` class stores its value as a raw `int` with a static constant fractional-bit count of 8, and implements the four Orthodox Canonical Form operations plus `getRawBits`/`setRawBits`. The program builds a few objects, copies and assigns them, and prints their raw values. Each canonical operation and each `getRawBits` call is announced on standard output (`Default constructor called`, `Copy constructor called`, `Copy assignment operator called`, `getRawBits member function called`, `Destructor called`), so the run doubles as a trace of the object lifecycle.

### ex01 — Towards a more useful fixed-point number class

```bash
make -C ex01 && ./ex01/ex01
```

`Fixed` gains constructors from `int` and `float`, the `toFloat` and `toInt` conversion members, and a `<<` overload that prints the floating-point representation. The program creates values such as `10`, `42.42f`, and `1234.4321f`, prints each one as a fixed-point value and as an integer, and shows the constructor messages (`Int constructor called`, `Float constructor called`) as they happen. Conversion to `float` divides the raw value by 2^8; `toInt` discards the fractional part.

### ex02 — Now we're talking

```bash
make -C ex02 && ./ex02/ex02
```

`Fixed` now overloads the six comparison operators (`>`, `<`, `>=`, `<=`, `==`, `!=`), the four arithmetic operators (`+`, `-`, `*`, `/`), and the pre/post increment and decrement operators, which step by the smallest representable value, 1/256 (about 0.00390625). Static `min` and `max` functions come in const and non-const variants.

The program runs two blocks: `=====GIVEN-TESTS=====` reproduces the subject's demonstration (increment behaviour and `Fixed::max`), and `=====OWN-TESTS=====` adds a small division example. Division by zero does not crash: `operator/` prints `ERROR: denominator is 0 in divison` and yields `0`.

### ex03 — BSP

```bash
make -C ex03 && ./ex03/ex03
```

`Point` holds `const Fixed` coordinates `x` and `y` with getters and a `<<` overload. The `bsp` function, implemented in `ex03/src/bsp.cpp`, decides whether a point is inside a triangle using cross-product orientation tests of the three edges. The test is strict: a point on an edge or on a vertex counts as outside, as the subject requires.

The program runs six built-in cases (interior point, exterior point, a vertex, two larger triangles, and points on edges) and prints each verdict together with the coordinates involved.

## Resources

- **cppreference:** entries for operator overloading, copy constructors, copy assignment operators, `std::ostream` and `operator<<`, and `roundf`. Consult the C++98 behavior when reading modern documentation.
- **ISO/IEC 14882:1998 (C++98):** the language standard this module targets.
- **David Goldberg, *What Every Computer Scientist Should Know About Floating-Point Arithmetic*:** the classic floating-point background reference.
- **The fixed-point and floating-point readings cited in the ex00 subject text:** linked from the subject PDF (see below).
- **GNU Make manual:** targets, automatic variables, and dependency tracking.
- **The module subject PDF:** supplied alongside the module repositories in the parent directory of this checkout.

### AI usage

AI was used to help write and improve this README and project documentation, prepare commits, and, where output or data visualisation is more complex, tweak that output.

## What this project demonstrates

* C++98 development under strict compilation rules (`-Wall -Wextra -Werror -std=c++98`)
* Orthodox Canonical Form: default and copy constructors, copy assignment operator, and destructor
* Ad-hoc polymorphism through operator overloading (comparison, arithmetic, increment/decrement, stream insertion)
* Fixed-point arithmetic with 8 fractional bits, converting to and from `int` and `float`
* Small-scale geometric computation with cross products (point-in-triangle test)
* Self-checking example programs that document each exercise's expected behaviour

## Technical constraints

This project is developed under the 42 C++ module rules:

* Standard: **C++98**
* Compiler flags: **`-Wall -Wextra -Werror -std=c++98`**
* Classes are designed in the **Orthodox Canonical Form**
* `using namespace` and `friend` are forbidden by the subject
* External libraries, Boost, and C++11 or later features are forbidden; so are `*printf()`, `*alloc()`, and `free()`
* STL containers and `<algorithm>` are forbidden in this module (the STL is allowed only from Module 08 on)
* No function implementations in headers (except function templates); headers use include guards and are self-contained
* `roundf` from `<cmath>` is the only allowed extra function from ex01 on
* Makefiles follow the same rules as in the C modules

## Repository structure

```text
cpp02/
├── README.md
├── ex00/   # My First Class in Orthodox Canonical Form
│   ├── include/   # Fixed.hpp
│   ├── src/       # main.cpp, Fixed.cpp
│   └── Makefile   # builds the ex00 executable
├── ex01/   # Towards a more useful fixed-point number class
│   ├── include/   # Fixed.hpp
│   ├── src/       # main.cpp, Fixed.cpp
│   └── Makefile
├── ex02/   # Now we're talking
│   ├── include/   # Fixed.hpp
│   ├── src/       # main.cpp, Fixed.cpp
│   └── Makefile
└── ex03/   # BSP
    ├── include/   # Fixed.hpp, Point.hpp
    ├── src/       # main.cpp, Fixed.cpp, Point.cpp, bsp.cpp
    └── Makefile
```

## Focus areas by exercise

### ex00 — My First Class in Orthodox Canonical Form

* Orthodox Canonical Form with observable lifecycle logging
* raw integer storage with a static constant fractional-bit count (8)
* `getRawBits`/`setRawBits` accessors

### ex01 — Towards a more useful fixed-point number class

* integer and floating-point conversions to and from fixed-point
* rounding with `roundf`
* stream insertion overload for `Fixed`

### ex02 — Now we're talking

* comparison, arithmetic, and increment/decrement operator overloading
* stepping by the smallest representable value (1/256)
* static `min`/`max` overloads for const and non-const operands

### ex03 — BSP

* immutable `Point` with `const Fixed` coordinates
* cross-product orientation tests
* strict point-in-triangle check (edges and vertices excluded)

## Status

* **Status:** Completed
* **Final grade:** **100/100 points**
