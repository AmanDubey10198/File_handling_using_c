#include <stdio.h>
#include <stdlib.h>
 
void main()
{
    FILE *fptr;
    char ch;
 
    fptr = fopen("E://program//CPP&C//FILES//output_file.out", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf ("%c", ch);
        ch = fgetc(fptr);
    }
    fclose(fptr);
}