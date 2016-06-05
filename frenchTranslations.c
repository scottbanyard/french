/* Scott Banyard Summer 2015
	 French Translation program
	 - basic french program that translates numbers, colours and months
	 - created to recap C and to recap basic french
   - greatly improved in March 2016 / (covers 0 - 99999 number translations) using indexes, used to be a hard coded amount of numbers
   - improved in June 2016, switchboard can be re-called, tests ask random questions with no duplicates, choose how many questions you want
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// declaring functions
void coloursTest();
void numbersTest();
void monthsTest();
void upperCase(char a[]);
char toupper();
int isspace(); // used to check if space in array

// max number for questions in number test
int const MAX_NUMBER_FOR_TESTS = 200;

// translations from 0-19
char *translations[22] = {"zero", "un", "deux", "trois", "quatre", "cinq", "six", "sept",
										"huit", "neuf", "dix", "onze", "douze", "treize", "quatorze",
										"quinze", "seize", "dix-sept", "dix-huit", "dix-neuf"};
// translations for 10, 20, 30... 100
char *multiples[13] = {"", "dix", "vingt", "trente", "quarante", "cinquante", "soixante", "soixante-dix",
										"quatre-vingt", "quatre-vingt-dix", "cent", "mille"};


// removes whitespace at end of string
void trim(char * s) {
    char * p = s;
    int l = strlen(p);

    while(isspace(p[l - 1])) p[--l] = 0;
    while(* p && isspace(* p)) ++p, --l;

    memmove(s, p, l + 1);
}

// returns number translation in a buffer array
void numbers(int i, char* buff) {
	// // keep answer inside this array to return
	char finalAnswer[50];
	// // clears finalAnswer array incase want to know another number
	// memset(&finalAnswer[0], 0, sizeof(finalAnswer));
	// get from array using i as index
	if (i >= 0 && i <= 19) {
		strcpy(buff, translations[i]);
		// printf("%s", answer);
	} else {
		// get number length (number of digits)
		int nDigits = floor(log10(abs(i))) + 1;

		// error catching - no translations for over 100,000 at the moment
		if (nDigits >= 6) {
			printf("Please enter a number between 0 - 99999.\n");
		} else {

			// track each digit
			char* eachDigit[nDigits];
			int k = 0;
			int savedDigit;
			// put each digit into an array
				for (int e = 0; e < nDigits; e++) {
					// get digit
					k = i % 10;
					// first digit will be 1, 2, 3,...
					if (e == 0) {
						eachDigit[e] = translations[k];
					// second digit will be 10, 20, 30....
					} else if (e == 1) {
						eachDigit[e] = multiples[k];
					//third digit will be 100, 200, 300...
					} else if (e == 2) {
						// if 100, only say cent not un cent
						if (k == 1) {
							eachDigit[e] = multiples[10];
						} else if (k >= 2 && k <= 9) {
							char hundredValue[13] = "";
							// get value of hundred i.e. one hundred, two hundred etc
							strcpy(hundredValue, translations[k]);
							strcat(hundredValue, " ");
							// add on cent
							strcat(hundredValue, multiples[10]);
							eachDigit[e] = hundredValue;
						} else {
							// else will be zero - don't need to print that
							eachDigit[e] = "";
						}
					} else if (e == 3) {
						if (nDigits != 5) {
							if (k == 1) {
								eachDigit[e] = multiples[11];
							} else if (k >= 2 && k <= 9){
								char thousandValue[13] = "";
								// get value of hundred i.e. one hundred, two hundred etc
								strcpy(thousandValue, translations[k]);
								strcat(thousandValue, " ");
								// add on mille
								strcat(thousandValue, multiples[11]);
								eachDigit[e] = thousandValue;
							} else {
								// will be zero - don't need to print
								eachDigit[e] = "";
							}
						} else {
							savedDigit = k;
							// put mille into eachDigit
							eachDigit[e] = multiples[11];
						}
					} else if (e == 4) {
						// if in 10 thousands, use translations from 10 - 19
						if (k == 1) {
							// multiply current digit by 10 and add on previous digit i.e. 12000 = 1 | 2 as digits, 1*10 = 10 + 2 = 12
							int value = (k * 10) + savedDigit;
							eachDigit[e] = translations[value];
						} else {
							char thousandValue[25] = "";
							// get value of hundred i.e. one hundred, two hundred etc
							strcpy(thousandValue, multiples[k]);
							// if theres a second digit (not zero) then add that on
							if (savedDigit >= 2 && savedDigit <= 9) {
								strcat(thousandValue, " ");
								// add on second digit
								strcat(thousandValue, translations[savedDigit]);
							}
							eachDigit[e] = thousandValue;
						}
					}
					// go to next digit
					i /= 10;
			}

			int index = 0;
			// build together a string with spaces where necessary - may create unnecessary whitespace at end
			for (int f = nDigits-1; f >= 0; f--) {
				// if zero, then don't print i.e. not trente zero but trente (strcmp returns 0 if true) (same for "")
				if (strcmp(eachDigit[f], "zero")) {
					if (strcmp(eachDigit[f], "")) {
						strcat(finalAnswer, eachDigit[f]);
						strcat(finalAnswer, " ");
					}
				}
			}

			// remove uneccessary whitespace at end of string
			trim(finalAnswer);
			finalAnswer[strlen(finalAnswer)] = '\0';
			// copy final string into buffer to return to caller
			strcpy(buff, finalAnswer);
		}
	}
}

// returns month translation in a buffer array
void months(char* month, char* buff) {
	if(strcmp(month, "january")==0) {
		strcpy(buff, "janvier");
	}
	else if(strcmp(month, "february")==0) {
		strcpy(buff, "fevrier");
	}
	else if(strcmp(month, "march")==0) {
		strcpy(buff, "mars");
	}
	else if(strcmp(month, "april")==0) {
		strcpy(buff, "avril");
	}
	else if(strcmp(month, "may")==0) {
		strcpy(buff, "mai");
	}
	else if(strcmp(month, "june")==0) {
		strcpy(buff, "juin");
	}
	else if(strcmp(month, "july")==0) {
		strcpy(buff, "juillet");
	}
	else if(strcmp(month, "august")==0) {
		strcpy(buff, "aout");
	}
	else if(strcmp(month, "september")==0) {
		strcpy(buff, "septembre");
	}
	else if(strcmp(month, "october")==0) {
		strcpy(buff, "octobre");
	}
	else if(strcmp(month, "november")==0) {
		strcpy(buff, "novembre");
	}
	else if(strcmp(month, "december")==0) {
		strcpy(buff, "decembre");

	}
	else {
		printf("That is not a valid month.");
	}
}

// returns colours translation is a buffer array
void colours(char* colour, char* buff) {
	if(strcmp(colour, "red")==0) {
		strcpy(buff, "rouge");
	}
	else if(strcmp(colour, "blue")==0) {
		strcpy(buff, "bleu");
	}
	else if(strcmp(colour, "green")==0) {
		strcpy(buff, "vert");
	}
	else if(strcmp(colour, "yellow")==0) {
		strcpy(buff, "jaune");
	}
	else if(strcmp(colour, "white")==0) {
		strcpy(buff, "blanc");
	}
	else if(strcmp(colour, "black")==0) {
		strcpy(buff, "noir");
	}
	else if(strcmp(colour, "grey")==0) {
		strcpy(buff, "gris");
	}
	else if(strcmp(colour, "orange")==0) {
		strcpy(buff, "orange");
	}
	else if(strcmp(colour, "brown")==0) {
		strcpy(buff, "marron");
	}
	else if(strcmp(colour, "pink")==0) {
		strcpy(buff, "rose");
	}
	else if(strcmp(colour, "blonde")==0) {
		strcpy(buff, "blond");
	}
	else if(strcmp(colour, "purple")==0) {
		strcpy(buff, "violet");
	}
	else {
		printf("We do not have any translation for that colour, sorry.");
	}

}

// checks if question has already been asked
int questionAlreadyAsked(int val, int *arr, int size){
  for (int i = 0; i < size; i++) {
    if (arr[i] == val) {
      return 1;
		}
  }
  return 0;
}

// initialises array to -1's so can can use 0 index question
void initialiseArray(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = -1;
	}
}

void coloursTest() {
	int score = 0;
	int numQuestions = 0;
	// array so can use random number to choose index and therefore a random question
	char englishColours[12][10] = {"red", "blue", "green", "yellow", "white", "black", "grey", "orange", "brown", "pink", "blonde", "purple"};

	printf("How many questions would you like?\n");
	scanf("%d", &numQuestions);
	printf("\n");

	if (numQuestions < 0) {
		printf("\nYou can't choose less than 0 questions.\n");
		return;
	} else if(numQuestions > 12) {
		printf("\nThere are only 12 colours to test you on. Please pick a number below this.\n");
		return;
	}

	/* skip first fgets - newline in stdin from scanfs but fflush(stdin) not working
	, so first fgets always skips in for loop - would replace all scanfs with fgets
	but too lazy atm so just skip this fgets outside loop*/
	char *colour = malloc (15);
	fgets(colour, 15, stdin);
	free(colour);

	// array to hold questions already asked to avoid duplicate questions
	int questionsAsked[numQuestions];

	// so able to use 0 index question - array is currently initialised with 0's
	initialiseArray(questionsAsked, numQuestions);

	// set random to always randomized even when currently processing - without this
	// random will always be the same numbers whenever program is re-run
	srand(time(NULL));

	// ask questions
	for (int i = 0; i < numQuestions; i++) {
		char buffer[15] = "";

		// generate random number to test - make sure questions already hasn't been asked
		int randColour = rand() % 12;
		while (questionAlreadyAsked(randColour, questionsAsked, numQuestions)) {
			randColour = rand() % 12;
		}
		// add question to already asked array
		questionsAsked[i] = randColour;
		printf("\nWhat is ");
		printf("%s", englishColours[randColour]);
		printf(" in French?\n");

		char *colour = malloc (15);
		// get the month, with size limit.
		fgets(colour, 15, stdin);

		// Remove trailing newline, if there. //
		if ((strlen(colour)>0) && (colour[strlen (colour) - 1] == '\n'))
		colour[strlen (colour) - 1] = '\0';

		// use english month to find translation into french and put in buffer
		colours(englishColours[randColour], buffer);

		// check correct answer and input answer
		if (strcmp(colour, buffer)==0) {
			printf("That's correct!\n");
			score++;
		} else {
			printf("That's incorrect! The correct answer is: ");
			printf("%s", buffer);
			printf("\n");
		}

		// reset buffer by clearing it
		memset(&buffer[0], 0, sizeof(buffer));
	}

	printf("The test is over. You scored %d out of %d!\n", score, numQuestions);
}

void monthsTest() {
	int score = 0;
	int numQuestions = 0;
	// array so can use random number to choose index and therefore a random question
	char englishMonths[12][15] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

	printf("How many questions would you like?\n");
	scanf("%d", &numQuestions);
	printf("\n");

	if (numQuestions < 0) {
		printf("\nYou can't choose less than 0 questions.\n");
		return;
	} else if(numQuestions > 12) {
		printf("\nThere are only 12 months to test you on. Please pick a number below this.\n");
		return;
	}

	/* skip first fgets - newline in stdin from scanfs but fflush(stdin) not working
	, so first fgets always skips in for loop - would replace all scanfs with fgets
	but too lazy atm so just skip this fgets outside loop*/
	char *month = malloc (15);
	fgets(month, 15, stdin);
	free(month);

	// array to hold questions already asked to avoid duplicate questions
	int questionsAsked[numQuestions];

	// so able to use 0 index question - array is currently initialised with 0's
	initialiseArray(questionsAsked, numQuestions);

	// set random to always randomized even when currently processing - without this
	// random will always be the same numbers whenever program is re-run
	srand(time(NULL));

	// ask questions
	for (int i = 0; i < numQuestions; i++) {
		char buffer[15] = "";

		// generate random month to test
		int randMonth = rand() % 12;
		while (questionAlreadyAsked(randMonth, questionsAsked, numQuestions)) {
			randMonth = rand() % 12;
		}
		// add question to already asked array
		questionsAsked[i] = randMonth;
		printf("\nWhat is ");
		printf("%s", englishMonths[randMonth]);
		printf(" in French?\n");

		char *month = malloc (15);
		// get the month, with size limit.
		fgets(month, 15, stdin);

		// Remove trailing newline, if there. //
		if ((strlen(month)>0) && (month[strlen (month) - 1] == '\n'))
		month[strlen (month) - 1] = '\0';

		// use english month to find translation into french and put in buffer
		months(englishMonths[randMonth], buffer);

		// check correct answer and input answer
		if (strcmp(month, buffer)==0) {
			printf("That's correct!\n");
			score++;
		} else {
			printf("That's incorrect! The correct answer is: ");
			printf("%s", buffer);
			printf("\n");
		}

		// reset buffer by clearing it
		memset(&buffer[0], 0, sizeof(buffer));
	}

	printf("The test is over. You scored %d out of %d!\n", score, numQuestions);

}

void numbersTest() {
	int score = 0;
	int numQuestions = 0;

	printf("How many questions would you like?\n");
	scanf("%d", &numQuestions);
	printf("\n");

	if (numQuestions < 0) {
		printf("\nYou can't choose less than 0 questions.\n");
		return;
	}

	// set random to always randomized even when currently processing - without this
	// random will always be the same numbers whenever program is re-run
	srand(time(NULL));

	/* skip first fgets - newline in stdin from scanfs but fflush(stdin) not working
	, so first fgets always skips in for loop - would replace all scanfs with fgets
	but too lazy atm so just skip this fgets outside loop*/
	char *number = malloc (100);
	fgets(number, 100, stdin);
	free(number);

	// array to hold questions already asked to avoid duplicate questions
	int questionsAsked[numQuestions];

	// so able to use 0 index question - array is currently initialised with 0's
	initialiseArray(questionsAsked, numQuestions);

	// ask questions
	for (int i = 0; i < numQuestions; i++) {
		char buffer[50] = "";

		// generate random number to test
		int randNum = rand() % MAX_NUMBER_FOR_TESTS;
		while (questionAlreadyAsked(randNum, questionsAsked, numQuestions)) {
			randNum = rand() % MAX_NUMBER_FOR_TESTS;
		}
		// add question to already asked array
		questionsAsked[i] = randNum;
		printf("\nWhat is ");
		printf("%d", randNum);
		printf(" in French?\n");

		char *number = malloc (100);
		// get the number, with size limit.
	  fgets(number, 100, stdin);

		// Remove trailing newline, if there. //
 		if ((strlen(number)>0) && (number[strlen (number) - 1] == '\n'))
		number[strlen (number) - 1] = '\0';

		// get correct answer by putting into buffer
		numbers(randNum, buffer);
		// check correct answer and input answer
		if (strcmp(number, buffer)==0) {
			printf("That's correct!\n");
			score++;
		} else {
			printf("That's incorrect! The correct answer is: ");
			printf("%s", buffer);
			printf("\n");
		}

		// reset buffer by clearing it
		memset(&buffer[0], 0, sizeof(buffer));
	}

	printf("The test is over. You scored %d out of %d!\n", score, numQuestions);
}

// turns all chars in array to uppercase
void upperCase(char a[]) {
	int i;
	for (i = 0; i < strlen(a); i++) {
		a[i] = toupper(a[i]);
	}
}

// prints number translation
void printNum() {
		int i;
		printf("Please enter a number: ");
		scanf("%d", &i);
		char buffer[50];
		numbers(i, buffer);
		printf("%s\n", buffer);
		memset(&buffer[0], 0, sizeof(buffer));
}

// prints month translation
void printMonth() {
	char buffer[15];
	char month[10];
	printf("Please enter a month: ");
	scanf("%s", month);
	months(month, buffer);
	printf("%s\n", buffer);
	memset(&buffer[0], 0, sizeof(buffer));
}

// prints colour translation
void printColour() {
	char buffer[15];
	char colour[10];
	printf("Please enter a colour: ");
	scanf("%s", colour);
	colours(colour, buffer);
	printf("%s\n", buffer);
	memset(&buffer[0], 0, sizeof(buffer));
}

// switchboard for choosing what translation to do and what test
void switchboard() {
	char choice[10];
	char yesno[3];
	int switchboardStillOpen = 1;

	// switchboard
	while(switchboardStillOpen) {
		printf("What would you like to know?\n- Numbers [numbers / n]\n- Months [months / m]\n- Colours [colours / n]\n- Quit [quit / q]\n");
		scanf("%s", choice);
		upperCase(choice);
		if(strcmp(choice, "NUMBERS")==0 || strcmp(choice, "N")==0) {
			int numCarryOn = 1;
			int i;
			while (numCarryOn) {
				printNum();
				printf("Do you want to know any more numbers? Y/N\n");
				scanf("%s", yesno);
				upperCase(yesno);
				if(strcmp(yesno, "YES")==0 || strcmp(yesno, "Y")==0) {
					numCarryOn = 1;
				} else {
					numCarryOn = 0;
					printf("Do you want to take a quick numbers test? Y/N\n");
					scanf("%s", yesno);
					upperCase(yesno);
					if(strcmp(yesno, "YES")==0 || strcmp(yesno, "Y")==0) {
						numbersTest();
					}
					printf("\nWould you like to go back to the switchboard?\n");
					scanf("%s", yesno);
					upperCase(yesno);
					if (strcmp(yesno, "NO")==0 || strcmp(yesno, "N")==0) {
						printf("\nThanks for using the French translation program.\n");
						switchboardStillOpen = 0;
					}
				}
			}
		}
		else if (strcmp(choice, "MONTHS")==0 || strcmp(choice, "M") == 0) {
			int monCarryOn = 1;
			while (monCarryOn) {
				printMonth();
				printf("Do you want to know any more months? Y/N\n");
				scanf("%s", yesno);
				upperCase(yesno);
				if (strcmp(yesno, "YES")== 0 || strcmp(yesno, "Y")==0) {
					monCarryOn = 1;
				} else {
					monCarryOn = 0;
					printf("Do you want to take a quick months test? Y/N\n");
					scanf("%s", yesno);
					upperCase(yesno);
					if (strcmp(yesno, "YES")== 0 || strcmp(yesno, "Y")==0) {
						monthsTest();
					}
					printf("\nWould you like to go back to the switchboard?\n");
					scanf("%s", yesno);
					upperCase(yesno);
					if (strcmp(yesno, "NO")==0 || strcmp(yesno, "N")==0) {
						printf("\nThanks for using the French translation program.\n");
						switchboardStillOpen = 0;
					}
				}
			}
		}
		else if (strcmp(choice, "COLOURS")==0 || strcmp(choice, "C")==0) {
			int colCarryOn = 1;
			while (colCarryOn) {
				printColour();
				printf("Do you want to know any more colours? Y/N\n");
				char yesno[3];
				scanf("%s", yesno);
				upperCase(yesno);
				if (strcmp(yesno, "YES")== 0 || strcmp(yesno, "Y")==0) {
					colCarryOn = 1;
				} else {
					colCarryOn = 0;
					printf("Do you want to take a quick colours test? Y/N\n");
					scanf("%s", yesno);
					upperCase(yesno);
					if (strcmp(yesno, "YES")== 0 || strcmp(yesno, "Y")==0) {
						coloursTest();
					}
					printf("\nWould you like to go back to the switchboard?\n");
					scanf("%s", yesno);
					upperCase(yesno);
					if (strcmp(yesno, "NO")==0 || strcmp(yesno, "N")==0) {
						printf("\nThanks for using the French translation program.\n");
						switchboardStillOpen = 0;
					}
				}
			}
		}
		else if (strcmp(choice, "QUIT")==0 || strcmp(choice, "Q")==0) {
			printf("\nThanks for using the French translaiton program.\n");
			exit(0);
		}
		else {
			printf("You have not chosen a category.\n");
		}
	}
}

int main() {

	// calls switchboard
	switchboard();

	// ends program successfully
	return 0;
}
