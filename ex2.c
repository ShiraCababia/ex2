/******************
Name: Shira Cababia
ID: 326153590
Assignment: ex2
*******************/

#include <stdio.h>

int main() {

	int isRequestedMenu = 1;
	int usersOption;
	while (isRequestedMenu) {
		 printf("Choose an option:\n");
		 printf("	1. happy Face\n");
		 printf("	2. Balanced Number\n");
		 printf("	3. Generous Number\n");
		 printf("	4. Circle Of Joy\n");
		 printf("	5. Happy Numbers\n");
		 printf("	6. Festival Of Laughter\n");
		 printf("	7. Exit\n");
 		 scanf("%d", &usersOption);
		 while ((usersOption < 1) || (usersOption > 7)) {
			printf("This option is not available, please try again.\n");
 		 	scanf("%d", &usersOption);
		 }

		 switch(usersOption) {
			

			case 1: {
				char eyes, nose, mouth;
				int faceSize;
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &eyes, &nose, &mouth);
				printf("Enter face size:\n");
				scanf("%d", &faceSize);
				while ((faceSize % 2 == 0) || (faceSize <= 0)){
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("%d", &faceSize);
				}
				// 
				printf("%c", eyes);
				for (int i=1; i<=faceSize; i++) {
					printf(" ");
				}
				printf("%c\n", eyes);
				// 
				for (int i=1; i<=(faceSize/2 + 1); i++) {
					printf(" ");
				}
				printf("%c\n", nose);
				// 
				printf("\\");
				for (int i=1; i<=faceSize; i++) {
					printf("%c", mouth);
				}
				printf("/\n");
			}

			//////////////////////////////////////////////////////////////////////////////////////
			case 2: {
				int num;
				printf("Enter a number:\n");
				scanf("%d", &num);
				while (num <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				int testedNum = num;
				int digCounter = 0;
				int numSides = 2;
				while (testedNum != 0) {
					testedNum = testedNum / 10;
					digCounter++;
				}
				testedNum = num;
				int numEachSide = digCounter / numSides;
				int sumRight = 0;
				int sumLeft = 0;
				for (int i=1; i <= numEachSide; i++) {
					sumRight = sumRight + (testedNum % 10);
					testedNum = testedNum / 10;
				}
				if (digCounter % 2 == 0) {
					for (int i=1; i <= numEachSide; i++) {
						sumLeft = sumLeft + (testedNum % 10);
						testedNum = testedNum / 10;
					}
				}
				else {
					testedNum = testedNum / 10;
					for (int i=1; i <= numEachSide; i++) {
						sumLeft = sumLeft + (testedNum % 10);
						testedNum = testedNum / 10;
					}
				}
				if (sumRight == sumLeft) {
					printf("This number is balanced and brings harmony!\n");
				}
				else {
					printf("This number isn't balanced and destroys harmony.\n");
				}
			}

			//////////////////////////////////////////////////////////////////////////////////////
			case 3: {
				
			}





			// case 7: {
			// 	printf("Thank you for your journey through Numeria!\n");
			// 	isRequestedMenu = 0;
			// }
		 }
	}


	// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
	/* Example:
	* n = 3:
	* 0   0
	*   o
	* \___/
	*/

	// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
	// and the sum of all digits to the right of the middle digit(s) are equal
	/* Examples:
	Balanced: 1533, 450810, 99
	Not blanced: 1552, 34
	Please notice: the number has to be bigger than 0.
	*/

	// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
	/* Examples:
	Abudant: 12, 20, 24
	Not Abudant: 3, 7, 10
	Please notice: the number has to be bigger than 0.
	*/

	// Case 4: determine wether a number is a prime.
	/* Examples:
	This one brings joy: 3, 5, 11
	This one does not bring joy: 15, 8, 99
	Please notice: the number has to be bigger than 0.
	*/
    

	// Happy numbers: Print all the happy numbers between 1 to the given number.
	// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
	/* Examples:
	Happy :) : 7, 10
	Not Happy :( : 5, 9
	Please notice: the number has to be bigger than 0.
	*/

	// Festival of Laughter: Prints all the numbers between 1 the given number:
	// and replace with "Smile!" every number that divided by the given smile number
	// and replace with "Cheer!" every number that divided by the given cheer number
	// and replace with "Festival!" every number that divided by both of them
	/* Example:
	6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
	*/

	// }

	return 0;
}
