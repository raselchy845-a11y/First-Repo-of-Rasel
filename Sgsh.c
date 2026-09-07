#include <stdio.h>

struct info
{
    int id;
    float cg;
    char name[20];
};

int main()
{
    struct info arr[3];

    for (int i = 0; i < 3; i++)
    {
        scanf("%d %f", &arr[i].id, &arr[i].cg);
        scanf(" %[^\n]", arr[i].name);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d %.2f %s\n", arr[i].id, arr[i].cg, arr[i].name);
    }

    return 0;
}
