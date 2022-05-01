#include "templates.h"

//checks and handles file errors
void checkFile(FILE*);

//checks and handles allocation errors
void checkAllocation(void* x, Manager* manager, void* ptrToFree1, void* ptrToFree2);


int isValidName(char*);
int isValidGrade(char*);
int isValidId(char*);
int getIdCourseByName(char*); //if not valid course - return 0

//checks and handles long line
void checkLongLine(char*, FILE* file);

//checks and updates if file is sorted
void checkIsSortedFile(Manager* manager, FILE* file);

void logger(FILE* log, unsigned char* erorrs, char* line, int numOfLine);