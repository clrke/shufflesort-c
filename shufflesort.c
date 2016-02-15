#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define string char*

int input(string query) {
    int x;

    printf("%s: ", query);
    scanf("%d", &x);

    return x;
}

void initialize_zeroes(int n, int array[n]) {
    for (int i = 0; i < n; i++) {
        array[i] = 0;
    }
}

void initialize(int n, int array[n]) {
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }
}

void print(int n, int array[n]) {
    for (int i = 0; i < n; i++) {
        printf("%12d %12d\n", i, array[i]);
    }
    printf("\n");
}

void swap(int n, int array[n], int i, int j) {
    int k = array[i];
    array[i] = array[j];
    array[j] = k;
}

void shuffle(int n, int array[n]) {
    n--;
    for (; n > 0; n--) {
        swap(n, array, rand() % (n + 1), n);
    }
}

int sort(int n, int array[n]) {
    int i, j, k, swaps_count = 0;

    for (i = 1; i < n; i++) {
        k = array[i];

        for (j = i - 1; k < array[j] && j >= 0; j--) {
            array[j+1] = array[j];
            swaps_count++;
        }
        array[j+1] = k;
    }

    return swaps_count;
}

float get_average(int n, int array[n], int total) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += i * array[i];
    }

    return sum / (float) total;
}

int main() {
    srand(time(NULL));

    int n = input("n"), m = input("m"), max_swaps = n * (n+1) / 2;
    int array[n], all_swaps_count[max_swaps];

    initialize(n, array);
    initialize_zeroes(max_swaps, all_swaps_count);

    for (int i = 0; i < m; i++) {
        shuffle(n, array);
        int swaps_count = sort(n, array);

        all_swaps_count[swaps_count]++;
    }

    printf("%12s %12s\n", "swap count", "occurences");
    print(max_swaps, all_swaps_count);

    printf("Average: %f", get_average(max_swaps, all_swaps_count, m));
}

