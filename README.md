# Holberton School _Monty_

### The Monty language

> Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

##### Monty byte code files:

- Files containing Monty byte codes usually have the .m extension
- There is not more than one instruction per line.
- There can be any number of spaces before or after the opcode and its argument
- Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account

### Example of a Monty file:  (note: the '$' character shows newline)
```shell
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
```
## The monty program

- Usage: ==monty file==
    - where ==file== is the path to the file containing Monty byte code
- The monty program runs the bytecodes line by line and stop if either:
    - it executed properly every line of the file
    - it finds an error in the file
    - an error occured
- The prototypes of all the functions are included in the header file called [monty.h](https://github.com/FabioH7/holbertonschool-monty/blob/master/monty.h)

## Monty Opcodes

- ##### Push opcode
    - The opcode ==push== pushes an element to the stack.
    - Usage: ==push <int>==
        - Where ==<int>== is an integer
- ##### Pall opcode
    - The opcode pall prints all the values on the stack, starting from the top of the stack.
    - Usage: ==pall==

Demonstration of the ==push== and ==pall== opcodes:
```shell
$ ~/monty$ cat bytecodes/06.m 
push 1
push 2
push 3
pall
$ ~/monty$ ./monty bytecodes/06.m 
3
2
1
```
- ##### Pint opcode
    - The opcode pint prints the value at the top of the stack, followed by a new line.
    - Usage: ==pint==

Demonstration of the ==pint== opcode:
```shell
$ ~/monty$ cat bytecodes/06.m 
push 1
push 2
push 3
pall
$ ~/monty$ ./monty bytecodes/06.m 
3
2
1
```

- ##### Pop opcode
    - The opcode pop removes the top element of the stack.
    - Usage: ==pop==

Demonstration of the ==pop== opcode:
```shell
$ ~/monty$ cat bytecodes/06.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
$ ~/monty$ ./monty bytecodes/06.m 
3
2
1
2
1
1
```

- ##### Swap opcode
    - The opcode swap swaps the top two elements of the stack.
    - Usage: ==swap==

Demonstration of the ==swap== opcode:
```shell
$ ~/monty$ cat bytecodes/06.m 
push 1
push 2
push 3
pall
swap
pall
$ ~/monty$ ./monty bytecodes/06.m 
3
2
1
2
3
1
```

- ##### Add opcode
    - The opcode add adds the top two elements of the stack.
    - The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
        - The top element of the stack contains the result
        - The stack is one element shorter
    - Usage: ==add==

Demonstration of the ==swap== opcode:
```shell
$ ~/monty$ cat bytecodes/06.m 
push 1
push 2
push 3
pall
add
pall
$ ~/monty$ ./monty bytecodes/06.m 
3
2
1
5
1
```

- ##### nop opcode
    - The opcode nop does nothing
    - Usage: ==nop==

## Contributing
[Katrolli](https://github.com/Katrolli) and [FabioH7](https://github.com/FabioH7)

### License
> Don't worry it's free lol!

