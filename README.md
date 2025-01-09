# Push_swap

Push_swap is a 42 school project where the goal is to sort a stack of integers using a set of predefined operations. The challenge is to do so efficiently, using the fewest possible moves.

---

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Operations](#operations)
- [Algorithm](#algorithm)
- [Evaluation](#evaluation)

---

## Introduction

In the Push_swap project, you are given two stacks (called `a` and `b`) and a set of operations to manipulate them. The objective is to sort stack `a` in ascending order, with stack `b` being empty at the end. The project emphasizes algorithmic efficiency and performance.

---

## Features

- Handles input validation (only integers, no duplicates).
- Implements stack operations for manipulation and sorting.
- Provides a visual representation of the sorting process (optional).
- Uses efficient sorting algorithms tailored to stack-based operations.

---

## Usage

### Compilation

Compile the program using the provided Makefile:

```bash
make
```

### Running the Program

To execute the program, provide a sequence of integers:

```bash
./push_swap 4 2 3 1 5
```

The output will be the list of operations needed to sort the stack.

### Testing with Checker

Use the `checker` program to verify the output:

```bash
./push_swap 4 2 3 1 5 | ./checker 4 2 3 1 5
```

- `OK`: The operations correctly sorted the stack.
- `KO`: The stack is not sorted, or an error occurred.

---

## Operations

The following operations are available to manipulate the stacks:

- **Swap**:
  - `sa`: Swap the first two elements of stack `a`.
  - `sb`: Swap the first two elements of stack `b`.
  - `ss`: Perform `sa` and `sb` simultaneously.

- **Push**:
  - `pa`: Push the top element of stack `b` to stack `a`.
  - `pb`: Push the top element of stack `a` to stack `b`.

- **Rotate**:
  - `ra`: Rotate stack `a` upward.
  - `rb`: Rotate stack `b` upward.
  - `rr`: Perform `ra` and `rb` simultaneously.

- **Reverse Rotate**:
  - `rra`: Rotate stack `a` downward.
  - `rrb`: Rotate stack `b` downward.
  - `rrr`: Perform `rra` and `rrb` simultaneously.

---

## Algorithm

### Small Set of Numbers

For a small number of elements (e.g., 3-5), the sorting can be done using hardcoded rules or simple algorithms like bubble sort.

### Larger Set of Numbers

For larger datasets, consider more advanced techniques like:

- **Divide and Conquer**: Splitting the data into smaller subsets.
- **Radix Sort**: Sorting based on digit significance.
- **Greedy Algorithms**: Making locally optimal choices for global efficiency.

---

## Evaluation

The project is evaluated based on:

1. Correctness: The program must sort the stack correctly.
2. Efficiency: The number of operations used should be minimal.
3. Code Quality: The code should be clean, well-documented, and modular.
4. Edge Cases: Handling duplicates, invalid input, and large datasets.

---

### Author

Chaimaa Laghrabi  
42 Network Student  
