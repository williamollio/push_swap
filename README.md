# 42 Push_swap

<strong>Introduction</strong>

The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted.

You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.


Your goal ? Write a program in C called push_swap which calculates and displays on the standard output the smallest program using Push_swap instruction language that sorts the integer arguments received.

The grade depends only on the number of operations that our program display to sort the inputs.

[Subject PDF](https://github.com/williamollio/push_swap/tree/master/subject)

# Grade
[![wollio's 42Project Score](https://badge42.herokuapp.com/api/project/wollio/push_swap)](https://github.com/williamollio/badge42)

# Clone
Open a terminal and run following command:
```
git clone <repository url>
```
# Run
Go to the created repository and run following command:
```
make
```
To start run following command :
```
./push_swap <arguments>
```
or, you can also use by creating a environment variable :
```
ARG="<arguments>"; ./push_swap $ARG
```
# Operations

To sort the arguments given as input, we have to use to stack A and B. Here is the available operations :
```
- sa :swap 'a' - swap the first 2 elements at the top of stack 'a';
- sb :swap 'b' - swap the first 2 elements at the top of stack 'b';
- ss :sa and sb at the same time.
- pa :push 'a' - take the first element at the top of 'b' and put it at the top of 'a'.
- pb :push 'b' - take the first element at the top of 'a' and put it at the top of 'b'.
- ra :rotate 'a' - shift up all elements of stack 'a' by 1.
- rb :rotate 'b' - shift up all elements of stack 'b' by 1.
- rr :ra and rb at the same time.
- rra :reverse rotate 'a' - shift down all elements of stack 'a' by 1.
- rrb :reverse rotate 'b' - shift down all elements of stack 'b' by 1;
- rrr :rra and rrb at the same time.

```

