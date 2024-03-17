#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers and save to file
void generateRandomNumbers(int *array, int size, int num) {
    char filename[20];
    sprintf(filename, "%d_input.txt", num);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand();
        fprintf(file, "%d\n", array[i]);
    }

    fclose(file);
}

// Bubble Sort algorithm
void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Selection Sort algorithm
void selectionSort(int *array, int size) {
    int minIndex, temp;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

// Insertion Sort algorithm
void insertionSort(int *array, int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

// Function to save sorted array and time to file
void saveSortedToFile(char *filename, int *array, int size, double time) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", array[i]);
    }

    fprintf(file, "\nWaktu Eksekusi (ms): %.2f\n", time);

    fclose(file);
}

int main() {
    const int max_size = 1000000;
    int *array = (int *)malloc(max_size * sizeof(int));

    printf("Sorting and recording times...\n");

    printf("| Jenis Algoritma | Jumlah Bilangan | Waktu Eksekusi (ms) |\n");
    printf("|-----------------|------------------|---------------------|\n");

    clock_t start, end;
    double cpu_time_used;

    for (int size = 100000; size <= max_size; size += 100000) {
        printf("| Bubble Sort     | %8dk         |", size / 1000);

        generateRandomNumbers(array, size, size);

        start = clock();
        bubbleSort(array, size);
        end = clock();

        char filename[20];
        sprintf(filename, "bubble_sort_%dk_output.txt", size / 1000);
        saveSortedToFile(filename, array, size, ((double)(end - start)) / CLOCKS_PER_SEC * 1000);

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf(" %11.2f |\n", cpu_time_used);
    }

    printf("\n");

    for (int size = 100000; size <= max_size; size += 100000) {
        printf("| Selection Sort  | %8dk         |", size / 1000);

        generateRandomNumbers(array, size, size);

        start = clock();
        selectionSort(array, size);
        end = clock();

        char filename[20];
        sprintf(filename, "selection_sort_%dk_output.txt", size / 1000);
        saveSortedToFile(filename, array, size, ((double)(end - start)) / CLOCKS_PER_SEC * 1000);

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf(" %11.2f |\n", cpu_time_used);
    }

    printf("\n");

    for (int size = 100000; size <= max_size; size += 100000) {
        printf("| Insertion Sort  | %8dk         |", size / 1000);

        generateRandomNumbers(array, size, size);

        start = clock();
        insertionSort(array, size);
        end = clock();

        char filename[20];
        sprintf(filename, "insertion_sort_%dk_output.txt", size / 1000);
        saveSortedToFile(filename, array, size, ((double)(end - start)) / CLOCKS_PER_SEC * 1000);

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf(" %11.2f |\n", cpu_time_used);
    }

    free(array);

    return 0;
}
