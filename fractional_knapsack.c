#include<stdio.h>
int p[100], w[100], n, a[100];
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
float* fractional_knapsack(int W, int n) {
    static float x[100];
    int load, i;
    float r;
    for (i = 1; i <= n; i++)
        x[i] = 0.0;
    load = 0;
    i = 1;
    while ((load < W) && (i <= n)) {
        if (w[i] + load <= W) {
            load = load + w[i];
            x[i] = 1.0;
        } else {
            r = W - load;
            load = load + r / (float)w[i];
            x[i] = r / (float)w[i];
        }
        i++;
    }
    return x;
}
int main() {
    float *ratio;
    int sum = 0, i, j, W;
    printf("Enter the number of items:");
    scanf("%d", &n);
    printf("Enter the total weight of the knapsack:");
    scanf("%d", &W);
    for (i = 1; i <= n; i++) {
        printf("Enter the profit and weight of item %d:", i);
        scanf("%d %d", &p[i], &w[i]);
        a[i] = p[i] / w[i];
    }
    for (i = 1; i <= n; i++) {
    for (j = i+1 ; j <= n ; j++) {
        if (a[i] < a[j]) { 
            swap(&a[j], &a[i]);
            swap(&p[j], &p[i]);
            swap(&w[j], &w[i]);
        }
    }
}
    ratio = fractional_knapsack(W, n);
    for (i = 1; i <= n; i++)
        sum = sum + (p[i] * ratio[i]);
    printf("The maximum profit is :%d", sum);
    return 0;
}
