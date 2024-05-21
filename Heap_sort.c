#include <stdio.h>
void heapify(int arr[], int N, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        heapify(arr, N, largest);
    }
}
void sort(int arr[], int N) {
    int i, temp;
    for (i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (i = N - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int N) {
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void readArray(int arr[], int N) {
    printf("Enter the elements of array: ");
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    printf("The original array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int N;
    printf("Enter the size of array: ");
    scanf("%d", &N);
    int arr[N];
    readArray(arr, N);
    sort(arr, N);
    printf("Sorted array: ");
    printArray(arr, N);
    return 0;
}
