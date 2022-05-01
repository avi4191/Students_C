#include "utils.h"

//from file
int createListFromTable(Manager* manager);
int insertLine(char* line, int numLine, FILE* log, Manager* manager);

//add or update list
Student* addStudent(Manager* manager, char* fname, char* lname, char* id, unsigned char isFromFile);
void updateGrade(Student* student, int numOfCourse, int grade);
void editNames(Manager* manager, Student* student, char* fname, char* lname);
void addToListInOrder(Manager* manager, Student* student);
void setCommand(Manager* manager, char* input);

//general
float getAvgOfStudent(Student* student);
void resetGrades(Student* student);
void resetManager(Manager* manager);
Student* findPrev(Manager* manager, Student* student);

//save & quit
void quit(Manager* Manager);
void freeMemory(Manager* Manager);
void saveChanges(Manager* Manager);

