#include "dataManagement.h"

//handles query request 
void selectCommand(Manager* manager, char* input);

//special functions that check specific field
//parameters: student for check, operator code, value for comparing
//return: true if condition occures
int filterByFirstName(Student* student, char op, void* value);
int filterByLastName(Student* student, char op, void* value);
int filterByID(Student* student, char op, void* value);
int filterByGrade1(Student* student, char op, void* value);
int filterByGrade2(Student* student, char op, void* value);
int filterByGrade3(Student* student, char op, void* value);
int filterByAverage(Student* student, char op, void* value);

//Prints the filtered list
//parameters: check func,operator code,value
void printSelected(Manager* manager, int(*fn)(Student*, char, void*), char op, void* val);