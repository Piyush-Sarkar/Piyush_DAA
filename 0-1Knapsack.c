#include<stdio.h>
int max(int a, int b) {
   return (a > b) ? a : b;
}
int knapsack(int W, int wt[], int val[], int n) {
   int i, w;
   int knap[n + 1][W + 1];
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= W; w++) {
         if (i == 0 || w == 0)
            knap[i][w] = 0;
         else if (wt[i - 1] <= w)
            knap[i][w] = max(val[i - 1] + knap[i - 1][w - wt[i - 1]], knap[i - 1][w]);
         else
            knap[i][w] = knap[i - 1][w];
      }
   }
   return knap[n][W];
}
int main() {
   int n, W;
   printf("Enter the number of items: ");
   scanf("%d", &n);
   int val[n], wt[n];
   printf("Enter the values of items: ");
   for (int i = 0; i < n; i++)
      scanf("%d", &val[i]);
   printf("Enter the weights of items: ");
   for (int i = 0; i < n; i++)
      scanf("%d", &wt[i]);
   printf("Enter the capacity of the knapsack: ");
   scanf("%d", &W);
   printf("The maximum value that can be put in a knapsack of capacity %d is: %d\n", W, knapsack(W, wt, val, n));
   return 0;
}
