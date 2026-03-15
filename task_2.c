#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// arr - массив, size - размер массива, указатели для "холмов" и "долин"
void count_hills_valleys(int arr[], int size, int *hills, int *valleys) {
    *hills = 0;
    *valleys = 0;
    
    // Проходим по внутренним элементам (индексы от 1 до size-2)
    for (int i = 1; i < size - 1; i++) {
        // Проверка на холм: больше обоих соседей
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            (*hills)++;
        }
        // Проверка на "долин": меньше обоих соседей
        else if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
            (*valleys)++;
        }
    }
}

int main() {
    int hills, valleys;

    srand(time(NULL));
    int size2 = 15;
    int arr2[size2];
    
    printf("Случайный массив: ");
    for (int i = 0; i < size2; i++) {
        arr2[i] = rand() % 20 - 5;  // числа от -5 до 14
        printf("%d ", arr2[i]);
    }
    printf("\n");
    
    count_hills_valleys(arr2, size2, &hills, &valleys);
    printf("Холмы: %d, Долины: %d\n", hills, valleys);
 
    return 0;
}
