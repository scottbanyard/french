// french verb program - practising verb endings, especially common irregular verbs
// scott banyard 08/10/15

#include <stdio.h>
#include <string.h>

// allows me to use string as char[]
typedef char * string;

// declaring function so can use it in regularVerbs()
void verbInfo(string, string, string, string, string, string, string);

void regularVerbs() {
	char choice[8];
	string list[3];
	list[0] = "parl(er)";
	list[1] = "chois(ir)";
	list[2] = "vend(re)";

	printf("The endings for each verb will be the same for -er, -ir and -re with irregular verbs being an exception\n\n");
	printf("What regular verb ending would you like to look at?\n");

	for (int i = 0; i < 3; i++) {
		printf("%s, ", list[i]);
	}
	printf("\n\n");

	printf("Type in the verb for more information: \n");
	scanf("%s", choice);

	// switchboard for each verb ending
	if(strcmp(choice, "parler")==0) {
		verbInfo("to speak", "parl(e)", "parl(es)", "parl(e)", "parl(ons)", "parl(ez)", "parl(ent)");
	}

	if(strcmp(choice, "choisir")==0) {
		verbInfo("to choose", "chois(is)", "chois(is)", "chois(it)", "chois(issons)", "chois(issez)", "chois(issent)");
	}

	if(strcmp(choice, "vendre")==0) {
		verbInfo("to sell", "vend(s)", "vend(s)", "vend()", "vend(ons)", "vend(ez)", "vend(ent)");
	}
}

void irregularVerbs() {
	char choice[8];
	string list[4];
	list[0] = "être";
	list[1] = "avoir";
	list[2] = "aller";
	list[3] = "faire";

	printf("What irregular verb would you like to look at?\n");

	printf("\n");
	// prints out list of irregular verbs
	for (int i = 0; i < 4; i++) {
		printf("%s, ", list[i]);
	}
	printf("\n\n");

	printf("Type in a verb from the list for more information: \n");
	scanf("%s", choice);

	// switchboard for each word
	if(strcmp(choice, "etre")==0) {
		verbInfo("to be", "suis", "es", "est", "sommes", "êtes", "sont");
	}

	if(strcmp(choice, "avoir")==0) {
		verbInfo("to have", "ai", "as", "a", "avons", "avez", "ont");
	}

	if(strcmp(choice, "aller")==0) {
		verbInfo("to go", "vais", "vas", "va", "allons", "avez", "vont");
	}

	if(strcmp(choice, "faire")==0) {
		verbInfo("to do", "fais", "fais", "fait", "faisons", "faites", "font");
	}
}

// function which templates the verb table
void verbInfo(string translation, string je, string tu, string il, string nous, string vous, string ils) {
	// can't use avoir with je as need j'ai so created an if for the exception
	if (strcmp(je, "ai")==0) {
		printf("The translation for this verb is:\n'%s'\n\n", translation);
		printf("j'%s\ntu %s\nil/elle/on %s\nnous %s\nvous %s\nils/elles %s\n\n", je, tu, il, nous, vous, ils);
		} else {
		printf("\nThe translation for this verb is:\n'%s'\n\n", translation);
		printf("je %s\ntu %s\nil/elle/on %s\nnous %s\nvous %s\nils/elles %s\n\n", je, tu, il, nous, vous, ils);
	}
}

int main(void) {
	char choice[10];

	printf("Would you like to look at regular or irregular verbs?\n");
	scanf("%s", choice);

	if(strcmp(choice, "regular")==0) {
		regularVerbs();
	}
	else if(strcmp(choice, "irregular")==0) {
		irregularVerbs();
	}
	return 0;
}