# Lab 1 - FLEX Scanner

## Issues
```
* Suppose to catch all possible tokens so that no input should be copied to output.
```

`Files:`
* lang.l
* lex.h
* main.cpp
* tokens.h
* makefile

`Special File:`
* feedback.txt - feedback file for instructor comments

`Opional File:`
* test files - regression tests

## Description
```
lang.l is the starting point for the lab.  You need to edit this file so that FLEX can build a scanner for the language.  A list of all tokens is given in tokens.h.

tokens.h must not be edited and gives all the values of what FLEX must return for each token.

In order to complete this lab, the scanner must pass the regression tests.

```

## Tokens

| Punctuation | Operators | Keywords |     Others    |
|:-----------:|:---------:|:--------:|:-------------:|
|      (      |     !=    |  program |  identifiers  |
|      )      |     ==    |    if    | integer const |
|      {      |     &&    |   else   |  float const  |
|      }      |     \|\|  |   endif  |              |
|      [      |           |   while  |               |
|      ]      |           |   print  |               |
|      ;      |           |    int   |               |
|      '      |           |   float  |               |
|      .      |           |   char   |               |
|      +      |           |  struct  |               |
|      -      |           |   array  |               |
|      *      |           |  return  |               |
|      /      |           |   char   |               |
|      %      |           |          |               |
|      =      |           |          |               |
|             |           |          |               |

## Author
* [Kevin Xu](https://github.com/kevinjiaxu96)
