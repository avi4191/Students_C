//structs
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

//names of courses
#define COURSE1 "clanguage"
#define COURSE2 "computernetworks"
#define COURSE3 "csfundamentals"
#define NAMECOURSE(x) (x==0)? COURSE1 : (x==1)? COURSE2:(x==2)? COURSE3 : "---"

//max length in program
#define MAXNAME 20
#define MAXFIELD 20
#define MAXCOMMAND 250
#define MAXLINE 150
#define MAXQUERY 70
#define NUM_OF_COURSES 3

//codes in program
typedef enum { allocationErorr, fileOpenErorr, fileEmptyErorr, successfulExit} ExitCodes;
typedef enum {notValidField =-1, firstName,lastName,ID, grade1,grade2,grade3,average} FieldCodes;
typedef enum {course=3, grade=4} columCodes;// 0,1,2 is same like field codes^
typedef enum {notValidOperator,equal,	bigger,	smaller,	biggerOrEqual,	smallerOrEqual,	notEqual} OperatorCodes;
typedef enum {firstNameErorr, lastNameErorr,  IDErorr, courseErorr, gradeErorr, namesNotEqualErorr} ErorrValidationCodes;
typedef enum { EMPTY =-1, FALSE, TRUE} general;