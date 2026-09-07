#include <stdio.h>

int main() {
    FILE *fptr;
    int num;

    fptr = fopen("numbers.txt", "a");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter 5 numbers:\n");

    for (int i = 0; i < 5; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &num);
        fprintf(fptr, "%d\n", num);
    }

    fclose(fptr);

    printf("Successfully saved 5 numbers to numbers.txt\n");

    return 0;
}
