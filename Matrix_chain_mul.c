#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of multiplications needed
int MatrixChainOrder(int p[], int i, int j) {
    if (i == j)
        return 0;
    int min = INT_MAX;
    for (int k = i; k < j; k++) {
        int count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (count < min)
            min = count;
    }
    return min;
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("The array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Minimum number of multiplications is: %d\n", MatrixChainOrder(arr, 1, n - 1));

    return 0;
}
