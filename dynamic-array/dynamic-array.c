#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

int startDynamicArray(DynamicArray *arr, size_t initialCapacity)
{
    arr->data = (int *)malloc(initialCapacity * sizeof(int));
    if (arr->data == NULL)
    {
        exit(EXIT_FAILURE);
    }
    arr->size = 0;
    arr->capacity = initialCapacity;
    return 0;
}

int addElements(DynamicArray *arr, int value)
{
    if (arr->size >= arr->capacity)
    {
        size_t newCapacity = arr->capacity > 0 ? arr->capacity * 2 : 1;
        int *newData = (int *)realloc(arr->data, newCapacity * sizeof(int));
        if (newData == NULL)
        {
            return -1;
        }
        arr->data = newData;
        arr->capacity = newCapacity;
        printf("Array redimensionado para capacidade: %zu\n", arr->capacity);
    }
    arr->data[arr->size] = value;
    arr->size++;
    return 0;
}

// Testes aqui
int main()
{
    DynamicArray myArr;

    startDynamicArray(&myArr, 10);
    printf("Array inicializado com capacidade: %zu\n", myArr.capacity);

    for (int i = 0; i < 9; i++)
    {
        addElements(&myArr, i + 1);
    }
    printf("\nAdicionados 9 elementos. Tamanho atual: %zu, Capacidade: %zu\n", myArr.size, myArr.capacity);

    printf("\nAdicionando 1000 inteiros...\n");
    for (int i = 0; i < 1000; i++)
    {
        addElements(&myArr, i + 1);
    }

    printf("\nFinalizado. Tamanho final: %zu, Capacidade final: %zu\n", myArr.size, myArr.capacity);

    free(myArr.data);

    return 0;
}