#include <stdio.h>
#include <time.h>  // For clock()

// Insertion Sort Function
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Binary Search Function
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Measure time for insertion sort
    clock_t startSort = clock();
    insertionSort(arr, n);
    clock_t endSort = clock();

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Measure time for binary search
    clock_t startSearch = clock();
    int result = binarySearch(arr, n, key);
    clock_t endSearch = clock();

    if (result != -1)
        printf("Element found at index %d (0-based)\n", result);
    else
        printf("Element not found\n");

    // Calculate and display CPU time
    double timeSort = (double)(endSort - startSort) / CLOCKS_PER_SEC;
    double timeSearch = (double)(endSearch - startSearch) / CLOCKS_PER_SEC;

    printf("CPU Time for Insertion Sort: %.6f seconds\n", timeSort);
    printf("CPU Time for Binary Search : %.6f seconds\n", timeSearch);
    printf("Total CPU Time             : %.6f seconds\n", timeSort + timeSearch);

    return 0;
}
