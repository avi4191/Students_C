#include "header.h"

Student* findById(Manager* manager, char* id) {
	Student* ptr = manager->head;
	while (ptr != NULL)
	{
		if (strcmp(id, ptr->id) == 0)
			return ptr;
		ptr = ptr->next;
	}
	return NULL;
}

void printHeader() {
	printf("==================================================================================================================================\n");
	printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n", "ID", "First Name", "Last Name", "C Language", "Computer Networks", "CS Fundamentals", "Average");
	printf("==================================================================================================================================\n");
}

void printStudent(Student* student) {
	printf("%-20s%-20s%-20s",
		student->id, student->firstName, student->lastName);
	for (int i = 0; i < 3; i++)
	{
		if (student->grades[i] != -1)
			printf("%-20d", student->grades[i]);
		else
			printf("%-20s", " ");
	}
	if (student->average != -1)
		printf("%-7.1f \n", student->average);
	else
		printf("%-20s", " ");

	printf("----------------------------------------------------------------------------------------------------------------------------------\n");
}

void printAll(Manager* manager) {
	Student* ptr = manager->head;
	int lines = 0;
	printHeader();
	while (ptr != NULL)
	{
		printStudent(ptr);
		lines++;
		ptr = ptr->next;
	}
	printf("%d items\n", lines);
}

void toLowerCase(char* str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		if (str[i] < 91 && str[i]>64)
			str[i] += 32;
}

void cleanSpaces(char* str) {
	int len = strlen(str), i, j;
	for (i = 0, j = 0; i < len; i++)
		if (str[i] != 32)
			str[j++] = str[i];
	str[j] = '\0';
}

int getOperator(char* str) {
	if (str[0] == '=')
		return 1;
	if (str[0] == '>')
		if (str[1] == '=')
			return 4;
		else
			return 2;
	if (str[0] == '<')
		if (str[1] == '=')
			return 5;
		else
			return 3;
	if (str[0] == '!' && str[1] == '=')
		return 6;
	return 0;
}

unsigned char getCodeByKey(char* str) {
	if (strcmp(str, "firstname") == 0)
		return 0;
	if (strcmp(str, "lastname") == 0)
		return 1;
	if (strcmp(str, "id") == 0)
		return 2;
	if (strcmp(str, COURSE1) == 0)
		return 3;
	if (strcmp(str, COURSE2) == 0)
		return 4;
	if (strcmp(str, COURSE3) == 0)
		return 5;
	if (strcmp(str, "average") == 0)
		return 6;
	return -1;
}

void printLog() {
	FILE* file = fopen("log.txt", "rt");
	checkFile(file);
	char c = fgetc(file);
	printf("\n");
	while (c != EOF) {
		printf("%c", c);
		c = fgetc(file);
	}
	fclose(file);
}

void printHelp() {
	FILE* file = fopen("help.txt", "rt");
	checkFile(file);
	char c = fgetc(file);
	printf("\n");
	while (c != EOF) {
		printf("%c", c);
		c = fgetc(file);
	}
	fclose(file);
}

