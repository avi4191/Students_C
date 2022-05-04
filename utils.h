#include "validation.h"

//Changes the string by reference, removes all spaces
void cleanSpaces(char*);

//Changes the string by reference, changes all the letters to lowercase
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
//return: code of field or -1 if not valid field
FieldCodes getCodeByField(char* str);

//Prints the "log.txt" file from the program folder
void printLog(void);

//Prints the "help.txt" file from the program folder
void printHelp(void);