#include <stdio.h>
#include <stdlib.h>
#include "../Header/Header.h"

student students[QUEUE_SIZE];
int add_index = 0;

//                 SDB_IsFull()
// Description: Check if the database is full
// Return Value: Return 1 if the the database is full, otherwise 0

boolean SDB_IsFull(void)
{
    int counter = 0;
    int calc = 0;
    if (add_index == QUEUE_SIZE)
    {
        printf("\nData Base Is Full!\n");
        return TRUE;
    }
    else
    {
        for (int i = 0; i <= add_index; i++)
        {
            counter = i;
        }
        calc = (QUEUE_SIZE - 1) - counter;
        printf("\n%d Places Remains\n", calc);
        return FALSE;
    }
}

//               SDB_GetUsedSize(void)
// Description: Get the number of entries in the database
// Return: Return the number of entries

int SDB_GetUsedSize()
{
    if (add_index == 0 && add_index <= QUEUE_SIZE)
    {
        return add_index;
    }
}

//                  bool SDB_AddEntry()
// Description: Add new entry to the database
// Return: Return 1 if the new entry is successfully added; otherwise 0

boolean SDB_AddEntry(int id, int year, int *subjects, int *grades)
{
    students[add_index].student_ID = id;
    students[add_index].student_year = year;
    for (int i = 0; i < COURSES_NUM; i++)
    {
        students[add_index].courses[i].course_ID = subjects[i];
        if (grades[i] == 0 || grades[i] <= 100)
        {
            students[add_index].courses[i].course_grade = grades[i];
        }
    }
    add_index += 1;
    return TRUE;
}

//          void SDB_DeleteEntry()
// Description: Delete the entry with the given ID
// Input Parameter - id: ID of the entry to be deleted

void SDB_DeleteEntry()
{
    if (add_index != 0 && add_index <= QUEUE_SIZE)
    {
        add_index -= 1;
    }
}

//              bool SDB_ReadEntry()
// Description: Read an entry matching the provided ID
// Return Value: Return 1 if the entry exist, otherwise 0
// Input Parameter - id: Student ID
// Output Parameter - year: Pointer to the student year
// Output Parameter - subjects: Pointer to the subjects
// Output Parameter - grades: Pointer to the grades

boolean SDB_ReadEntry(int id)
{
    int ID = 0;
    int Grade = 0;
    boolean check = FALSE;
    if (add_index != 0 && add_index <= QUEUE_SIZE)
    {
        for (int i = 0; i < add_index; i++)
        {
            if (id == students[i].student_ID)
            {
                check = TRUE;
                printf("\n-----------------------------------------\n");
                printf("Student Year : %d\n", students[i].student_year);
                printf("--Student Subjects Are--\n");
                for (int j = 0; j < COURSES_NUM; j++)
                {
                    ID = students[i].courses[j].course_ID;
                    printf("Subject %d \t", ID);
                }
                printf("\n--Student Grades Are--\n");
                for (int x = 0; x < COURSES_NUM; x++)
                {
                    Grade = students[i].courses[x].course_grade;
                    printf("Subject %d Grade is : %d \t", x + 1, Grade);
                }
                printf("\n-----------------------------------------\n");
            }
        }
    }
    if (check == FALSE)
    {
        printf("\nStudent ID Does Not Exist\n");
    }
}

//              void SDB_GetIdList()
// Description: Get the list of IDs of the students
// Output Parameter - count: Pointer to the number of entries currently exists in the
// database
// Output Parameter - list: Pointer to the list of ID

void SDB_GetIdList()
{
    int ID = 0;
    if (add_index != 0 && add_index <= QUEUE_SIZE)
    {
        printf("\n-----------------------------------------\n");
        printf("[\t");
        for (int i = 0; i < add_index; i++)
        {
            ID = students[i].student_ID;
            printf("%d,\t", ID);
        }
        printf("]");
        printf("\n-----------------------------------------\n");
    }
}
//               bool SDB_IsIdExist()
// Description: Checks if the the provided student ID exists
// Return Value: Return 1 if ID exists in the database, otherwise 0
boolean SDB_IsIdExist(int id)
{
    for (int i = 0; i < add_index; i++)
    {
        if (id == students[i].student_ID)
        {
            printf("\nID Exists\n");
            return TRUE;
        }
        else
        {
            printf("\nID Doesn't Exist\n");
            return FALSE;
        }
    }
}