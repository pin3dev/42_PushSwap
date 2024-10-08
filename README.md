<h1 align="center">PushSwap</h1>
<p align="center"> 
  <img src="https://img.shields.io/badge/grade-100%2F100-green?style=for-the-badge&logo=42&labelColor=gray"/>
</p>

<p align="center"> 
  <a href="https://github.com/pin3dev/42_Cursus/tree/main/push_swap/#02-Push_Swap">
    <img src="https://img.shields.io/badge/Sorting_Algorithms-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Data_structures-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Stacks-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Optimization-blue?style=for-the-badge"/>
  </a>
</p>

<p align="center">
  <img src="https://github.com/pin3dev/42_Cursus/blob/a708c0de6d3fdc729bb720318b5d35bdaa9551c0/assets/PushSwap/Rdm/pushswap_vs.gif" width="600" height="375" />
</p>

<h3>
  <p align="center"> 
    <a href="#introduction">Introduction</a> • 
    <a href="#structure">Structure</a> • 
    <a href="#docs">Docs</a> • 
    <a href="#cloning">Cloning</a> • 
    <a href="#usage">Usage</a> • 
    <a href="#norms">Norms</a> • 
    <a href="#theoretical">Theoretical</a> •   
    <a href="#tutorial">Tutorial</a> • 
    <a href="#contributors">Contributors</a>
  </p>
</h3>

## 🗣️ Introduction <a id="introduction"></a>

The **Push Swap** project is an algorithm challenge aimed at sorting a stack of integers in the least number of moves, using a constrained set of operations. This project serves as a way to deepen understanding of sorting algorithms and optimize problem-solving techniques.

This repository is dedicated to the implementation of an efficient solution to sort the stack using the minimum number of operations. The project does not include a checker, so the validation must be done with external tools or the checker provided by 42.

## 🧬 Project Structure <a id="structure"></a>

The **Push Swap** project is organized into different components based on the operations allowed to manipulate two stacks (A and B). The mandatory part includes creating algorithms to sort small to large sequences using the following operations:

- **`sa`**, **`sb`**, **`ss`**: Swap operations on stack A, stack B, or both.
- **`pa`**, **`pb`**: Push operations to move the top element from one stack to another.
- **`ra`**, **`rb`**, **`rr`**: Rotate operations to move the top element to the bottom.
- **`rra`**, **`rrb`**, **`rrr`**: Reverse rotate operations to move the bottom element to the top.

The project is focused on optimization and efficiency, aiming to minimize the number of moves for different stack sizes.

## 🗃️ Documentation <a id="docs"></a>

For detailed documentation, including usage examples and function breakdowns, please visit the link below:  

<p align="center"> 
  <a href="https://github.com/pin3dev/42_Push_Swap/wiki">
    <img src="https://img.shields.io/badge/PushSwap_Docs-lightgreen?style=for-the-badge"/>
  </a>
</p>

## 🫥 Cloning the Repository <a id="cloning"></a>

To clone this repository and compile the project, run the following commands:

```bash
git clone https://github.com/pin3dev/42_Push_Swap.git
cd 42_Push_Swap
```
This will download the project from GitHub into your local machine. Once inside the `42_Push_Swap` directory, you can compile the project using the provided Makefile.

## 🕹️ Compilation and Usage <a id="usage"></a>

### Makefile

A `Makefile` is provided to simplify the compilation process. The Makefile includes the following rules:

- `all`: Compiles the project.
- `clean`: Removes object files.
- `fclean`: Removes object files and the executable.
- `re`: Recompiles the entire project from scratch.

To compile the project, simply run:
```bash
make
```
This will generate the `push_swap` executable, which can be used to sort a list of integers.

### Basic Usage

To run the **Push Swap** algorithm on a list of integers:

1. Execute the program with a set of integers as arguments:
    ```bash
    ./push_swap 3 5 2 1 4
    ```

2. The program will output a sequence of operations needed to sort the integers:
    ```bash
    pb
    ra
    sa
    pa
    ```

You can also test the number of operations by piping the output to `wc -l`:
```bash
./push_swap 3 5 2 1 4 | wc -l
```

## ⚠️ Norms and Guidelines Disclaimer <a id="norms"></a>

This project strictly follows the [**42 School Norm**](https://github.com/pin3dev/42_Cursus/blob/b9cd0fe844ddb441d0b3efb98abcee92aee49535/assets/General/norme.en.pdf) coding guidelines, which significantly influenced certain decisions in its implementation. These rules may sometimes lead to seemingly inefficient or unusual solutions, but they were necessary to meet the strict requirements of the school.  

## 📖 Theoretical Background <a id="theoretical"></a>

All the theoretical materials used for the development of this project are available in the repository link provided below. These resources cover algorithm design, sorting techniques, and optimization strategies.

<p align="center"> 
  <a href="https://github.com/pin3dev/42_Cursus/tree/main/library/#02-Push_Swap">
    <img src="https://img.shields.io/badge/PushSwap_Library-gray?style=for-the-badge"/>
  </a>
</p>

## 🔬 Tutorial <a id="tutorial"></a>

A step-by-step tutorial is available and can be followed to complete the project. It is linked in the button below.   

<p align="center"> 
  <a href="https://github.com/pin3dev/42_Cursus/tree/main/tutorial/PushSwap">
    <img src="https://img.shields.io/badge/PushSwap_Tutorial-lightgreen?style=for-the-badge"/>
  </a>
</p>

## 👥 Contributors <a id="contributors"></a>

<a href="https://github.com/pin3dev">
  <img src="https://img.shields.io/badge/Ivany_Pinheiro-%40pin3dev-purple?style=for-the-badge"/>  
</a>  
<br>
<a href="https://github.com/clima-fr">
  <img src="https://img.shields.io/badge/Clara_Franco-%40clima--fr-purple?style=for-the-badge"/>  
</a>
