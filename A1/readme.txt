Patrick Copp

1007602

Assignment 1

*************************************************
MAKEFILE DESCRIPTION

makefile: use command "make" to compile all
included .c files. This makefile compiles the
following files as object files:
	carbon.c
	ackermann.c
	newton.c
and compiles main.c as an executable file "main".

*************************************************
RUNNING THE ASSIGNMENT

In order to run the assignment, you must enter
"./main" along with three following command line
arguments.

The command line arguments are as follows:

	1. Ackermann's "m" value
	2. Ackermann's "n" value
	3. Positive real to be square rooted by
		Newton's method

All 3 program's outputs will be printed at once
in the following order: carbon.c, ackermann.c,
newton.c.

*************************************************
SAMPLE OUTPUT

assuming "./main 1 2 16"

carbon.c:
	carbon
	carbno
	...
	nobrca
	nobrac

ackermann.c: (m=1,n=2)
	Ackermann(1,2): 4

newton.c: (16)
	Recursive square root: 4.000000
	Iterative square root: 4.000000

***********************************************
KNOWN LIMITATIONS OF PROGRAMS

ackermann.c:
	range: (5,0) works, (5,1) does not

