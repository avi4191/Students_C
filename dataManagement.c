#include "header.h"

//from file
int createListFromTable(Manager* manager) {
	char line[MAXLINE + 1];
	int numline = 0, successLines = 0;
	FILE* input = fopen("save records.csv", "rt");
	checkFile(input);
	checkIsSortedFile(manager, input);
	FILE* log = fopen("log.txt", "at");
	if (log == NULL)
		log = fopen("log.txt", "wt");
	checkFile(log);

	while (fgets(line, MAXLINE, input) != NULL)
	{
		checkLongLine(line, input);
		line[strlen(line)-1] = '\0';
		if (insertLine(line, numline++, log, manager))
			successLines++;
	}
	manager->fallenRows = numline - successLines;
	fclose(input);
	fclose(log);
	if (manager->length == 0)
		return 0;
	printf("Lines received successfully: %d of %d\n", successLines, numline);
	return 1;
}

int insertLine(char* line, int numLine, FILE* log, Manager* manager) {
	char *column_p[5],* token, temp[MAXLINE + 1];
	unsigned char idCourse, erorrs[6], i = 0;
	Student* result = NULL;

	// parsers of the line
	cleanSpaces(line);
	toLowerCase(line);
	strcpy(temp, line);
	token = strtok(temp, ",");
	while (token!=NULL)
	{
		if (strlen(token) < MAXFIELD)
			column_p[i] = token;
		token = strtok(NULL, ",");
		i++;
	}
	
	// validation
	erorrs[firstNameErorr] = isValidName(column_p[firstName]);
	erorrs[lastNameErorr] = isValidName(column_p[lastName]);
	erorrs[IDErorr] = isValidId(column_p[ID]);
	erorrs[courseErorr] = idCourse = getIdCourseByName(column_p[course]);
	erorrs[gradeErorr] = isValidGrade(column_p[grade]);
	erorrs[namesNotEqualErorr] = 1;

	//Inserting the data into place
	if (erorrs[firstNameErorr]&&erorrs[lastNameErorr] &&erorrs[IDErorr]&&erorrs[courseErorr]&&erorrs[gradeErorr]) {//all data is valid
		result = findById(manager, column_p[ID]);//check if exist?
		if (result == NULL)//no exist, add new
			result = addStudent(manager, column_p[firstName], column_p[lastName], column_p[ID], TRUE);

		////else = exist, If the names in the row and the list names are not equal
		else if (strcmp(column_p[firstName], result->firstName) != 0 && strcmp(column_p[lastName], result->lastName) != 0) {
			erorrs[namesNotEqualErorr] = 0;
			logger(log, erorrs, line, numLine);
			return 0;
		}
		updateGrade(result, idCourse, atoi(column_p[grade]));
	}
	else { // is not valid case
		logger(log, erorrs, line, numLine);//erorr 1-5
		return 0;
	}
	return 1;
}


//add or update list
Student* addStudent(Manager* manager, char* fname, char* lname, char* id, unsigned char isFromFile) {
	//allocation
	Student* temp = (Student*)malloc(sizeof(Student));
	checkAllocation(temp,manager,NULL,NULL);
	temp->firstName = (char*)malloc((strlen(fname) + 1) * sizeof(char));
	checkAllocation(temp->firstName,manager,temp,NULL);
	temp->lastName = (char*)malloc((strlen(lname) + 1) * sizeof(char));
	checkAllocation(temp->lastName,manager,temp->firstName,temp);

	//copy 3 fields
	strcpy(temp->firstName, fname);
	strcpy(temp->lastName, lname);
	strcpy(temp->id, id);

	//resets fields (grades,avg,next)
	resetGrades(temp);
	temp->next = NULL;

	//add to list in order
	if (manager->length == 0)
		manager->head = manager->tail = temp;
	else {
		if (manager->isSortedFile && isFromFile)
			temp->next = NULL, manager->tail->next = temp, manager->tail = temp;
		else {
			addToListInOrder(manager, temp);
		}
	}
	manager->length++;

	return temp;
}

void updateGrade(Student* student, int numOfCourse, int grade) {

	student->grades[numOfCourse] = grade;
	student->average = getAvgOfStudent(student);
}

void editNames(Manager* manager, Student* student, char* fname, char* lname) {
	char flag = 0;
	if (*fname != 0 && strcmp(student->firstName, fname) != 0) {
		free(student->firstName);
		char* tempFN = (char*)malloc(strlen(fname) + 1 * sizeof(char));
		checkAllocation(tempFN, manager,NULL,NULL);
		strcpy(tempFN, fname);
		student->firstName = tempFN;
	}
	if (*lname != 0 && strcmp(student->lastName, lname) != 0) {
		if (strcmp(student->lastName, lname) > 0 || strcmp(lname, student->next->lastName) > 0) {//àí éù öåøê áîéåï çãù
			Student* ptr;
			ptr = findPrev(manager, student);
			if (ptr == NULL) {
				manager->head = student->next;
				student->next = NULL;
			}
			else
				ptr->next = ptr->next->next;
			flag = 1;
		}
		free(student->lastName);
		char* tempLN = (char*)malloc(strlen(fname) + 1 * sizeof(char));
		checkAllocation(tempLN,manager,NULL,NULL);
		strcpy(tempLN, lname);
		student->lastName = tempLN;
		if (flag)
			addToListInOrder(manager, student);
	}
}

void addToListInOrder(Manager* manager, Student* student) {

	Student* ptr = manager->head;
	if (strcmp(student->lastName, ptr->lastName) <= 0)//1 = The current should be before the head
	{
		student->next = ptr;
		manager->head = student;
	}

	else
	{
		while (TRUE)
		{
			if (ptr->next == NULL) //1 = The current should be the tail
			{
				student->next = NULL;
				manager->tail = ptr->next = student;
				break;
			}

			if (strcmp(student->lastName, ptr->next->lastName) <= 0)//1 = The current should be after the ptr and befor the ptr->next
			{
				student->next = ptr->next;
				ptr->next = student;
				break;
			}

			ptr = ptr->next;
		}
	}
}

void setCommand(Manager* manager, char* input) {
	char fname[MAXNAME] = { 0 }, lname[MAXNAME] = { 0 }, id[MAXNAME] = { 0 }, course[MAXFIELD] = { 0 }, grade1[5] = { 0 }, grade2[5] = { 0 }, grade3[5] = { 0 }, * token;
	char* arr[] = { fname,lname,id,grade1,grade2,grade3 };
	Student* result = NULL;
	FieldCodes temp;
	
	//parser all fields
	token = strtok(input, "=");
	while (token != NULL)
	{
		temp = getCodeByField(token);
		if (temp == notValidField || temp == average) {
			printf("\'%s\' is not valid field!", token);
			return;
		}
		token = strtok(NULL, ",");//ìáãå÷ ùäåà ìå÷ç àú äåììéå äàçøåï àôéìå ùàéï àçøéå ôñé÷
		strcpy(arr[temp], token);
		token = strtok(NULL, "=");
	}

	//validation
	if (*id == 0) {
		printf("id is requird!");
		return;
	}
	if (!isValidId(id)) {
		printf("invalid id!");
		return;
	}
	if (*fname!=0 && !isValidName(fname)) {
		printf("invalid first name!");
		return;
	}
	if (*lname!=0 && !isValidName(lname)) {
		printf("invalid last name!");
		return;
	}
	if ((*grade1 != 0 && !isValidGrade(grade1)) || (*grade2 != 0 && !isValidGrade(grade2)) || (*grade3 != 0 && !isValidGrade(grade3))) {
		printf("invalid grade!");
		return;
	}

	//check if is update or add
	result = findById(manager, id);
	if (result == NULL) {
		if (*fname == 0) {
			printf("for add student: first name is requird!");
			return;
		}
		if (*lname == 0) {
			printf("for add student: last name is requird!");
			return;
		}
		result = addStudent(manager, fname, lname, id, FALSE);
	}
	else {
		if (*fname == 0 && *lname == 0 && *grade1 == 0 && *grade2 == 0 && *grade3 == 0) {
			printf("For update: you must provide additional data to the ID!");
			return;
		}
		if (*fname != 0 || *lname != 0)
			editNames(manager, result, fname, lname);
	}

	//update grades
	for (int i = 3; i < 6; i++)
		if (arr[i][0] != 0)
			updateGrade(result, i - 3, atoi(arr[i]));
	manager->changes += 1;
}

//general
float getAvgOfStudent(Student* student) {
	int i, gradesCount = 0, sum = 0;
	for (i = 0; i < NUM_OF_COURSES; i++)
		if (student->grades[i] != -1)
			gradesCount++, sum += student->grades[i];
	return (float)sum / gradesCount;
}

Student* findPrev(Manager* manager, Student* student) {
	Student* ptr;
	ptr = manager->head;
	while (ptr->next != NULL) {
		if (ptr->next == student)
			return ptr;
		ptr = ptr->next;
	}
	return NULL;
}

void resetManager(Manager* manager) {
	manager->head = NULL;
	manager->tail = NULL;
	manager->changes = 0;
	manager->fallenRows = 0;
	manager->length = 0;
	manager->isSortedFile = 0;
}

void resetGrades(Student* student) {
	for (int i = 0; i < NUM_OF_COURSES; i++)
		student->grades[i] = EMPTY;
	student->average = 0;
}




//save & quit
void quit(Manager* manager) {
	if (manager->changes > 0 || manager->isSortedFile == 0 || manager->fallenRows > 0)
		saveChanges(manager);
	freeMemory(manager);
	exit(successfulExit);
}

void freeMemory(Manager* manager) {
	Student* temp = NULL, * ptr = manager->head;
	while (ptr != NULL)
	{
		free(ptr->firstName);
		free(ptr->lastName);
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
}

void saveChanges(Manager* manager) {
	FILE* file = fopen("save records.csv", "wt");
	Student* ptr = manager->head;
	checkFile(file);
	fprintf(file, "#\n");
	while (ptr != NULL)
	{
		for (int i = 0; i < NUM_OF_COURSES; i++)
			if (ptr->grades[i] != -1)
				fprintf(file, "%s,%s,%s,%s,%d\n", ptr->firstName, ptr->lastName, ptr->id, NAMECOURSE(i), ptr->grades[i]);
		ptr = ptr->next;
	}
	fclose(file);
}


