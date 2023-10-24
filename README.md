# Push Swap

## Overview

The `push_swap` project is an algorithm challenge aiming to sort a stack of integers using the least possible number of operations, adhering to a specified set of allowed operations. This repository consists of two programs: a `checker`, which verifies the list of operations, and `push_swap`, which produces the list of operations to sort the stack.

## Features

1. Efficient algorithm to sort the stack.
2. Checker program to validate the sorting operations.
3. Limited set of operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

## Compilation and Execution

```bash
make
ARG="3 5 2 1 4"; ./push_swap $ARG | ./checker $ARG
```

## Usage Examples

```bash
$> ARG="3 5 2 1 4"; ./push_swap $ARG
[...list of operations...]
$> ARG="3 5 2 1 4"; ./push_swap $ARG | ./checker $ARG
OK
```

## Contributors

* Ívany Pinheiro
* Clara Franco