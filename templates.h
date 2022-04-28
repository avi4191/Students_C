
typedef struct Student {
	char grades[3];
	float average;
	char* firstName;
	char* lastName;
	struct Student* next;
	char id[10];
}Student;

typedef struct {
	Student* head;
	Student* tail;
	unsigned int length;
	unsigned int fallenRows;
	unsigned int changes;
	unsigned char isSortedFile;
}Manager;

#define MAXNAMECOURSE 30

#define TRUE 1
#define FALSE 0
#define EMPTY -1

#define COURSE1 "clanguage"
#define COURSE2 "computernetworks"
#define COURSE3 "csfundamentals"
#define NAMECOURSE(x) (x==0)? COURSE1 : (x==1)? COURSE2:(x==2)? COURSE3 : "---"

#define MAXNAME 20
#define MAXFIELD 20
#define MAXCOMMAND 250
#define MAXLINE 150
#define MAXQUERY 70
#define NUM_OF_COURSES 3