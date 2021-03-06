/*
		DS Lab- 3
	   CSE Sec 2, Group 5
    Implementation of Queue using arrays
*/
#include<stdio.h>
#include<conio.h>
#define QSIZE 5
#define TRUE 1
#define FALSE 0
//********Functions Used*********
void menu();
void insert();
int remove();      //output is the element deleted
int isempty();     //output true or false
int isfull();      //output true or false
void display();

//********Global Variables*******
int qarr[QSIZE];
int front,rear,ele_last_rem;

//*******Main Function*********
void main()
{
#ifdef __CONIO_H
  clrscr();
#endif
  menu();
  display();
#ifdef __CONIO_H
  getch();
#endif
}

//****Display Function**********
void display()
{
  int i;
  printf("\n");
  for(i=0;i<=rear;i++)
  {
    printf("%d\t",qarr[i]);
  }
}

//******Menu Function***********
void menu()
{
  int choice;
  printf("\n\n\t\tEnter your Choice:");
  printf("\n\t\t:1 for Add into the Queue.. ");
  printf("\n\t\t:2 for Delete from the Queue.. ");
  printf("\n\t\t:3 Display Elements of the Queue.. ");
  printf("\n\t\t:4 For Exit..\n\t\t\t :: ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
    if(isfull())
    printf("\n\t\tERROR: Queue Overflow");
    insert();
    break;
    case 2:
    if(isempty())
    printf("\n\t\tERROR: Queue Underflow ! ! !");
    else
    printf("Element deleted is %d",remove());
    break;
    case 3:
    if(isempty())
    printf("\n\t\tERROR: Queue is empty");
    else
    display();
    break;
    case 4:
    //exit
    break;
    default:
    printf("Wish You knew how to count");
    break;
  }
}

//******Empty******
int isempty()
{
  if(front==rear)
  {
    return(TRUE);
  }
  else
  return(FALSE);
}

//*****Full*******
int isfull()
{
  if(rear==QSIZE)
  {
    return(TRUE);
  }
  else
  return(FALSE);
}

//*****insert******
void insert()
{
  int input;
  printf("\nEnter the element you wish to insert: ");
  scanf("%d",&input);
  qarr[rear]=input;
  rear+=1;    //increase rear by one
  printf("\nElement successfully inserted in the Queue");
  display();
}

//*****remove*******
int remove()
{
  if(front==-1||front>rear)
    printf("Queue Underflow !");
  front+=1;
  return(qarr[front-1]);
}
