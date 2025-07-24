#include <stdbool.h>

#define MAX 50

typedef int KEY;

typedef struct
{
    KEY key;
} REGISTERS;

typedef struct
{
    REGISTERS A[MAX];
    int elementsNumbers;
} LIST;

void startList(LIST *list)
{
    list->elementsNumbers = 0;
}

int sizeList(LIST *list)
{
    return list->elementsNumbers;
}

void printList(LIST *list)
{
    int i;
    printf("List: \" ");
    for (i = 0; i < list->elementsNumbers; i++)
    {
        printf("%i ", list->A[i].key);
    }
    printf("\"\n");
}

int searchSequential(LIST *list, KEY key)
{
    int i = 0;
    while (i < list->elementsNumbers)
    {
        if (key == list->A[i].key)
            return i;
        else
            i++;
    }
    return -1;
}

bool insertElementInList(LIST *list, REGISTERS registers, int i)
{
    int j;

    if ((list->elementsNumbers == MAX) || (i < 0) || (i > list->elementsNumbers))
    {
        return false;
    }

    for (j = list->elementsNumbers; j > i; j--)
        list->A[j] = list->A[j - 1];

    list->A[i] = registers;
    list->elementsNumbers++;
    return true;
}

bool deleteElementInList(KEY key, LIST *list)
{
    int after, j;
    after = searchSequential(list, key);

    if (after == -1)
        return false;

    for (j == after; j < list->elementsNumbers - 1; j++)
    {
        list->A[j] = list->A[j + 1];
    }

    list->elementsNumbers--;
    return true;
}


