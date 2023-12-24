# Lesson 1: Hello World!

## Overview
- Introduction to C++ programming.
- Writing and running a basic C++ program.

## Learning Objectives
- Understand the fundamentals of C++ syntax and structure.
- Learn how to create, compile, and run a C++ program.
- Familiarize yourself with common C++ input/output functions.

## Prerequisites
- None

## Lesson Content

### C++ Basics
- C++ is a powerful and widely-used programming language known for its efficiency and performance.
- It is an object-oriented language that can be used to develop a wide range of software applications.
- Today, we'll start with a simple "Hello, World!" program to get you acquainted with C++.

### Writing Your First Program
- In C++, the traditional first program is one that displays "Hello, World!" on the screen.
- Let's break down the code step by step:
  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      cout << "Hello, World!" << endl;
      return 0;
  }
### Explanation of code components:
- #: The start of a preprocessor command.
- #include: specific preprocessor command, include the functionality in the program without having to literally cut and paste it into the source code every time.
- #include <iostream>: This line includes the input/output library.
- using namespace std;:  allows you to use all the names defined in the std namespace without explicitly specifying(prefix) the namespace. It contains many standard library functions and objects.  For example, you can write cout instead of std::cout, cin instead of std::cin, and so on.
- int main() { ... }: The main function is the entry point of the program.
- cout: cout is short for “character output”
- <<: behave like functions, This capability is called operator overloading.
- {}: block of code defined within {} token represents start and end.
- ;(semicolons): Statements in C++ must be terminated with a semicolon.
- return 0;: This line indicates a successful program execution. It signals to the operating system that everything went smoothly. By default, a C++ program will always return 0 if there is no return at the end of main.

### Running the Program
- Compiler: It is the translator that acts as an intermediary between the programmer and the CPU on the computer.
Compile the program using a C++ compiler (e.g., g++):

```cpp
g++ hello.cpp -o hello
or
./hello
```
You should see "Hello, World!" displayed on the screen

