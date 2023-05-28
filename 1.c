#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n = 10;
    int a[] = {-4, 2, 2, -3, 4, 2, -4, 1, -2, 0};

    int maxMagnitude = 0;
    int indices[n];
    int count = 0;

    // Знаходимо максимальний модуль числа
    for (int i = 0; i < n; i++)
    {
        int magnitude = abs(a[i]);
        if (magnitude > maxMagnitude)
        {
            maxMagnitude = magnitude;
        }
    }

    // Знаходимо індекси чисел з максимальним модулем та друкуємо їх
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i]) == maxMagnitude)
        {
            indices[count] = i + 1;
            count++;
        }
        printf("%d ", a[i]);
    }

    printf("\nНомери: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", indices[i]);
    }

    return 0;
}
