# Lab 2 - Symbol Table

`Files:`
* lang.l
* lex.h
* cSymbol.h
* cSymbolTable.h
* cSymbolTable.cpp
* main.cpp
* tokens.h
* makefile

`Special File:`
* feedback.txt - feedback file for instructor comments

`Opional File:`
* test files - regression tests

## Description
```
cSymbolTable.h and lang.l is the starting point of this lab.

Need to modify lang.l to call appropriate methods for scope and symbols.

Need to modify cSymbolTable.h to implement the methods provided by the function prototypes.

```

## Example
```
{
    a;
    b;
    {
        c;
        d;
    }
}

Explaination:

a and b are in their own scope.
c and d are in their own scope.

when the } bracket ends, c and d will be out of scope and the table for that is therefor 
popped off the stack.
```
## Author
* [Kevin Xu](https://github.com/kevinjiaxu96)