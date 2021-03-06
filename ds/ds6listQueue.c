/*
		    DS Lab- 5
	   CSE Sec 2, Group 5
	      Oct 10, 2012
	       UE 113090
AIM: Implementation of Queue using Linked Lists
*/
#include<stdio.h>
#include<stdlib.h>
struct nodeS {
  ///ptr to a node is represented by an array index
  int info;
  struct nodeS *next;    //next points to var of type node
};
typedef struct nodeS *NODEPTR;
//*******Global Variable*****
//********Functions**********
NODEPTR getNode(void);
void freeNode(NODEPTR);
/* void insAfter(NODEPTR p,int x); */
/* void delAfter(int p, int *px); */
/* void insert(NODEPTR tempStart,int x); */
void insert(NODEPTR , int);
void delete(NODEPTR , int);
void display(NODEPTR);

//*********Main**************
int main(){
  NODEPTR start;    //p is a ptr to struct nodeS
  start=getNode();
  start->info=0;
  start->next=NULL;
  
  printf("1. Insert at End\n");
  printf("2. Deleted at End\n");
//  printf("1. Insert After\n");
//  printf("2. Delete After\n");
  printf("3. Print\n");
  while(1){
    int query;
    printf("\nEnter operation: ");
    scanf("%d",&query);
    if(query==1){
      int data;
      printf("\nEnter data to insert at end: ");
      scanf("%d",&data);
      insert(start,data);
    }
    else if(query==2){
      int dataDeleted;
      printf("\nEnter data to be deleted: ");
      scanf("%d",&dataDeleted);
      delete(start,dataDeleted);
    }
    else if(query==3){
	  printf("The list is ");
	  display(start->next);
      printf("\n");
      }//end q=3
    }//end while
  }//end main
  
NODEPTR getNode(void){
  ///removes a node from available list and returns a ptr to it
  NODEPTR p;
  p=(NODEPTR)malloc(sizeof(struct nodeS));
  return(p);
}//end getnode

void freeNode(NODEPTR  p){
  ///returns the node(p) to the available list
  free(p);
}//end freenode
 
void display(NODEPTR p){
  if (p==NULL){
    return;
  }
  printf("\t%d",p->info);
  p=p->next;
  display(p);
}

void insert(NODEPTR tempStart,int x){
  ///if p is not null, inserts x into node after the node pointed by p
  NODEPTR q;
  q=getNode();
  q->info=x;//info saved in new node
  q->next=NULL;//new node points to null: at end
  //traverse to find last node
  while(tempStart->next!=NULL){
    tempStart=tempStart->next;
  }
  tempStart->next=q;//prev last node containing null now points to new node
}//end insert after


void delete(NODEPTR tempStart,int data){
  NODEPTR ptr;
  ptr=tempStart;
  while(ptr->next!=NULL && (ptr->next)->info!=data){
    //because we need ptr at location before the location to be deleted
    ptr=ptr->next;
    //printf("while");  //debug
  }
  if(ptr->next==NULL){
    printf("\nSorry key %d not found in List ! ",data);
  }
  else{
    NODEPTR temp;
    temp=ptr->next;  //temp points to node to be removed
    ptr->next=temp->next;  //removed node next to ptr
    freeNode(temp);  //free memory
    //printf("else");  //debug
  }
}

