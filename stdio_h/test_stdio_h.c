#include <stdio.h>

int main()
{
    // size_t size;
    // size = sizeof(int);
    // printf("sizeof(int): %ld\n",size);
    // printf("sizeof(size_t): %ld\n",sizeof(size_t));

    char *memory = (char *)10000;
    int size = 1024;
    
    FILE *file = fopen("output.txt","w");

    if (file == NULL)
    {
        printf("Error opening file");
        return 1;
    }
    for(int i = 0; i < size; i++)
    {
        fprintf(file,"%c",*(memory+i));
    }
    fclose(file);
    return 0;
}