#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array should have at least two elements.\n");
        return 0;
    }

    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int smallest = arr[0];
    int secondSmallest = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != smallest) {
            if (secondSmallest == -1 || arr[i] < secondSmallest) {
                secondSmallest = arr[i];
            }
        }
    }

    if (secondSmallest == -1) {
        printf("No second smallest element exists.\n");
    } else {
        printf("The second smallest element is: %d\n", secondSmallest);
    }

    return 0;
}
