#include <stdio.h>
#include <stdlib.h>

void inputArray(int* arr, int n) {
    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < n; i++) {
        printf("Елемент %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArray(const int* arr, int n) {
    printf("Масив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int countNegativeOddIndex(const int* arr, int n) {
    int count = 0;
    for (int i = 1; i < n; i += 2) {
        if (arr[i] < 0) {
            count++;
        }
    }
    return count;
}

int findMinAbsElement(const int* arr, int n) {
    int minAbs = abs(arr[0]);
    for (int i = 1; i < n; i++) {
        if (abs(arr[i]) < minAbs) {
            minAbs = abs(arr[i]);
        }
    }
    return minAbs;
}

long long computeProductAfterMinAbs(const int* arr, int n) {
    int minAbs = findMinAbsElement(arr, n);
    int minIndex = 0;
    while (abs(arr[minIndex]) != minAbs) {
        minIndex++;
    }
    
    long long product = 1;
    for (int i = minIndex + 1; i < n; i++) {
        product *= arr[i];
    }
    return product;
}

int main() {
    int n;
    printf("Введіть розмір масиву: ");
    scanf("%d", &n);
    
    int* array = (int*)malloc(n * sizeof(int));
    
    if (array == NULL) {
        printf("Не вдалося виділити пам'ять для масиву.\n");
        return 1;
    }
    
    inputArray(array, n);
    printArray(array, n);
    
    int count = countNegativeOddIndex(array, n);
    printf("Кількість від'ємних елементів масиву з непарними індексами: %d\n", count);
    
    long long product = computeProductAfterMinAbs(array, n);
    printf("Добуток елементів масиву, розташованих після мінімального за модулем елемента: %lld\n", product);
    
    free(array);
    
    return 0;
}
