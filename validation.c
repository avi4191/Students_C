#include "header.h"

int isValidName(char* str) {
	int len = (int)strlen(str);
	for (int i = 0; i < len; i++)
		if (str[i] < 'A' || str[i] > 'z' || str[i] > 'Z' && str[i] < 'a')
			return 0;
	return 1;
}

int isValidGrade(char* grade) {
	int len = (int)strlen(grade);
	if (len < 2 || len > 4)
		return 0;
	for (int i = 0; i < len - 1; i++)
		if (grade[i] < '0' || grade[i] > '9')
			return 0;
	if (atoi(grade) < 0 || atoi(grade) > 100)
		return 0;
	return 1;
}

int isValidId(char* str) {
	int len = (int)strlen(str);
	if (len != 9)
		return 0;
	for (int i = 0; i < 9; i++)
		if (str[i] < '0' || str[i] > '9')
			return 0;
	return 1;
}

int getIdCourseByName(char* course) {
	if (strcmp(COURSE1, course) == 0)
		return 1;
	if (strcmp(COURSE2, course) == 0)
		return 2;
	if (strcmp(COURSE3, course) == 0)
		return 3;
	return 0;
}

void checkFile(FILE* file) {
	if (file == NULL) {
		printf("open file erorr!!!\n");
		exit(1);
	}
}

void checkAllocation(void* x, Manager *manager,void *ptrToFree1, void* ptrToFree2) {
	if (x == NULL) {
		printf("allocation erorr!!!\n");
		if (ptrToFree1 != NULL)
			free(ptrToFree1);
		if (ptrToFree2 != NULL)
			free(ptrToFree2);
		if (manager->changes > 0 || manager->isSortedFile == 0 || manager->fallenRows > 0)
			saveChanges(manager);
		freeMemory(manager);
		exit(2);
	}
}

void checkLongLine(char* line, FILE* file) {
	char c = 'a';
	int len = (int) strlen(line);
	if (line[len - 1] != '\n' && line[len - 1] != EOF)
		while (c != '\n' && c != EOF)
			c = fgetc(file);
}

void checkIsSortedFile(Manager* manager, FILE* file) {
	char str[7];
	fgets(str, 6, file);
	if (str[0] == '#')
		manager->isSortedFile = 1;
	else  rewind(file);
}

void logger(FILE* log, unsigned char* erorrs, char* line, int numOfLine) {
	fprintf(log, "Line %d:\n%s\n", numOfLine, line);
	if (erorrs[0] == 0)
		fprintf(log, "ERORR %d: first name is not valid.\n", 0);
	if (erorrs[1] == 0)
		fprintf(log, "ERORR %d: last name is not valid.\n", 1);
	if (erorrs[2] == 0)
		fprintf(log, "ERORR %d: id is not valid.\n", 2);
	if (erorrs[3] == 0)
		fprintf(log, "ERORR %d: course is not valid.\n", 3);
	if (erorrs[4] == 0)
		fprintf(log, "ERORR %d: grade is not valid.\n", 4);
	if (erorrs[5] == 0)
		fprintf(log, "ERORR %d: id is exist with first or last name other!.\n", 5);
	fprintf(log, "===================================\n");
}


