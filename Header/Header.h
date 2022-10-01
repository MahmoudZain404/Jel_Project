#ifndef STACK_H_INCLUED
#define STACK_H_INCLUED
#define QUEUE_SIZE (10)
#define COURSES_NUM (3)
typedef enum boolean
{
    TRUE = 1,
    FALSE = 0
} boolean;

typedef struct Course
{
    int course_ID;
    int course_grade;
} Course;

typedef struct student
{
    int student_ID;
    int student_year;
    Course courses[COURSES_NUM];
} student;

//                 SDB_IsFull()
// Description: Check if the database is full
// Return Value: Return 1 if the the database is full, otherwise 0

boolean SDB_IsFull();

//               SDB_GetUsedSize()
// Description: Get the number of entries in the database
// Return: Return the number of entries

int SDB_GetUsedSize();

//                  bool SDB_AddEntry()
// Description: Add new entry to the database
// Return: Return 1 if the new entry is successfully added; otherwise 0

boolean SDB_AddEntry(int id, int year, int *subjects, int *grades);

//          void SDB_DeleteEntry()
// Description: Delete the entry with the given ID
// Input Parameter - id: ID of the entry to be deleted

void SDB_DeleteEntry();

//              bool SDB_ReadEntry()
// Description: Read an entry matching the provided ID
// Return Value: Return 1 if the entry exist, otherwise 0
// Input Parameter - id: Student ID
// Output Parameter - year: Pointer to the student year
// Output Parameter - subjects: Pointer to the subjects
// Output Parameter - grades: Pointer to the grades

boolean SDB_ReadEntry(int id);

//              void SDB_GetIdList()
// Description: Get the list of IDs of the students
// Output Parameter - count: Pointer to the number of entries currently exists in the
// database
// Output Parameter - list: Pointer to the list of ID

void SDB_GetIdList();

//               bool SDB_IsIdExist()
// Description: Checks if the the provided student ID exists
// Return Value: Return 1 if ID exists in the database, otherwise 0

boolean SDB_IsIdExist(int id);

#endif