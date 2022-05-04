#include "header.h"


void selectCommand(Manager* manager, char* input) {
	//parser and validation
	if (strlen(input) > MAXQUERY) {
		printf("Invalid length query");
		return;
	}
	char *token, temp[MAXQUERY], len, val[MAXNAME];
	strcpy(temp, input);
	token = strtok(temp, "<>=!");
	FieldCodes codeField = getCodeByField(token);
	len =(int) strlen(token);
	if (codeField == notValidField) {
		printf("\'%s\' is not valid property!", token);
		return;
	}
	OperatorCodes op = getOperator(input + len);
	if (op == notValidOperator) {
		printf("Invalid operator!");
		return;
	}
	if (op <= 3)//if length operator =1
		strcpy(val, input + len + 1);
	else//if length operator =2
		strcpy(val, input + len + 2);
	
	//handles by field
	switch (codeField)
	{  
	case firstName:
		if (isValidName(val))
			printSelected(manager, &filterByFirstName, op, val);
		else
		{
			printf("value \'%s\' is not valid name!", val);
			return;
		}
		break;
	case lastName:
		if (isValidName(val))
			printSelected(manager, &filterByLastName, op, val);
		else
		{
			printf("value \'%s\' is not valid name!", val);
			return;
		}
		break;
	case ID:
		if (isValidId(val))
			printSelected(manager, &filterByID, op, val);
		else
		{
			printf("value \'%s\' is not valid ID!", val);
			return;
		}
		break;
	case grade1:
		if (isValidGrade(val)) {
			val[0] = atoi(val);
			printSelected(manager, &filterByGrade1, op, val);
		}
		else
		{
			printf("value \'%s\' is not valid grade!", val);
			return;
		}
		break;
	case grade2:
		if (isValidGrade(val)) {
			val[0] = atoi(val);
			printSelected(manager, &filterByGrade2, op, val);
		}
		else
		{
			printf("value \'%s\' is not valid grade!", val);
			return;
		}
		break;
	case grade3:
		if (isValidGrade(val)) {
			val[0] = atoi(val);
			printSelected(manager, &filterByGrade3, op, val);
		}
		else
		{
			printf("value \'%s\' is not valid grade!", val);
			return;
		}
		break;
	case average:
		if (1) {
			float tempVal =(float) atof(val);
			printSelected(manager, &filterByAverage, op, &tempVal);
		}
		else
		{
			printf("value \'%s\' is not valid average!", val);
			return;
		}
		break;
	}
}

int filterByFirstName(Student* student, char op, char* value) {
	switch (op)
	{
	case equal:
		if (strcmp(student->firstName, value) == 0)
			return 1;
		break;
	case bigger:
		if (strcmp(student->firstName, value) > 0)
			return 1;
		break;
	case smaller:
		if (strcmp(student->firstName, value) < 0)
			return 1;
		break;
	case biggerOrEqual:
		if (strcmp(student->firstName, value) >= 0)
			return 1;
		break;
	case smallerOrEqual:
		if (strcmp(student->firstName, value) <= 0)
			return 1;
		break;
	case notEqual:
		if (strcmp(student->firstName, value) != 0)
			return 1;
		break;
	}
	return 0;
}
int filterByLastName(Student* student, char op, char* value) {
	switch (op)
	{
	case equal:
		if (strcmp(student->lastName, value) == 0)
			return 1;
		break;
	case bigger:
		if (strcmp(student->lastName, value) > 0)
			return 1;
		break;
	case smaller:
		if (strcmp(student->lastName, value) < 0)
			return 1;
		break;
	case biggerOrEqual:
		if (strcmp(student->lastName, value) >= 0)
			return 1;
		break;
	case smallerOrEqual:
		if (strcmp(student->lastName, value) <= 0)
			return 1;
		break;
	case notEqual:
		if (strcmp(student->lastName, value) != 0)
			return 1;
		break;
	}
	return 0;
}
int filterByID(Student* student, char op, char* value) {
	switch (op)
	{
	case equal:
		if (strcmp(student->id, value) == 0)
			return 1;
		break;
	case bigger:
		if (strcmp(student->id, value) > 0)
			return 1;
		break;
	case smaller:
		if (strcmp(student->id, value) < 0)
			return 1;
		break;
	case biggerOrEqual:
		if (strcmp(student->id, value) >= 0)
			return 1;
		break;
	case smallerOrEqual:
		if (strcmp(student->id, value) <= 0)
			return 1;
		break;
	case notEqual:
		if (strcmp(student->id, value) != 0)
			return 1;
		break;
	}
	return 0;
}
int filterByGrade1(Student* student, char op, char* value) {
	char gradeIndex = 0;
	switch (op)
	{
	case equal:
		if (student->grades[gradeIndex] == *value)
			return 1;
		break;
	case bigger:
		if (student->grades[gradeIndex] > *value)
			return 1;
		break;
	case smaller:
		if (student->grades[gradeIndex] < *value)
			return 1;
		break;
	case biggerOrEqual:
		if (student->grades[gradeIndex] >= *value)
			return 1;
		break;
	case smallerOrEqual:
		if (student->grades[gradeIndex] <= *value)
			return 1;
		break;
	case notEqual:
		if (student->grades[gradeIndex] != *value)
			return 1;
		break;
	}
	return 0;
}
int filterByGrade2(Student* student, char op, char* value) {
	char gradeIndex = 1;
	switch (op)
	{
	case equal:
		if (student->grades[gradeIndex] == *value)
			return 1;
		break;
	case bigger:
		if (student->grades[gradeIndex] > *value)
			return 1;
		break;
	case smaller:
		if (student->grades[gradeIndex] < *value)
			return 1;
		break;
	case biggerOrEqual:
		if (student->grades[gradeIndex] >= *value)
			return 1;
		break;
	case smallerOrEqual:
		if (student->grades[gradeIndex] <= *value)
			return 1;
		break;
	case notEqual:
		if (student->grades[gradeIndex] != *value)
			return 1;
		break;
	}
	return 0;
}
int filterByGrade3(Student* student, char op, char* value) {
	char gradeIndex = 2;
	switch (op)
	{
	case equal:
		if (student->grades[gradeIndex] == *value)
			return 1;
		break;
	case bigger:
		if (student->grades[gradeIndex] > *value)
			return 1;
		break;
	case smaller:
		if (student->grades[gradeIndex] < *value)
			return 1;
		break;
	case biggerOrEqual:
		if (student->grades[gradeIndex] >= *value)
			return 1;
		break;
	case smallerOrEqual:
		if (student->grades[gradeIndex] <= *value)
			return 1;
		break;
	case notEqual:
		if (student->grades[gradeIndex] != *value)
			return 1;
		break;
	}
	return 0;
}
int filterByAverage(Student* student, char op, float* value) {
	switch (op)
	{
	case equal:
		if (student->average == *value)
			return 1;
		break;
	case bigger:
		if (student->average > *value)
			return 1;
		break;
	case smaller:
		if (student->average < *value)
			return 1;
		break;
	case biggerOrEqual:
		if (student->average >= *value)
			return 1;
		break;
	case smallerOrEqual:
		if (student->average <= *value)
			return 1;
		break;
	case notEqual:
		if (student->average != *value)
			return 1;
		break;
	}
	return 0;
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
		printf("\n%d items", lines);
	else
		printf("no results found!");
}