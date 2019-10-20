//wap all functions of double linked list

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
   int data;
   int key;

   struct Node *next;
   struct Node *prev;
};

struct Node *head = NULL;
struct Node *last;

void setlast()
{
    for(last = head; last->next != NULL; last = last->next);
}


//is list empty
bool isEmpty()
{
   return (bool) head == NULL;
}

int length()
{
   int count = 1;
//    for(last = head; last != NULL; last = last->next,count++);
   return count;
}

//display the list in from first to last
void displayForward()
{
    printf("\n");
   struct Node *temp;
   for(temp = head ; temp!=NULL ; temp = temp->next)
   {
       printf("[%3d , %3d]" , temp->key , temp->data);
   }
}

//display the list from last to first
void displayBackward()
{
    printf("\n");
   struct Node *lptr ;
   for(lptr = last ; lptr!=head ; lptr = lptr->prev)
   {
       printf("[%d , %d ]" , lptr->key , lptr->data);
   }
}


//insert link at the first location
void insert_at_beginning()
{
   struct Node *new_Node = (struct Node*) malloc(sizeof(struct Node));
   new_Node->key = 1;
   scanf("%d", &new_Node->data);

   if(isEmpty())
   {
      //make it the last link
      new_Node->prev = head ;
      new_Node ->next = NULL;
      head = last = new_Node;
      return;
    }
   else
   {
      head->prev = new_Node;
      new_Node->next = head;
      head = new_Node;
   }


}

//insert link at the last location
void insertLast(int key, int data)
{
   //create a link
   struct Node *link = (struct Node*) malloc(sizeof(struct Node));
   link->key = key;
   link->data = data;

   if(isEmpty())
   {
      //make it the last link
      last = link;
   }
   else
   {
      //make link a new last link
      last->next = link;
      //mark old last Node as prev of new link
      link->prev = last;
   }

   //point last to new last Node
   last = link;
}

//delete first item
//struct Node* deleteFirst()
//{
//   //save reference to first link
//   struct Node *temp = head;
//
//   //if only one link
//   if(head->next == NULL)
//   {
//      last = NULL;
//   }
//   else
//   {
//      head->next->prev = NULL;
//   }
//
//   head = head->next;
//   //return the deleted link
//   return temp;
//}

struct Node* deleteFirst()
{
    struct Node* temp  = head;

    if(head->next == NULL)
    {
        last = NULL;
        free(temp);
    }

    else
    {
        head->next->prev  = NULL;
        free(temp);
    }
    head = head->next ;
}

//delete link at the last location
struct Node* deleteLast()
{
   //save reference to last link
   struct Node *tempLink = last;

   //if only one link
   if(head->next == NULL)
   {
      head = NULL;
   }
   else
   {
      last->prev->next = NULL;
   }

   last = last->prev;

   //return the deleted link
   return tempLink;
}

void deleteLast()
{
    struct Node* temp  = last;

    if(head)


}

//delete a link with given key
struct Node* delete(int key)
{
   //start from the first link
   struct Node* current = head;
   struct Node* previous = NULL;

   //if list is empty
   if(head == NULL)
   {
      return NULL;
   }

   //navigate through list
   while(current->key != key)
   {
      //if it is last Node

      if(current->next == NULL)
      {
         return NULL;
      }
      else
      {
         //store reference to current link
         previous = current;

         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head)
   {
      //change first to point to next link
      head = head->next;
   }
   else
   {
      //bypass the current link
      current->prev->next = current->next;
   }

   if(current == last)
   {
      //change last to point to prev link
      last = current->prev;
   }
   else
   {
      current->next->prev = current->prev;
   }

   return current;
}

//insert data after the specified Node
bool insertAfter(int key, int newKey, int data)
{
   //start from the first link
   struct Node *current = head;

   //if list is empty
   if(head == NULL)
   {
      return false;
   }

   //navigate through list
   while(current->key != key)
   {

      //if it is last Node
      if(current->next == NULL)
      {
         return false;
      }
      else
      {
         //move to next link
         current = current->next;
      }
   }

   //create a link
   struct Node *newLink = (struct Node*) malloc(sizeof(struct Node));
   newLink->key = key;
   newLink->data = data;

   if(current == last)
   {
      newLink->next = NULL;
      last = newLink;
   }
   else
   {
      newLink->next = current->next;
      current->next->prev = newLink;
   }

   newLink->prev = current;
   current->next = newLink;
   return true;
}

void reverse_print()
{
    for(last = head ; last->next!=NULL ; last = last->next);
    struct Node* temp;
    for(temp = last ; temp!=head ; temp = temp ->prev)
    {
        printf("%2d" , temp->data);
    }
}

int main()
{
   for(int i = 0 ; i< 5 ; i++)
   {
       insert_at_beginning();
   }

    reverse_print();
//    printf("%d" , length());
//
//   printf("\nList (First to Last): ");
//   displayForward();
//
//   printf("\n");
//   printf("\nList (Last to first): ");
//   displayBackward();
//
//   printf("\nList , after deleting first record: ");
//   deleteFirst();
//   displayForward();
//
//   printf("\nList , after deleting last record: ");
//   deleteLast();
//   displayForward();
//
//   printf("\nList , insert after key(4) : ");
//   insertAfter(4,7, 13);
//   displayForward();
//
//   printf("\nList  , after delete key(4) : ");
//   delete(4);
//   displayForward();
//
//
//
//   return 0;
}
