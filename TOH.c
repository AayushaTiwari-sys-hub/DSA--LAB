#include <stdio.h>

void TOH(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    TOH(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    TOH(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("Tower of Hanoi Moves:\n");
    TOH(n, 'A', 'C', 'B');  // A = Source, C = Destination, B = Auxiliary
    return 0;
}
