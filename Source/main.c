// Simple Data Base Project (Jelecom C cource test)
// Code By Mahmoud Zain Salah
#include <stdio.h>
#include <stdlib.h>
#include "../Header/Header.h"

int main()
{
    SDB_IsFull();
    SDB_GetUsedSize();

    int sub[3] = {10, 20, 30};
    int grads[3] = {40, 50, 60};
    SDB_AddEntry(711, 1998, sub, grads);
    SDB_AddEntry(811, 2023, sub, grads);
    SDB_AddEntry(911, 2023, sub, grads);

    SDB_IsFull();
    SDB_GetUsedSize();
    printf("The Number Of Entrys Are : %d\n", SDB_GetUsedSize());

    SDB_DeleteEntry();

    SDB_IsFull();
    SDB_GetUsedSize();
    printf("The Queue Size Is : %d\n", SDB_GetUsedSize());

    SDB_ReadEntry(711);
    SDB_ReadEntry(911); // does not exist;

    SDB_GetIdList();

    SDB_IsIdExist(711); //  exists
    SDB_IsIdExist(911); // does not exist
    return 0;
}