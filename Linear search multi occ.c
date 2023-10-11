#include <stdio.h>

void linearSearchMultiple(int arr[], int size, int target) {
    int occurrences = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Found target at index %d\n", i);
            occurrences++;
        }
    }

    if (occurrences == 0) {
        printf("Target not found in the array.\n");
    } else {
        printf("Target found %d times in the array.\n", occurrences);
    }
}

int main() {
    int arr[] = {3, 7, 2, 8, 7, 4, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    linearSearchMultiple(arr, size, target);

    return 0;
}

