# Lab 3 - LL(1) Parser
`Special File:`
* feedback.txt - feedback file for instructor comments

`Opional File:`
* test files - regression tests

`Source File:`
* lab3_jiawei_xu.tar

## Description
```


```

## Grammar
```

Explaination:

PROG  -> STMTS end
STMTS -> STMT STMTS
      -> λ
STMT  -> EXPR ;
EXPR  -> (EXPR) EXPR’
      -> TERM
EXPR’ -> PLUSOP (EXPR) EXPR’
      -> λ
PLUSOP -> +
       -> -
TERM  -> [EXPR] TERM’
      -> num
TERM’ -> TIMESOP [EXPR] TERM’
      -> λ
TIMESOP -> *
        -> /

```
## Author
* [Kevin Xu](https://github.com/kevinjiaxu96)