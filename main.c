#include<stdio.h>
#include<stdlib.h>
#include"header.h"
void main()
{
deco();             
int choice;



do
{
//  menu

printf("0: Quit\t1: singly linklist\t2: vector\t3:sum of array using pointers\t4:infix to postfix and evaluation\t5: stack\n\n6: two stack in 1 array\t\t7: linear search\t8:binary search\t\t9:fibonacci search\t10:BST\t11: bubble sort\n\n 12: selection sort\t13: insertion sort\t14: quick sort\t15: merge sort\t16:heap sort\t17:queue using circular list\n\n18: queue operation\t19: deque\t20:binary tree\t21:binary threaded tree\n");
gotomn(3,56);
printf("Enter a choice :");
scanf("%d",&choice);

switch(choice)
{

case 1:
fun1();                           //singly linklist all operations
break;

case 2:
mainvector();                    //vector
break;

case 3:
mainsoa();                       //sum of array using pointers
break;

case 4:
mainpolish();                    //infix to postfix and evaluation of postfix
break;

case 5:
mainstack();                     //stack basic operations push() , pop()
break;

case 6:
main_two_stack();                //two stack in one array
break;

case 7:
mainlinear();                    //linear search
break;

case 8:
mainbinary();                    //binary search
break;

case 9:
mainfibonacci();                 //fibonacci search
break;

case 10:
mainB();                         //BST
break;

case 11:                 
mainb();                         //bubble sort
break;

case 12:
mains();                         //selection sort
break;

case 13:
maini();                         //insertion sort
break;

case 14:
mainquick();                     //quick sort
break;

case 15:
mainmerge();                     //merge sort
break;

case 16:
mainheap();                      //heap sort
break;

case 17:
main_cir_listq();                //queue using circular list
break;

case 18:
mainqueue();                     //queue operations
break;

case 19:
maindq();                       //Deque
break;

case 20:
mainbintree();                 //binary tree
break;

case 21:
mainbtt();                     //binary threaded tree
break;


}
printf("press a key to continue\n");
getch();getch();
system("clear");
}while(choice!=0);

bye();
}
