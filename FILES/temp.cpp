#include<iostream>

using namespace std;

void gotoxy(int x,int y)
{
for(int i=0;i<x;i++)
{
	cout<<endl;
}
for(int j= 0;j<y;j++)
{
	cout<<" ";
}
}

int main()
{
	system ("color B8");
	gotoxy(2,50);
	cout<<"aman dubey";
	return 0;
}