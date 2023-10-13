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
- #include <iostream>: This line includes the input/output library.
- using namespace std;: This line allows you to use cout and cin without specifying std::.
- int main() { ... }: The main function is the entry point of the program.
- cout << "Hello, World!" << endl;: This line displays the message.
- return 0;: This line indicates a successful program execution. It signals to the operating system that everything went smoothly. By default, a C++ program will always return 0 if there is no return at the end of main.

### Running the Program
Compile the program using a C++ compiler (e.g., g++):

```cpp
g++ hello.cpp -o hello
or
./hello
```
You should see "Hello, World!" displayed on the screen

