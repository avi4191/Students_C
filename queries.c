#include "header.h"


void selectCommand(Manager* manager, char* input) {
	char codeKey, * token, temp[50], op, len, val[50];
	if (strlen(input) > 99)
		printf("Invalid length query");
	strcpy(temp, input);

	token = strtok(temp, "<>=!");
	codeKey = getCodeByKey(token);
	len =(int) strlen(token);
	if (codeKey == -1)
		printf("\'%s\' is not valid property!", token);
	op = getOperator(input + len);
	if (op == 0)
		printf("Invalid operator!");
	if (op <= 3)
		strcpy(val, input + len + 1);
	else
		strcpy(val, input + len + 2);
	switch (codeKey)
	{  
	case 0:
		if (isValidName(val))
			printSelected(manager, &filterByFirstName, op, val);
		break;
	case 1:
		if (isValidName(val))
			printSelected(manager, &filterByLastName, op, val);
		break;
	case 2:
		if (isValidId(val))
			printSelected(manager, &filterByID, op, val);
		break;
	case 3:
		if (isValidGrade(val)) {
			val[0] = atoi(val);
			printSelected(manager, &filterByGrade1, op, val);
			break;
		}
	case 4:
		if (isValidGrade(val)) {
			val[0] = atoi(val);
			printSelected(manager, &filterByGrade2, op, val);
			break;
		}
	case 5:
		if (isValidGrade(val)) {
			val[0] = atoi(val);
			printSelected(manager, &filterByGrade3, op, val);
			break;
		}
	case 6:
		if (1) {
			float tempVal =(float) atof(val);
			printSelected(manager, &filterByAverage, op, &tempVal);
			break;
		}
		break;
	default:
		break;
	}
}

void printSelected(Manager* manager, int(*fn)(Student*, char, void*), char op, void* val) {
	Student* ptr = manager->head;
	int lines = 0;
	printHeader();
	while (ptr != NULL)
	{
		if ((*fn)(ptr, op, val)) {
			printStudent(ptr);
			lines++;
		}
		ptr = ptr->next;
	}
	if (lines)
		printf("\nsum = %d result", lines);
	else
		printf("no results found!");
}


int filterByFirstName(Student* student, char op, void* value) {
	char ret = 0, * val = (char*)value;
	switch (op)
	{
	case 1:
		if (strcmp(student->firstName, val) == 0)
			ret = 1;
		break;
	case 2:
		if (strcmp(student->firstName, val) > 0)
			return 1;
	case 3:
		if (strcmp(student->firstName, val) < 0)
			return 1;
	case 4:
		if (strcmp(student->firstName, val) >= 0)
			return 1;
	case 5:
		if (strcmp(student->firstName, val) <= 0)
			return 1;
	case 6:
		if (strcmp(student->firstName, val) != 0)
			return 1;
	}
	return ret;
}
int filterByLastName(Student* student, char op, void* value) {
	char ret = 0;
	switch (op)
	{
	case 1:
		if (strcmp(student->lastName, value) == 0)
			ret = 1;
		break;
	case 2:
		if (strcmp(student->lastName, value) > 0)
			ret = 1;
		break;
	case 3:
		if (strcmp(student->lastName, value) < 0)
			ret = 1;
		break;
	case 4:
		if (strcmp(student->lastName, value) >= 0)
			ret = 1;
		break;
	case 5:
		if (strcmp(student->lastName, value) <= 0)
			ret = 1;
		break;
	case 6:
		if (strcmp(student->lastName, value) != 0)
			ret = 1;
		break;
	}
	return ret;
}
int filterByID(Student* student, char op, void* value) {
	char ret = 0;
	switch (op)
	{
	case 1:
		if (strcmp(student->id, value) == 0)
			ret = 1;
		break;
	case 2:
		if (strcmp(student->id, value) > 0)
			ret = 1;
		break;
	case 3:
		if (strcmp(student->id, value) < 0)
			ret = 1;
		break;
	case 4:
		if (strcmp(student->id, value) >= 0)
			ret = 1;
		break;
	case 5:
		if (strcmp(student->id, value) <= 0)
			ret = 1;
		break;
	case 6:
		if (strcmp(student->id, value) != 0)
			ret = 1;
		break;
	}
	return ret;
}
int filterByGrade1(Student* student, char op, void* value) {
	char ret = 0, gradeIndex = 0;
	switch (op)
	{
	case 1:
		if (student->grades[gradeIndex] == *((char*)value))
			ret = 1;
		break;
	case 2:
		if (student->grades[gradeIndex] > *((char*)value))
			ret = 1;
		break;
	case 3:
		if (student->grades[gradeIndex] < *((char*)value))
			ret = 1;
		break;
	case 4:
		if (student->grades[gradeIndex] >= *((char*)value))
			ret = 1;
		break;
	case 5:
		if (student->grades[gradeIndex] <= *((char*)value))
			ret = 1;
		break;
	case 6:
		if (student->grades[gradeIndex] != *((char*)value))
			ret = 1;
		break;
	}
	return ret;
}
int filterByGrade2(Student* student, char op, void* value) {
	char ret = 0, gradeIndex = 1;
	switch (op)
	{
	case 1:
		if (student->grades[gradeIndex] == *((char*)value))
			ret = 1;
		break;
	case 2:
		if (student->grades[gradeIndex] > *((char*)value))
			ret = 1;
		break;
	case 3:
		if (student->grades[gradeIndex] < *((char*)value))
			ret = 1;
		break;
	case 4:
		if (student->grades[gradeIndex] >= *((char*)value))
			ret = 1;
		break;
	case 5:
		if (student->grades[gradeIndex] <= *((char*)value))
			ret = 1;
		break;
	case 6:
		if (student->grades[gradeIndex] != *((char*)value))
			ret = 1;
		break;
	}
	return ret;
}
int filterByGrade3(Student* student, char op, void* value) {
	char ret = 0, gradeIndex = 2;
	switch (op)
	{
	case 1:
		if (student->grades[gradeIndex] == *((char*)value))
			ret = 1;
		break;
	case 2:
		if (student->grades[gradeIndex] > *((char*)value))
			ret = 1;
		break;
	case 3:
		if (student->grades[gradeIndex] < *((char*)value))
			ret = 1;
		break;
	case 4:
		if (student->grades[gradeIndex] >= *((char*)value))
			ret = 1;
		break;
	case 5:
		if (student->grades[gradeIndex] <= *((char*)value))
			ret = 1;
		break;
	case 6:
		if (student->grades[gradeIndex] != *((char*)value))
			ret = 1;
		break;
	}
	return ret;
}
int filterByAverage(Student* student, char op, float* value) {
	char ret = 0, gradeIndex = 0;
	switch (op)
	{
	case 1:
		if (student->average == *value)
			ret = 1;
		break;
	case 2:
		if (student->average > *value)
			ret = 1;
		break;
	case 3:
		if (student->average < *value)
			ret = 1;
		break;
	case 4:
		if (student->average >= *value)
			ret = 1;
		break;
	case 5:
		if (student->average <= *value)
			ret = 1;
		break;
	case 6:
		if (student->average != *value)
			ret = 1;
		break;
	}
	return ret;
}
