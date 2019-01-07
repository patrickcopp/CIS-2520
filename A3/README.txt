Patrick Copp
Assignment 3

Compilation: compile both questions using command "make"

Question 1: 
	
	Run: ./q2 [expression]

	I honestly didn't complete q1 even mildly, I did not have the time.
	I completed parsing the numbers in the program but completed little else.
	Regardless, it compile cleanly and has some functionality completed.

Question 2:

	Run: ./q2

	Sample output given the example .dat file:
	
	
25	12	17	82	52	53	5	3	68	64	
16	14	27	99	29	99	79	45	59	19	
50	9	6	44	59	87	32	36	36	46	
12	0	68	68	49	68	74	32	9	30	
81	30	16	65	40	39	44	49	32	60	
25	41	11	88	15	39	88	69	31	49	
44	27	68	96	70	98	85	13	25	47	
3	60	76	23	14	81	82	0	38	4	
43	27	20	59	4	84	10	42	43	2	
41	82	53	40	29	84	24	61	87	20	
99	37	50	93	57	6	29	91	92	39	
81	14	42	21	9	69	5	30	20	91	
3	37	97	53	36	54	69	68	38	43	
83	82	43	11	21	4	8	97	93	14	
51	90	37	86	42	44	48	64	41	1	
96	89	75	0	63	24	54	20	20	24	
88	56	59	88	39	30	44	59	49	72	
49	17	44	32	33	54	60	33	51	87	
9	83	22	90	74	56	64	75	67	55	
41	62	82	46	69	42	74	68	79	28

	The program reads in integers from f.dat, stores them, then creates
	a min-heap based upon the value of the sum of the first three integers
	in the object.

	The algorithm runs a downheap starting from the last parent node twice (O(n)),
	because log20=1.3 O(n log n).


