#include "validation.h"


void cleanSpaces(char*);

void toLowerCase(char*);

//search student with id in list
Student* findById(Manager* manager, char* id);

//print
//prints head of table 
void printHeader(void);
//prints one row in table
void printStudent(Student* student);
//prints the list from head as table
void printAll(Manager* manager);

//parameters: string that starts with operator
//return: operator code or 0 if not valid operator
OperatorCodes getOperator(char* str);

//parameters: name of field 
//return: code of field
FieldCodes getCodeByField(char* str);

void printLog(void);
void printHelp(void);