# Push Swap `100/100`

<p align="center">
  <img src="https://github.com/pin3dev/42_Cursus/blob/a708c0de6d3fdc729bb720318b5d35bdaa9551c0/assets/PushSwap/Rdm/pushswap_vs.gif" width="600" height="375" />
</p>

<p align="center">
  <a href="https://github.com/pin3dev/42_Push_Swap/wiki">🎰---TUTORIAL---🎰</a>
</p>


## Table of Contents
- [Project Overview](#overview)
- [Mandatory Features](#features)
- [Project Compilation and Execution](#compilation-and-execution)
- [Tests -  Usage Examples](#usage-examples)
- [Copyright](#contributors)

## Overview

The `push_swap` project is an algorithm challenge aiming to sort a stack of integers using the least possible number of operations, adhering to a specified set of allowed operations.

This repository does not have a checker, so it is necessary for the sorting test to be carried out by third-party testers or by the checker provided by 42.

## Features

1. Efficient algorithm to sort the stack.
2. Limited set of operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

## Compilation and Execution

```bash
#Compilation
make

#Execution option 1:
ARG="3 5 2 1 4"; ./push_swap $ARG
#[...list of operations...]

#Execution option 2:
$>./push_swap 3 5 2 1 4
#[...list of operations...]
```

## Usage Examples

```bash
#Test counting the amount of movements:
ARG="3 5 2 1 4"; ./push_swap $ARG | wc -l
#[...amount of operations...]

#Test counting the amount of movements:
./push_swap 3 5 2 1 4 | wc -l
#[...amount of operations...]

#Test with sort checker:
ARG="3 5 2 1 4"; ./push_swap $ARG | ./checker $ARG
#OK

#Test with non-integer:
./push_swap 3 5 2 one 4
#Error

./push_swap 3 5 2 -2147483649 4
#Error

./push_swap 3 5 2 2147483649 4
#Error

./push_swap 3 5 2 --2 4
#Error
#$>

./push_swap 3 5 2 -+2 4
#Error

./push_swap 3 5 2 - 4
#Error

```

## Contributors

* Ívany Pinheiro aka [`@pin3dev`](https://github.com/pin3dev)
* Clara Franco aka [`@clima-fr`](https://github.com/clima-fr)
