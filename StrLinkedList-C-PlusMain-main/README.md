# String List Manipulation in C

## Overview

This project implements a custom data structure for managing a list of strings, called `StrList`, in C. The project provides functionalities to create, manipulate, and query lists of strings. The `StrList` can handle operations such as insertion, deletion, searching, and sorting of strings. The project includes a command-line interface to interact with the `StrList` through various options.

### Components

- **StrList**
  - `StrList.h`: Header file defining the interface for the `StrList` data structure.
  - `StrList.c`: Implementation of the `StrList` functions, including memory management, list operations, and utility functions.

- **Main Program**
  - `Main.c`: The main file that provides a command-line interface for the user to interact with the `StrList`. It allows users to insert, delete, print, reverse, sort, and query the list through a menu-driven system.

- **Makefile**
  - `Makefile`: Automates the compilation process of the project files.

### Features

- **Dynamic List Management**: The `StrList` allows dynamic insertion and deletion of strings.
- **Custom Sorting**: Sort the strings in lexicographical order.
- **Reversal**: Reverse the order of strings in the list.
- **Query Operations**: Count occurrences of a string, get the number of characters, and check if the list is sorted.
- **Memory Management**: Proper allocation and deallocation of memory for strings and nodes.

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection) or any compatible C compiler.
- Linux/Unix or Windows environment.

### Compiling the Project

To compile the project, use the provided `Makefile`. Run the following command in the terminal:

```sh
make
```

This will compile the `StrList.c` and `Main.c` files and generate the executable.

### Running the Program

To run the compiled program:

```sh
./Main
```

### Command-Line Interface

Upon running the program, you will be prompted to enter a command (an integer) to perform various operations on the `StrList`. The available commands are:

- **0**: Exit the program.
- **1**: Add a series of words from a story to the list.
- **2**: Insert a word at a specified index.
- **3**: Print all words in the list.
- **4**: Print the size of the list.
- **5**: Print the word at a specific index.
- **6**: Print the total number of characters in the list.
- **7**: Count occurrences of a word in the list.
- **8**: Remove all occurrences of a word in the list.
- **9**: Remove the word at a specific index.
- **10**: Reverse the order of the list.
- **11**: Free all nodes in the list (clear the list).
- **12**: Sort the list in lexicographical order.
- **13**: Check if the list is sorted lexicographically (prints `true` or `false`).

### Example Usage

```sh
# Start the program
./Main

# Enter commands as prompted, for example:
# Enter "1" to add a series of words
# Enter "3" to print the current list
# Enter "12" to sort the list
# Enter "0" to exit the program
```

## Project Structure

- **`StrList.h`**: Defines the `StrList` structure and function prototypes.
- **`StrList.c`**: Implements the `StrList` operations such as insertion, deletion, and sorting.
- **`Main.c`**: Provides the user interface for interacting with the `StrList`.
- **`Makefile`**: Script to compile the project.

## License

This project is open-source and available under the MIT License. Feel free to use, modify, and distribute as per the terms of
