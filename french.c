// scott banyard 2015
// very basic french program that translates numbers, months and colours with little tests - created to recap C and to recap basic french

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// declaring functions
void colourstest();
void numberstest();
void monthstest();
void upperCase(char a[]);
char toupper();

// translations from 0-19
char *translations[22] = {"zero", "un", "deux", "trois", "quatre", "cinq", "six", "sept",
										"huit", "neuf", "dix", "onze", "douze", "treize", "quatorze",
										"quinze", "seize", "dix-sept", "dix-huit", "dix-neuf"};
// translations for 10, 20, 30...
char *multiples[13] = {"", "dix", "vingt", "trente", "quarante", "cinquante", "soixante", "soixante-dix",
										"quatre-vingt", "quatre-vingt-dix", "cent"};

void numbers() {
	int i;
	printf("Please enter a number: ");
	scanf("%d", &i);
	char answer[15];
	if (i >= 0 && i <= 19) {
		strcpy(answer, translations[i]);
		printf("%s", answer);
	} else {
		// get number length (number of digits)
		int nDigits = floor(log10(abs(i))) + 1;
		char* eachDigit[nDigits];
		int k;
		// put each digit into an array
			for (int e = 0; e < nDigits; e++) {
			k = i % 10;
			// first digit, get string in array
			if (e == 0) {
				eachDigit[e] = translations[k];
			// second digit will be a multiple
			} else if (e == 1) {
				eachDigit[e] = multiples[k];
			}
			i /= 10;
		}

		// print out answer i.e. 22 = 20 + 2 = vingt + deux
		for (int f = nDigits-1; f >= 0; f--) {
			// if zero, then don't print i.e. not trente zero but trente
			if (strcmp(eachDigit[f], "zero")) {
				printf("%s", eachDigit[f]);
				printf(" ");
			}
		}
		printf("\n");
	}
}

void months() {
	char month[10];
	printf("Please enter a month: ");
	scanf("%s", month);

	if(strcmp(month, "january")==0) {
		printf("janvier\n");
	}
	else if(strcmp(month, "february")==0) {
		printf("fevrier\n");
	}
	else if(strcmp(month, "march")==0) {
		printf("mars\n");
	}
	else if(strcmp(month, "april")==0) {
		printf("avril\n");
	}
	else if(strcmp(month, "may")==0) {
		printf("mai\n");
	}
	else if(strcmp(month, "june")==0) {
		printf("juin\n");
	}
	else if(strcmp(month, "july")==0) {
		printf("juillet\n");
	}
	else if(strcmp(month, "august")==0) {
		printf("aout\n");
	}
	else if(strcmp(month, "september")==0) {
		printf("septembre\n");
	}
	else if(strcmp(month, "october")==0) {
		printf("octobre\n");
	}
	else if(strcmp(month, "november")==0) {
		printf("novembre\n");
	}
	else if(strcmp(month, "december")==0) {
		printf("decembre\n");
	}
	else {
		printf("That is not a valid month.");
	}
}

void colours() {
	char colour[10];
	printf("Please enter a colour: ");
	scanf("%s", colour);

	if(strcmp(colour, "red")==0) {
		printf("rouge\n");
	}
	else if(strcmp(colour, "blue")==0) {
		printf("bleu\n");
	}
	else if(strcmp(colour, "green")==0) {
		printf("vert\n");
	}
	else if(strcmp(colour, "yellow")==0) {
		printf("jaune\n");
	}
	else if(strcmp(colour, "white")==0) {
		printf("blanc\n");
	}
	else if(strcmp(colour, "black")==0) {
		printf("noir\n");
	}
	else if(strcmp(colour, "grey")==0) {
		printf("gris\n");
	}
	else if(strcmp(colour, "orange")==0) {
		printf("orange\n");
	}
	else if(strcmp(colour, "brown")==0) {
		printf("brun or marron\n");
	}
	else if(strcmp(colour, "pink")==0) {
		printf("rose\n");
	}
	else if(strcmp(colour, "blonde")==0) {
		printf("blond\n");
	}
	else if(strcmp(colour, "purple")==0) {
		printf("violet\n");
	}
	else {
		printf("That is not a valid colour.");
	}

}

void colourstest() {
	int score = 0;
	char colour[10];

	// q1
	printf("What is 'blue' in French?\n");
	scanf("%s", colour);
	if (strcmp(colour, "bleu")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'bleu'.\n");
	}

	// q2
	printf("What is 'green' in French?\n");
	scanf("%s", colour);
	if (strcmp(colour, "vert")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'vert'.\n");
	}

	// q3
	printf("What is 'black' in French?\n");
	scanf("%s", colour);
	if (strcmp(colour, "noir")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'noir'.\n");
	}

	// q4
	printf("What is 'purple' in French?\n");
	scanf("%s", colour);
	if (strcmp(colour, "violet")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'violet'.\n");
	}

	// q5
	printf("What is 'white' in French?\n");
	scanf("%s", colour);
	if (strcmp(colour, "blanc")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'blanc'.\n");
	}

	// result
	printf("The test is over. You scored %d out of 5!\n", score);
}

void monthstest() {
	int score = 0;
	char month[10];

	// q1
	printf("What is 'february' in French?\n");
	scanf("%s", month);
	if (strcmp(month, "fevrier")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'fevrier'.\n");
	}

	// q2
	printf("What is 'march' in French?\n");
	scanf("%s", month);
	if (strcmp(month, "mars")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'mars'.\n");
	}

	// q3
	printf("What is 'november' in French?\n");
	scanf("%s", month);
	if (strcmp(month, "novembre")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'novembre'.\n");
	}

	// q4
	printf("What is 'august' in French?\n");
	scanf("%s", month);
	if (strcmp(month, "aout")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'aout'.\n");
	}

	// q5
	printf("What is 'may' in French?\n");
	scanf("%s", month);
	if (strcmp(month, "mai")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'mai'.\n");
	}

	// result
	printf("The test is over. You scored %d out of 5!\n", score);
}

void numberstest() {
	int score = 0;
	char number[15];

	// q1
	printf("What is '15' in French?\n");
	scanf("%s", number);
	if(strcmp(number, "quinze")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'quinze'.\n");
	}

	// q2
	printf("What is '21' in French?\n");
	scanf("%s", number);
	if(strcmp(number, "vingt un")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'vingt-et-un'.\n");
	}

	// q3
	printf("What is '30' in French?\n");
	scanf("%s", number);
	if(strcmp(number, "trente")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'trente'.\n");
	}

	// q4
	printf("What is '100' in French?\n");
	scanf("%s", number);
	if(strcmp(number, "cent")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'cent'.\n");
	}

	// q5
	printf("What is '80' in French?\n");
	scanf("%s", number);
	if(strcmp(number, "quatre-vingt")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'quatre-vingt'.\n");
	}

	// q6
	printf("What is '90' in French?\n");
	scanf("%s", number);
	if(strcmp(number, "quatre-vingt-dix")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'quatre-vingt-dix'.\n");
	}

	// q7
	printf("What is '50' in French?\n");
	scanf("%s", number);
	if(strcmp(number, "cinquante")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'cinquante'.\n");
	}

	// q8
	printf("What is '65' in French?\n");
	scanf("%s", number);
	if(strcmp(number, "soixante cinq")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'soixante-cinq'.\n");
	}

	// result
	printf("The test is over. You scored %d out of 8!\n", score);
}

void upperCase(char a[]) {
	int i;
	for (i = 0; i < strlen(a); i++) {
		a[i] = toupper(a[i]);
	}
}

int main() {

	char choice[10];

	// switchboard
	printf("What would you like to know? Numbers, months or colours?\n");
	scanf("%s", choice);
	upperCase(choice);
	if(strcmp(choice, "NUMBERS")==0 || strcmp(choice, "N")==0) {
		int numCarryOn = 1;
		while (numCarryOn) {
			numbers();
			printf("Do you want to know any more numbers?\n");
			char yesno[3];
			scanf("%s", yesno);
			upperCase(yesno);
			if(strcmp(yesno, "YES")==0 || strcmp(yesno, "Y")==0) {
				numCarryOn = 1;
			} else {
				numCarryOn = 0;
				printf("Do you want to take a quick numbers test?\n");
				scanf("%s", yesno);
				upperCase(yesno);
				if(strcmp(yesno, "YES")==0 || strcmp(yesno, "Y")==0) {
					numberstest();
				}
			}
		}
	}
	else if (strcmp(choice, "MONTHS")==0 || strcmp(choice, "M") == 0) {
		int monCarryOn = 1;
		while (monCarryOn) {
			months();
			printf("Do you want to know any more months?\n");
			char yesno[3];
			scanf("%s", yesno);
			upperCase(yesno);
			if (strcmp(yesno, "YES")== 0 || strcmp(yesno, "Y")==0) {
				monCarryOn = 1;
			} else {
				monCarryOn = 0;
				printf("Do you want to take a quick months test?\n");
				scanf("%s", yesno);
				upperCase(yesno);
				if (strcmp(yesno, "YES")== 0 || strcmp(yesno, "Y")==0) {
					monthstest();
				}
			}
		}
	}
	else if (strcmp(choice, "COLOURS")==0 || strcmp(choice, "C")==0) {
		int colCarryOn = 1;
		while (colCarryOn) {
			colours();
			printf("Do you want to know any more colours?\n");
			char yesno[3];
			scanf("%s", yesno);
			upperCase(yesno);
			if (strcmp(yesno, "YES")== 0 || strcmp(yesno, "Y")==0) {
				colCarryOn = 1;
			} else {
				colCarryOn = 0;
				printf("Do you want to take a quick colours test?\n");
				scanf("%s", yesno);
				upperCase(yesno);
				if (strcmp(yesno, "YES")== 0 || strcmp(yesno, "Y")==0) {
					colourstest();
				}
			}
		}
	}
	else {
		printf("You have not chosen a category.\n");
	}

	// ends program successfully
	return 0;
}
