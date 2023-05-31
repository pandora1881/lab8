#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10;
    int a[] = {-4, 2, 2, -3, 4, 2, -4, 1, -2, 0};

    int max_absolute_value = abs(*a);  // Початкове найбільше значення
    int* max_indices[10];  // Масив вказівників на найбільші числа
    int count = 0;  // Лічильник знайдених найбільших чисел

    // Перебір елементів масиву і пошук найбільших чисел
    for (int i = 0; i < n; i++) {
        int current_value = abs(*(a + i));  // Абсолютне значення поточного числа

        if (current_value > max_absolute_value) {
            max_absolute_value = current_value;
            count = 0;  // Знайдено нове максимальне число, скидаємо лічильник
        }

        if (current_value == max_absolute_value) {
            max_indices[count] = &a[i];  // Зберігаємо адресу числа у масиві
            count++;  // Збільшуємо лічильник
        }
    }

    // Вивід елементів масиву
    printf("Елементи масиву: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Вивід порядкових номерів найбільших чисел
    printf("Номери: ");
    for (int i = 0; i < count; i++) {
        int index = max_indices[i] - a + 1;  // Визначення порядкового номеру
        printf("%d ", index);
    }
    printf("\n");

    return 0;
}
