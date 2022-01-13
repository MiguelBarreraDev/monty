# Monty Interpreter

`monty` is an interpreter of Monty ByteCodes files, which is a scripting language Just like Python.

## Info
This is a language that contains specific instructions to manipulate data information (stacks or queues),
where each instruction (called opcode) is sended per line. Files which contains Monty byte codes usually have
the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language.

####  Monty files
 There is not more than one instruction per line. Lines that start with # are not executed.

Example (`000.m`):
```bash
>$ cat 000.m
# Pushing element to the stack
push 0
push 1
push 2
# Printing all elements
pall
push 3
push 4
pop
# Rotating the stack to the bottom
rotr
pall
rotl
# Setting FIFO
queue
push 5
# Setting LIFO
stack
push 5
$
```

There can be any number of spaces before or after the opcode and its argument:
Example (`001.m`):
```Bash
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```
## Technologies
* Interpreter was written with C language
* C files are compiled using `gcc 10.2.1`
* Tested on Ubuntu 20.04 LTS

## Features

### Available Opcodes Functions

`monty` executes the following opcodes:
| Opcode | Description |
| -------- | ----------- |
| `push` | Pushes an element to the stack |
| `pall` | Prints all the values on the stack |
| `pint` | Prints the value at the top of the stack |
| `pop` | Removes the top element of the stack |
| `swap` | Swaps the top two elements of the stack |
| `nop` | Doesn't do anything |
| `add` | Adds the top two elements of the stack |
| `sub` | Subtracts the top element of the stack from the second top element of the stack |
| `mul` | Multiplies the second top element of the stack with the top element of the stack |
| `div` | Divides the second top element of the stack by the top element of the stack |
| `mod` | Computes the rest of the division of the second top element of the stack by the top element of the stack |
| `pchar` | Prints the char at the top of the stack |


Comments, indicated with `#`, are not executed by the interpreter.

When a **nonextistent opcode** is passed, the interpreter prints an error message and stops:

```bash
>$ cat 002.m

push 1
pint
pcx
>$ ./monty errorfile.m
1
L3: unknown instruction pcx
```

## Usage
To compile all files:

```bash
>$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
>$
```

The **synopsis** of the interpreter is the following:

```bash
>$ ./monty [filename]
>$
```

To run the interpreter:

```bash
>$ ./monty 000.m
2
1
0
0
3
2
1
>$
```

## Authors
* Miguel Barrera: [Twitter](https://twitter.com/migue_dev_23) - [GitHub](https://github.com/MiguelBarreraDev)
* Rogelio C: [Twitter](https://twitter.com/RogelioConde5) - [GitHub](https://github.com/)
