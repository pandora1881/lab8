#include <stdio.h>
#include <stdlib.h>

// Функція для введення елементів масиву
void inputArray(int *array, int size)
{
    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Елемент %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

// Функція для виведення елементів масиву
void outputArray(int *array, int size)
{
    printf("Елементи масиву:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Функція для обчислення кількості від'ємних елементів з непарними індексами
int countNegativeOddIndices(int *array, int size)
{
    int count = 0;
    for (int i = 1; i < size; i += 2)
    {
        if (array[i] < 0)
        {
            count++;
        }
    }
    return count;
}

// Функція для обчислення добутку елементів масиву, розташованих після мінімального за модулем елемента
int productAfterMinAbsolute(int *array, int size)
{
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (abs(array[i]) < abs(array[minIndex]))
        {
            minIndex = i;
        }
    }

    int product = 1;
    for (int i = minIndex + 1; i < size; i++)
    {
        product *= array[i];
    }
    return product;
}

int main()
{
    int n;

    printf("Введіть розмір масиву: ");
    scanf("%d", &n);

    // Виділення пам'яті під масив
    int *array = (int *)malloc(n * sizeof(int));

    // Введення елементів масиву
    inputArray(array, n);

    // Виведення елементів масиву
    outputArray(array, n);

    // Обчислення та виведення кількості від'ємних елементів з непарними індексами
    int negativeOddCount = countNegativeOddIndices(array, n);
    printf("Кількість від'ємних елементів з непарними індексами: %d\n", negativeOddCount);

    // Обчислення та виведення добутку елементів масиву, розташованих після мінімального за модулем елемента
    int product = productAfterMinAbsolute(array, n);
    printf("Добуток елементів масиву, розташованих після мінімального за модулем елемента: %d\n", product);

    // Звільнення пам'яті
    free(array);

    return 0;
}
