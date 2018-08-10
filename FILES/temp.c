#include<stdio.h>

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

int main()
{
	gotoxy(32,43);
	printf("Hello World");
	return 0;
}