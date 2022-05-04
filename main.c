#include "header.h"

void getActionsFromUser(Manager* manager);

void main() {
	unsigned char flag;
	Manager manager;
	resetManager(&manager);

	flag = createListFromTable(&manager);
	
	if (flag) {
	printAll(&manager);
	getActionsFromUser(&manager);
	}
	
	else
	{
		printf("Error getting data from file!");
		exit(fileEmptyErorr);
	}
}

void getActionsFromUser(Manager* manager) {
	char input[MAXLINE];
	while (TRUE) {
		printf("\n\n->  ");
		fgets(input, MAXLINE-1, stdin);
		input[strlen(input) - 1] = '\0';

		cleanSpaces(input);
		toLowerCase(input);

		if (strcmp(input, "quit") == 0)
			quit(manager);
		else if (strcmp(input, "print") == 0)
			printAll(manager);
		else if (strncmp(input, "set", 3) == 0)
			setCommand(manager, input + 3);
		else if (strncmp(input, "select", 6) == 0)
			selectCommand(manager, input + 6);
		else if (strcmp(input, "log") == 0)
			printLog();
		else if (strcmp(input, "help") == 0)
			printHelp();
		else {
			printf("The command is invalid!\n");
			printHelp();
		}
	}
}