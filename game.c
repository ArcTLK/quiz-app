#include "game.h"

void play() {
	FILE *file;
	char question[200];
	char answer[200];
	char input[200];
	int points = 0;
	char name[100];
	char *pos;
	int i;
	printf("Enter your name:\t");
	scanf("%[^\n]", name);
	//clean input buffer
    while ((i = getchar()) != '\n' && i != EOF);

	file = fopen("questions.txt", "r");
	while(fgets(question, sizeof(question), file) != NULL) {
        fgets(answer, sizeof(answer), file);
        // print question
        printf("Question:\t%sEnter your answer:\t", question);
        scanf("%[^\n]", input);
		//clean input buffer
	    while ((i = getchar()) != '\n' && i != EOF);
	    // strip \n
	    if ((pos = strchr(answer, '\n')) != NULL) {
	    	*pos = '\0';
	    }
	    if (strcmp(input, answer) == 0) {
	    	points += 1;
	    }
    }
    printf("You scored %d points!", points);
	fclose(file);
	// save score
	file = fopen("scores.txt", "a");
	fprintf(file, "%s\t%d\n", name, points);
	fclose(file);
}

void launchGameCreationSequence() {
	char question[200];
	char answer[200];
	char option;
	int i;
	FILE *file;
	// open file
	file = fopen("questions.txt", "a");
	while(1) {
		printf("Enter the question:\n");
		scanf("%[^\n]", question);
		//clean input buffer
        while ((i = getchar()) != '\n' && i != EOF);

		printf("Enter the answer:\n");
		scanf("%[^\n]", answer);
		//clean input buffer
        while ((i = getchar()) != '\n' && i != EOF);

		// store it in the file
		fputs(question, file);
		fputs("\n", file);
		fputs(answer, file);
		fputs("\n", file);
		printf("Do you want to add another question? (Enter y if yes)");
		scanf("%c", &option);
		//clean input buffer
        while ((i = getchar()) != '\n' && i != EOF);
		if (option != 'y') {
			break;
		}
	}
	fclose(file);
}

void viewScores() {
	FILE *file;
	char data[100];
	file = fopen("scores.txt", "r");
	if (file == NULL) {
		printf("No scores recorded yet.");
	}
	else {
		while(fgets(data, sizeof(data), file) != NULL) {
        	fputs(data, stdout);
        	fputs("\n", stdout);
     	}
	}
	fclose(file);
}