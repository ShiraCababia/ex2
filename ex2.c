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
		printf("	1. Happy Face\n");
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
				break;
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
				break;
			}

			//////////////////////////////////////////////////////////////////////////////////////
			case 3: {
				int num;
				printf("Enter a number:\n");
				scanf("%d", &num);
				while (num <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				int sumdivisors = 0;
				for (int i=num/2; i>0; i--) {
					if (num % i == 0) {
						sumdivisors = sumdivisors + i;
					}
					if (sumdivisors > num) {
					printf("This number is generous!\n");
					break;;
					}
				}
				if (sumdivisors <= num) {
					printf("This number does not share.\n");
				}
				break;
			}

			//////////////////////////////////////////////////////////////////////////////////////
			case 4: {
				int num;
				printf("Enter a number:\n");
				scanf("%d", &num);
				while (num <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				if ((num == 1) || (num%2 == 0 && num!=2)) {
					printf("The circle remains incomplete.\n");
				}
				else {
					int isNumDivided = 0;
					int isReversedDivided = 0;
					for (int i=num/2; i>2; i--) {
						if (num % i == 0) {
							isNumDivided = 1;
							break;
						}
					}
					if (!isNumDivided) {
						int tempNum = num;
						int reversedNum = 0;
						int tempDig = 0;
						while (tempNum != 0) {
							tempDig = tempNum % 10;
							tempNum = tempNum / 10;
							reversedNum = (reversedNum * 10) + tempDig;
						}
						for (int i=reversedNum/2; i>2; i--) {
							if (reversedNum % i == 0) {
								isReversedDivided = 1;
								break;
							}
						}
					}
					if (!isNumDivided && !isReversedDivided) {
						printf("This number completes the circle of joy!\n");
					}
					else {
						printf("The circle remains incomplete.\n");
					}
				}
				break;
			}

			//////////////////////////////////////////////////////////////////////////////////////
			case 5: {
				int n;
				printf("Enter a number:\n");
				scanf("%d", &n);
				while (n <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &n);
				}
				printf("Between 1 and %d only these numbers bring happiness: ", n);
				int tempN = 0;
				int nDig = 0;
				int sumSquareDigits = 0;
				for (int i=1; i<=n; i++) {
					tempN = i;
					while (sumSquareDigits != 1 && sumSquareDigits != 4 && sumSquareDigits != n && sumSquareDigits != 7) {
						sumSquareDigits = 0;
						while (tempN != 0) {
						nDig = tempN % 10;
						sumSquareDigits = sumSquareDigits + (nDig * nDig);
						tempN = tempN / 10;
						}
						if (tempN == 0) {
							tempN = sumSquareDigits;
						}
					}
					if (sumSquareDigits == 1 || sumSquareDigits == 7) {
						printf("%d ", i);
					}
					sumSquareDigits = 0;
				}
				printf("\n");
				break;
			}

			//////////////////////////////////////////////////////////////////////////////////////
			case 6: {
				int smile=0, cheer=0;
				printf("Enter a smile and cheer number:\n");
				int numOfInputs = scanf(" smile : %d , cheer : %d", &smile, &cheer);
				while (numOfInputs != 2 || smile <= 0 || cheer <= 0 || smile == cheer) {
					scanf("%*[^\n]%*c");
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					numOfInputs = scanf(" smile : %d , cheer : %d", &smile, &cheer);
				}
				int n = 0;
				printf("Enter maximum number for the festival: \n");
				scanf("%d", &n);
				while (n <= 0) {
					printf("Only positive maximum number is allowed, please try again:\n");
					scanf("%d", &n);
				}
				for (int i=1; i<=n; i++) {
					if ((i % smile == 0) && (i % cheer == 0)) {
						printf("Festival!\n");
					}
					else if ((i % smile == 0) && !(i % cheer == 0)) {
						printf("Smile!\n");
					}
					else if ((i % cheer == 0) && !(i % smile == 0)) {
						printf("Cheer!\n");
					}
					else {
						printf("%d\n", i);
					}
				}
				break;
			}

			//////////////////////////////////////////////////////////////////////////////////////
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
