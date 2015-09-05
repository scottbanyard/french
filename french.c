#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int numbers() {
	int i;
	printf("Please enter a number: ");
	scanf("%d", &i);

	switch(i) {
	case 0:
		printf("zero\n");
	case 1:
		printf("un\n");
		break;
	case 2:
		printf("deux\n");
		break;
	case 3:
		printf("trois\n");
		break;
	case 4:
		printf("quatre\n");
		break;	
	case 5:
		printf("cinq\n");
		break;
	case 6:
		printf("six\n");
		break;
	case 7:
		printf("sept\n");
		break;	
	case 8:
		printf("huit\n");
		break;
	case 9:
		printf("neuf\n");
		break;
	case 10:
		printf("dix\n");
		break;
	case 11:
		printf("onze\n");
		break;
	case 12:
		printf("douze\n");	
		break;
	case 13:
		printf("treize\n");
		break;
	case 14:
		printf("quatorze\n");
		break;
	case 15:
		printf("quinze\n");
		break;
	case 16:
		printf("seize\n");
		break;
	case 17:
		printf("dix-sept\n");
		break;
	case 18:
		printf("dix-huit\n");
		break;
	case 19:
		printf("dix-neuf\n");
		break;
	case 20:
		printf("vingt\n");
		break;		
	case 21:
		printf("vingt-et-un\n");
		break;
	case 30:
		printf("trente\n");
		break;
	case 40:
		printf("quarante\n");
		break;
	case 50:
		printf("cinquante\n");
		break;
	case 60:
		printf("soixante\n");
		break;
	case 70:
		printf("soixante-dix\n");
		break;
	case 80:
		printf("quatre-vingt\n");
		break;
	case 90:
		printf("quatre-vingt-dix\n");
		break;
	case 100:
		printf("cent\n");
		break;
	case 101:
		printf("cent-un\n");
		break;
	case 1000:
		printf("mille\n");	
		break;														
	}	

	// able to repeat function
	printf("Do you want to know any more numbers?\n");
	char yesno[2];
	scanf("%s", &yesno);
	if(strcmp(yesno, "yes")==0) {
		numbers();
	}

	// starts test
	printf("Would you like to take a quick test?\n");
	scanf("%s", &yesno);
	if(strcmp(yesno, "yes")==0){
		numberstest();
	}

	// ends function
	return 0;
}

int months() {
	char month[10];
	printf("Please enter a month: ");
	scanf("%s", &month);
		
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
	if(strcmp(month, "june")==0) {
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

	// able to repeat function
	printf("Do you want to know any more months?\n");
	char yesno[2];
	scanf("%s", &yesno);
	if(strcmp(yesno, "yes")==0) {
		months();
	}

	// starts test
	printf("Would you like to take a quick test?\n");
	scanf("%s", &yesno);
	if(strcmp(yesno, "yes")==0){
		monthstest();
	}

	// ends function
	return 0;
}

int colours() {
	char colour[10];
	printf("Please enter a colour: ");
	scanf("%s", &colour);

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

	// able to repeat function
	printf("Do you want to know any more colours?\n");
	char yesno[2];
	scanf("%s", &yesno);
	if(strcmp(yesno, "yes")==0) {
		colours();
	}

	// starts test
	printf("Would you like to take a quick test?\n");
	scanf("%s", &yesno);
	if(strcmp(yesno, "yes")==0){
		colourstest();
	}

	// ends function
	return 0;
}

int colourstest() {
	int score = 0;
	char colour[10];

	// q1
	printf("What is 'blue' in French?\n");
	scanf("%s", &colour);
	if (strcmp(colour, "bleu")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'bleu'.\n");
	}

	// q2
	printf("What is 'green' in French?\n");
	scanf("%s", &colour);
	if (strcmp(colour, "vert")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'vert'.\n");
	}

	// q3
	printf("What is 'black' in French?\n");
	scanf("%s", &colour);
	if (strcmp(colour, "noir")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'noir'.\n");
	}

	// q4
	printf("What is 'purple' in French?\n");
	scanf("%s", &colour);
	if (strcmp(colour, "violet")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'violet'.\n");
	}

	// q5
	printf("What is 'white' in French?\n");
	scanf("%s", &colour);
	if (strcmp(colour, "blanc")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'blanc'.\n");
	}

	// result
	printf("The test is over. You scored %d out of 5!\n", score);

	// ends function
	return 0;
}

int monthstest() {
	int score = 0;
	char month[10];

	// q1
	printf("What is 'february' in French?\n");
	scanf("%s", &month);
	if (strcmp(month, "fevrier")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'fevrier'.\n");
	}

	// q2
	printf("What is 'march' in French?\n");
	scanf("%s", &month);
	if (strcmp(month, "mars")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'mars'.\n");
	}

	// q3
	printf("What is 'november' in French?\n");
	scanf("%s", &month);
	if (strcmp(month, "novembre")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'novembre'.\n");
	}

	// q4
	printf("What is 'august' in French?\n");
	scanf("%s", &month);
	if (strcmp(month, "aout")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'aout'.\n");
	}

	// q5
	printf("What is 'may' in French?\n");
	scanf("%s", &month);
	if (strcmp(month, "mai")==0) {
		printf("That's correct!\n");
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'mai'.\n");
	}

	// result
	printf("The test is over. You scored %d out of 5!\n", score);

	// ends function
	return 0;
}

int numberstest() {
	int score = 0;
	char number[15];

	// q1
	printf("What is '15' in French?\n");
	scanf("%s", &number);
	if(strcmp(number, "quinze")==0) {
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'quinze'.\n");
	}

	// q2
	printf("What is '21' in French?\n");
	scanf("%s", &number);
	if(strcmp(number, "vingt-et-un")==0) {
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'vingt-et-un'.\n");
	}

	// q3
	printf("What is '30' in French?\n");
	scanf("%s", &number);
	if(strcmp(number, "trente")==0) {
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'trente'.\n");
	}

	// q4
	printf("What is '100' in French?\n");
	scanf("%s", &number);
	if(strcmp(number, "cent")==0) {
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'cent'.\n");
	}

	// q5
	printf("What is '80' in French?\n");
	scanf("%s", &number);
	if(strcmp(number, "quatre-vingt")==0) {
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'quatre-vingt'.\n");
	}

	// q6
	printf("What is '90' in French?\n");
	scanf("%s", &number);
	if(strcmp(number, "quatre-vingt-dix")==0) {
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'quatre-vingt-dix'.\n");
	}

	// q7
	printf("What is '50' in French?\n");
	scanf("%s", &number);
	if(strcmp(number, "cinquante")==0) {
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'cinquante'.\n");
	}

	// q8
	printf("What is '65' in French?\n");
	scanf("%s", &number);
	if(strcmp(number, "soixante-cinq")==0) {
		score++;
	} else {
		printf("That's incorrect, the correct answer is 'soixante-cinq'.\n");
	}

	// result
	printf("The test is over. You scored %d out of 8!\n", score);

	// ends function
	return 0;
}


int main() {

	char choice[10];

	// switchboard 
	printf("What would you like to know? Numbers, months or colours?\n");
	scanf("%s", &choice);

	if(strcmp(choice, "numbers")==0) {
		numbers();
	}
	else if (strcmp(choice, "months")==0) {
		months();
	}
	else if (strcmp(choice, "colours")==0) {
		colours();
	}
	else {
		printf("You have not chosen a category.\n");
	}

	// ends program successfully
	return 0;
}


