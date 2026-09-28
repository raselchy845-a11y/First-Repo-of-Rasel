#include <stdio.h>

int main()
{
    FILE *file;
    int arr[100];
    int n, i, j, temp;
    int swapped;

    /* Step 1: Create file and write numbers */
    file = fopen("numbers.txt", "w");

    if (file == NULL)
    {
        printf("File could not be created!\n");
        return 1;
    }

    printf("How many numbers? ");
    scanf("%d", &n);

    fprintf(file, "Original numbers:\n");

    printf("Enter %d numbers:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);


    /* Step 2: Open file and read numbers */
    file = fopen("numbers.txt", "r");

    if (file == NULL)
    {
        printf("File could not be opened!\n");
        return 1;
    }

    /* Skip the text "Original numbers:" */
    fscanf(file, "Original numbers:\n");

    for (i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);


    /* Step 3: Bubble Sort */
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        /* Already sorted */
        if (swapped == 0)
            break;
    }


    /* Step 4: Append sorted array to file */
    file = fopen("numbers.txt", "a");

    if (file == NULL)
    {
        printf("File could not be opened!\n");
        return 1;
    }

    fprintf(file, "\n\nSorted numbers:\n");

    for (i = 0; i < n; i++)
    {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);


    /* Step 5: Show sorted array on screen */
    printf("\nSorted array:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nSorted numbers have been added to numbers.txt\n");

    return 0;
}
