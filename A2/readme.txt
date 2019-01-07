Patrick Copp
1007602
Assignment 2

Compilation: compile both q1 and q2 using command "make"

Question 1:

	Run: ./q1
	
	Sample outputs of each transaction:

	1. Enter a plate number: Test
	   Enter a mileage: 123
	   Moved Test to available

	2. Enter the car's plate number: Test
	   Enter the car's mileage: 135
	   Charge: $40.00
	   Moved Test from rented to available

	3. Enter the car's plate number: Test
	   Enter the car's mileage: 123
	   Charge: $40.00
	   Moved Test from rented to repair

	4. Enter the car's plate number: Test
	   Moved Test from repair to available

	5. Enter an expected return date (yymmdd): 121212
	   Moved Test from available to rented

	6. Available-for-Rent:
	   ******************

	   Rented:
	   ******
	   Test	   1223	   121212

	   Repair:
	   ******
	
	Note: Printed values are as follows: Plate Number, Mileage, Return Date (if rented)
	
	7. Total Profit: $190.15
	
	Note: Mileage costs in this program are calculated by subtracting the old mileage from the new mileage

	
	Files:
		q1.c:		 source code
		repair.txt:	 stores repair list
		rented.txt:	 stores rented list
		available.txt	 stores available list
	
	Note: I used three different record files for easier bugchecking, editting, and reliability


Question 2:

	Run: ./q2 (postfix expression)

	Sample output:

	./q2 23+4-5*
	5.00
	
	./q2 47+4-5/
	1.40


