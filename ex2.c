/******************
Name: Shira Cababia
ID: 326153590
Assignment: ex2
*******************/

#include <stdio.h>

int main() {

	// A variable represents whether the menu should be presented again.
	int isRequestedMenu = 1;
	// A variable represents the chosen option by the user.
	int usersOption;
	// As long as the menu should be represented again, repeat the following code.
	while (isRequestedMenu) { 
		printf("Choose an option:\n");
		printf("	1. Happy Face\n");
		printf("	2. Balanced Number\n");
		printf("	3. Generous Number\n");
		printf("	4. Circle Of Joy\n");
		printf("	5. Happy Numbers\n");
		printf("	6. Festival Of Laughter\n");
		printf("	7. Exit\n");
 		scanf("%d", &usersOption);
		// As long as the user chose an option that doesn't exist, represent a message and let him try again.
		while ((usersOption < 1) || (usersOption > 7)) {
			printf("This option is not available, please try again.\n");
 			scanf("%d", &usersOption);
		}

		switch(usersOption) {
			
			// If the user chose option "1" - Draw Happy Face with given symbols for eyes, nose and mouse.
			case 1: {
				char eyes, nose, mouth;
				int faceSize;
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &eyes, &nose, &mouth);
				printf("Enter face size:\n");
				scanf("%d", &faceSize);
				// As long as the user inputs an even or 0/negative number, represent a message and let him try again.
				while ((faceSize % 2 == 0) || (faceSize <= 0)){
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("%d", &faceSize);
				}
				/* Print the 'eye' char, Add spaces in the chosen amount, 
				and Add anothe 'eye' char at the end of the raw (Create 'eyes' look). */
				printf("%c", eyes);
				for (int i=1; i<=faceSize; i++) {
					printf(" ");
				}
				printf("%c\n", eyes);
				/* Print spaces in half of the chosen amout (to split it in both sides of the 'nose' char),
				Add the 'nose' char, and Print spaces again in half of the chosen amount 
				(Create 'nose' look in the middle of the raw)*/
				for (int i=1; i<=(faceSize/2 + 1); i++) {
					printf(" ");
				}
				printf("%c\n", nose);
				// Print '\', Print 'mouth' char in the chosen amount, and Print '/' (Create 'mouth' look)
				printf("\\");
				for (int i=1; i<=faceSize; i++) {
					printf("%c", mouth);
				}
				printf("/\n");
				break;
			}

			/* If the user chose option "2" - Determine whether the sum of all digits to the left of the middle 
			digit(s) and the sum of all digits to the right of the middle digit(s) are equal. */
			case 2: {
				int num;
				printf("Enter a number:\n");
				scanf("%d", &num);
				// As long as the user inputs a 0/negative number, represent a message and let him try again.
				while (num <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				/* The variable 'testedNum' conatins the 'num' value, that will be manipulated. 
				I created it to not use the original variable, for possible future use in the original input value. */
				int testedNum = num;
				// A variable that represents the number of digits of the user's input.
				int digCounter = 0;
				// A variable that represents the number of sides we want to check in the number.
				int numSides = 2;
				// The loop finds the number of digits of the user's input.
				while (testedNum != 0) {
					testedNum = testedNum / 10;
					digCounter++;
				}
				testedNum = num;
				/* A variable that represents the number of digits from both sides of the chosen number 
				(the middle digit, if exist, doesn't count since it belongs to neither of sides.) */
				int numEachSide = digCounter / numSides;
				// A variable that represents the sum of the digits in the right side of the chosen number.
				int sumRight = 0;
				// A variable that represents the sum of the digits in the left side of the chosen number.
				int sumLeft = 0;
				// The loop calculates the sum of the digits in the right side of the chosen number.
				for (int i=1; i <= numEachSide; i++) {
					sumRight = sumRight + (testedNum % 10);
					testedNum = testedNum / 10;
				}
				/* If the number of digits is even, there are left the same amount of digits to sum in the 
				remain number (the left side). So we just repeat the process.*/
				if (digCounter % 2 == 0) {
					for (int i=1; i <= numEachSide; i++) {
						sumLeft = sumLeft + (testedNum % 10);
						testedNum = testedNum / 10;
					}
				}
				/* If the number of digits is odd, there are left same amount of digit plus one (the middle digit!), 
				so we remove it (since it doesn't belong to neither of sides) and then repeat the process.*/
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
				break;
			}

			/* If the user chose option "3" - Determine whether the sum of the proper divisors (od an integer) 
			is greater than the number itself. */
			case 3: {
				int num;
				printf("Enter a number:\n");
				scanf("%d", &num);
				// As long as the user inputs a 0/negative number, represent a message and let him try again.
				while (num <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				int sumdivisors = 0;
				/* The loop sum the dividors of the chosen number (while saving runtime), and stops the loop 
				and print a message the moment it finds the sum is bigger than the original number. */
				for (int i=num/2; i>0; i--) {
					if (num % i == 0) {
						sumdivisors = sumdivisors + i;
					}
					if (sumdivisors > num) {
					printf("This number is generous!\n");
					break;;
					}
				}
				// If the sum of the dividers isn't bigger than the original number, print a message.
				if (sumdivisors <= num) {
					printf("This number does not share.\n");
				}
				break;
			}

			// If the user chose option "4" - Determine wether a number is a prime.
			case 4: {
				int num;
				printf("Enter a number:\n");
				scanf("%d", &num);
				// As long as the user inputs a 0/negative number, represent a message and let him try again.
				while (num <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				/* Edge Cases + Saving runtime ==> It is known that '1' isn't a prime number, 
				and It is known that every even number (except 2) is not a prime number, since it can be divided by 2. */
				if ((num == 1) || (num%2 == 0 && num!=2)) {
					printf("The circle remains incomplete.\n");
				}
				// If the number isn't 1 and isn't even' continue checking.
				else {
					// A variable that represents wether the number have divided.
					int isNumDivided = 0;
					// A variable that represents wether the reversed number have divided.
					int isReversedDivided = 0;
					/* The loop checks wether the num is dividable (while saving runtime), and stops the loop 
					and change the 'isNumDivided' value the moment it finds a divisor. */
					for (int i=num/2; i>2; i--) {
						if (num % i == 0) {
							isNumDivided = 1;
							break;
						}
					}
					// If the number isn't dividable, we find and create the reversed number and check the same on it.
					if (!isNumDivided) {
						int tempNum = num;
						int reversedNum = 0;
						int tempDig = 0;
						// Creating the reversed number.
						while (tempNum != 0) {
							tempDig = tempNum % 10;
							tempNum = tempNum / 10;
							reversedNum = (reversedNum * 10) + tempDig;
						}
						/* Checking if the reversed number is a peime number. And if it is, change 
						the 'isReversedDivided' value the moment it finds a divisor. */
						for (int i=reversedNum/2; i>2; i--) {
							if (reversedNum % i == 0) {
								isReversedDivided = 1;
								break;
							}
						}
					} 
					// If the chosen number and the reversed number are prime numbers, represent a proper message.
					if (!isNumDivided && !isReversedDivided) {
						printf("This number completes the circle of joy!\n");
					}
					// If the chosen number and the reversed number are not *both* prime numbers, represent a proper message.
					else {
						printf("The circle remains incomplete.\n");
					}
				}
				break;
			}

			/* If the user chose option "5" - Print all the 'Happy numbers' (Number which eventually reach 1 
			when replaced by the sum of the square of each digit) between 1 to the given number. */
			case 5: {
				int n;
				printf("Enter a number:\n");
				scanf("%d", &n);
				// As long as the user inputs a 0/negative number, represent a message and let him try again.
				while (n <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &n);
				}
				printf("Between 1 and %d only these numbers bring happiness: ", n);
				// A variable that represents the number we test the "Happy Number" algorithm on.
				int tempN = 0;
				// A variable that represents the Unity Digit of the tempN.
				int nDig = 0;
				// A variable that represents the sum of the squared digits of the tested number.
				int sumSquareDigits = 0;
				// checking what numbers between 1 and n are "Happy Numbers" and printing them.
				for (int i=1; i<=n; i++) {
					tempN = i;
					/* As long as we didn't get a result that indicates that the number is "Happy Number" or isn't,
					we keep checking. */
					while (sumSquareDigits != 1 && sumSquareDigits != 4 && sumSquareDigits != n && sumSquareDigits != 7) {
						// Equate the 'sumSquareDigits to zero for the next checked number.
						sumSquareDigits = 0;
						// Calculating the sum of the squared digits of the tested number.
						while (tempN != 0) {
						nDig = tempN % 10;
						sumSquareDigits = sumSquareDigits + (nDig * nDig);
						tempN = tempN / 10;
						}
						/* If we finished checking the tempN number, we want to do it all over again for 
						the value of 'sumSquareDigits' so we put it as 'tempN'. */
						if (tempN == 0) {
							tempN = sumSquareDigits;
						}
					} 
					// If 'sumSquareDigits' is 1 or 7 - the i number is a Happy Number so we print it.
					if (sumSquareDigits == 1 || sumSquareDigits == 7) {
						printf("%d ", i);
					}
					// Equate the 'sumSquareDigits to zero for the next i number.
					sumSquareDigits = 0;
				}
				printf("\n");
				break;
			}

			/* If the user chose option "6" - Print all the numbers between 1 and the given number,
			replace with "Smile!" every number that divided by the given 'smile' number,
			replace with "Cheer!" every number that divided by the given 'cheer' number,
			and replace with "Festival!" every number that divided by both of them. */
			case 6: {
				int smile=0, cheer=0;
				printf("Enter a smile and cheer number:\n");
				/* Determine the format of the requested input, save the user' input values for 'smile' and 'cheer'
				as the variables' values. */
				int numOfInputs = scanf(" smile : %d , cheer : %d", &smile, &cheer);
				/* As long as we didn't recieve 2 numbers, or the user' input values for 'smile' and 'cheer' are not
				numbers, or the inputs are equal, represent a message and ask the user to input proper inputs. */
				while (numOfInputs != 2 || smile <= 0 || cheer <= 0 || smile == cheer) {
					// Clean the Buffer
					scanf("%*[^\n]%*c");
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					numOfInputs = scanf(" smile : %d , cheer : %d", &smile, &cheer);
				}
				int n = 0;
				printf("Enter maximum number for the festival: \n");
				scanf("%d", &n);
				// As long as the user inputs a 0/negative number, represent a message and let him try again.
				while (n <= 0) {
					printf("Only positive maximum number is allowed, please try again:\n");
					scanf("%d", &n);
				}
				// For every number between 1 and the chosen number : 
				for (int i=1; i<=n; i++) {
					/* If the number divisible by the 'smile' value and 'cheer' value, 
					replace its printing with the string "Festival! */
					if ((i % smile == 0) && (i % cheer == 0)) {
						printf("Festival!\n");
					}
					// If the number divisible by the 'smile' value, replace its printing with the string "Smile!
					else if ((i % smile == 0) && !(i % cheer == 0)) {
						printf("Smile!\n");
					}
					// If the number divisible by the 'cheer' value, replace its printing with the string "Cheer!
					else if ((i % cheer == 0) && !(i % smile == 0)) {
						printf("Cheer!\n");
					}
					// If the number is not divisible by neither 'cheer' value and 'smile' value, print the num i itself.
					else {
						printf("%d\n", i);
					}
				}
				break;
			}

			/* If the user chose option "7" - Represent a message and end the program - (change 
			'isRequestedMenu' value so the menu won't be represented again). */
			case 7: {
				printf("Thank you for your journey through Numeria!\n");
				isRequestedMenu = 0;
				break;
			}
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
