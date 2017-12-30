#include <stdio.h>		//Contains functions prototypes
#include <stdlib.h>
#pragma warning(disable: 4996)		//Disables scanf_s for visual studio
void printAuthor() {				//Function that prints the Author information
	printf("Author: Mohammad Abdul Salam\n");
	printf("Program: #1, Guess Number\n");
	printf("TA : Alexis, Tues\n");
	printf("Jan 18, 2017\n\n\n");
}
void printInstructions() {			//Function that prints the Instructions information
	printf("Welcome to the guessing number game!\n");
	printf("If you concentrate, sometimes you can connect to the electrons in the computer!\n");
	printf("Let's try it.\nThink of a three-digit number\n");
	printf("(To make it harder, make the digits all different from each other).\n\n");
}

int userInput() {						//Function that takes threedigits from the user
	int threedigits = 0;					//Initializing a variable
	printf("Enter a three digit number\n");
	scanf("%d", &threedigits);				//Takes the input and stores it in the variable (threedigits)
	return threedigits;					//Returning the value user put in
}

int main() {
	printAuthor();					//Calling the printAuthor function inside main
	printInstructions();				//Calling the printInstructions function inside main
	int threedigits;				
	threedigits = userInput();			//Setting a variable equal to another variable
	


	int reverseNumber;				//Initializing a variable

	int reverseInput;				//Initializing a variable
	int value1 = 0;					//Initializing a variable
	int value2 = 0;					//Initializing a variable
	int value3 = 0;					//Initializing a variable

	value1 = threedigits % 10;			//Calculation takes out the third digit from the threedigits
	value2 = (threedigits % 100) / 10;		//Calculation takes out the sescond digit from the threedigits
	value3 = threedigits / 100;			//Calculation takes out the first digit from the threedigits

	if ((value1 == value2) || (value2 == value3) || (value3 == value1)) {			//If statement to stop the program if user inputs a dublicate number
		printf("*** All three digits are not different.  Exiting program...\n");	//Prints the following if user input is a dublicate

	}
	else {											//else executes if user input isn't a dublicate number
		printf("I'll help you with the math. Lets randomize those digits by reversing them, and do a subtraction:\n");	
		reverseNumber = (value1 * 100) + (value2 * 10) + value3;			//the variable "reverseNumber" stores the added value of the user input after reversi

		int subtracted;									//Initializing a variable
		if (threedigits <= reverseNumber) {						//Using an if else statement to arrange the order. Bigger number on top minus the smaller one
			printf("  %d    (The reversed number)\n", reverseNumber);		//Printing the value in reverseNumber
			printf("- %d    (The original number)\n", threedigits);			//Printing the value in threedigits
			subtracted = reverseNumber - threedigits;				//Substracting both variables
			printf("=======\n  %d\n", subtracted);					//Printing the subtracted value after the calculation
		}	else {									//else executes if threedigits is not less than or equal to the reverseNumber
			printf("  %d    (The original number)\n", threedigits);			//Printing the value in threedigits
			printf("- %d    (The reversed number)\n", reverseNumber);		//Printing the value in reverseNumber
			subtracted = threedigits - reverseNumber;				//Subtracting both variables
			printf("=======\n  %d\n", subtracted);					//Printing the substracted value after the calculation
		}
		char input;									//Initializing a character
		char Enter;									//Initializing a character
		printf("Press y to continue or x to exit\n");					//Printing the statement
		scanf(" %c", &input);								//Storing the input character in the variable "input"
		if (input == 'x') {								//Using an if statement to prevent the function from proceeding if the user input is x
			return 0;
		}
		else{										//else executes if user input is not equal to 'x'
		printf("\nNow lets again scramble the numbers by reversing them, and adding them this time:\n");		//Printing the statement
		}
		int secondReverse;							//Initializing a variable
		printf("  %d    (Previous Answer)\n", subtracted);			//Printing the value stored in the variable "subtracted"

		value1 = subtracted % 10;						//Taking out the third digit
		value2 = (subtracted % 100) / 10;					//Taking out the second digit
		value3 = subtracted / 100;						//Taking out the first digit
		secondReverse = (value1 * 100) + (value2 * 10) + value3;

		printf("+ %d    (Second Reverse)\n", secondReverse);
		int Addition;
		Addition = subtracted + secondReverse;
		printf("=======\n   ?");
	//adding second reversed value and subtracted value
		printf("\n\nBefore you continue, take a look at my number guess written down on paper.\n\n");

		printf("Press 'd' to display the answer or 'x' to exit\n");

		scanf(" %c", &input);
		if (input == 'x') {			//'x' is to stop the program
			return 0;
		}
		else if (input == 'd') {		//'d' is to display
			printf("Answer is %d\n\n", Addition);

		}




		printf("Press 't' to test all possible combinations or 'x' to exit...\n");


		scanf(" %c", &input);
		if (input == 'x') {
			return 0;
		}
		else if (input == 't') {
			printf("For all numbers between 1..1000, the values that do not work are:\n\n");
			int fails;
			for (threedigits = 0, fails = 0; threedigits < 1000; threedigits++) {
				value1 = threedigits % 10;
				value2 = (threedigits % 100) / 10;
				value3 = threedigits / 100; //20

				if ((value1 == value2) || (value2 == value3) || (value3 == value1)) {
					printf("  %d", threedigits);
					fails++;

				}
				else {
					reverseNumber = (value1 * 100) + (value2 * 10) + value3;

					if (threedigits <= reverseNumber) {
						subtracted = reverseNumber - threedigits;
					}
					else {
						subtracted = threedigits - reverseNumber;
					}

					value1 = subtracted % 10;
					value2 = (subtracted % 100) / 10;
					value3 = subtracted / 100;
					secondReverse = (value1 * 100) + (value2 * 10) + value3;

					Addition = subtracted + secondReverse;
					if (Addition != 1089) {
						printf("  %d", threedigits);
						fails++;
					}
				}
			}
			printf("\n\nThere are %d values that do not work\n\n", fails);
			printf("Thanks for playing!\n\n");
		}

	}
	//'t' tests all possibilities <= 1000 and displays them excluding numbers that have two or more repeating digits
	//using a counter to count all the ones that don't work then printing them


	return 0;
}
