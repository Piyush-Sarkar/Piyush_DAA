#include <stdio.h>

// Recursive function to solve Tower of Hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main() {
    int N;
    
    // Ask the user for the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &N);

    // A, B and C are names of rods
    towerOfHanoi(N, 'A', 'C', 'B');
    
    return 0;
}
