#include <stdio.h>
#include <time.h>

// Quick Sort Functions
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choosing the last element as pivot
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
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

    // Measure time for quick sort
    clock_t startSort = clock();
    quickSort(arr, 0, n - 1);
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

    // Calculate CPU times
    double timeSort = (double)(endSort - startSort) / CLOCKS_PER_SEC;
    double timeSearch = (double)(endSearch - startSearch) / CLOCKS_PER_SEC;

    printf("CPU Time for Quick Sort    : %.6f seconds\n", timeSort);
    printf("CPU Time for Binary Search: %.6f seconds\n", timeSearch);
    printf("Total CPU Time             : %.6f seconds\n", timeSort + timeSearch);

    return 0;
}
