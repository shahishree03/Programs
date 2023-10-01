#include <stdio.h>
#include <stdlib.h>

int* getarray(int* source, int* dest, int n, int *length)
{
    int k = 0;
    static int result[11] = {0};
    int index = 0;
    result[0] = 0;

    for (int m = 1; m < n; m++)
    {
        if (source[m] >= dest[k])
        {
            index++;
            result[index] = m;
            k = m;
        }
    }

    *length = index + 1;
    return result;
}

int main()
{
    int num_ele, i;
    printf("provide the details how many sources and destination elements you want enter :");
    scanf("%d",&num_ele);
    printf("\nprovide the sources and destination for the follwoing :\n");

    int source[11];
    int dest[11] ;
    for( i=0;i<num_ele;i++)
    {
        printf("Source %d :",i);
        scanf("%d", &source[i]);
        printf("Destination %d : ",i);
       
        scanf("%d", &dest[i]);
        printf("\n");
    }
    printf("\nSource \t\t Destination\n\n");
    for(i=0;i<num_ele;i++)
    {
        printf("%d", source[i]);
         printf("\t\t\t");
        printf("%d", dest[i]);
        printf("\n");
    }
    int length;

    int *arr = getarray(source, dest,num_ele, &length);

    for (int i = 0; i < length; i++) {
        printf("%d ", *(arr + i));
    }

    return 0;
}
