#include<conio.h>
void gotomn(int m,int n)
{
int i;
for(i=0;i<m;i++)
printf("\n");
for(i=0;i<n;i++)
printf(" ");
}

/*void main()
{
deco();
}*/

void deco()
{
int i;
printf("Enter a key to continue");
getch();
system("clear");

gotomn(12,70);
printf("DSA PROJECT");
gotomn(1,70);
printf("***********");
gotomn(10,20);
printf("submitted to - Ashish sir");
gotomn(1,20);
printf("*************************");
gotomn(0,50); 
printf("submitted by -Nikhil Kumar Mishra (15103084)");
gotomn(1,95);
printf("********************************************");
gotomn(2,100);
printf("computer science   3rd sem");
gotomn(1,100);
printf("**************************");
gotomn(12,0);
for(i=0;i<150;i++)
printf("#");
printf("\n\npress a key to continue");
getch();
system("clear");
}


void bye()
{
int i;
gotomn(20,70);
printf("THANKYOU");
gotomn(20,0);
for(i=0;i<150;i++)
printf("%%");
getch();
system("clear");
}







