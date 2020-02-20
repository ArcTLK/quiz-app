#include "game.h"

int main() {
	char option;
	while(1) {
		system("cls");
		printf("Select an option:\n");
		printf("1) Play\n2) Create\n3) Scores\n4) Exit\n\n");
		option = getch();
		// load game
		if (option == '1') {
			play();
			getch();
		}
		// create game
		else if (option == '2') {
			launchGameCreationSequence();
		}
		// view scores
		else if (option == '3') {
			viewScores();
			getch();
		}
		// exit
		else if (option == '4') {
			break;
		}
		else {
			printf("You seem to have entered an invalid option!");
			getch();
		}
	}
	printf("Exiting! Thanks for playing :)");
	getch();
	return 0;
}