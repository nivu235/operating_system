#include <stdio.h>
#include <stdlib.h> 
int main()
{
    FILE *fptr1, *fptr2;
    char filename[100], c;
 	fptr1 = fopen("exx1.txt", "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }
  	fptr2 = fopen("exxx2.txt", "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
  
    printf("\nContents copied to file");
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}