////WAP to display the linked list
//
////#include<stdio.h>
////#include<stdlib.h>
////
////    typedef struct node
////    {
////        int data;
////        struct node * link;
////    }node;
////
////    node * create(int n);
////    void display(node * root);
////
////    int main()
////    {
////        int n=0;
////        node  * root = NULL;
////        printf("ENTER TOTAL NODES : ");
////        scanf("%d",&n);
////        root = create(n);
////
////        printf("\nTHE LINKED LIST IS: \n\n\n");
////        display(root);
////        printf("\n\n\n");
////
////        return 0;
////    }
////
////    node * create(int n)
////    {
////        int i=0;
////        node * root = NULL;
////        node * temp = NULL;
////        node * p = NULL;
////
////        for(i=0 ; i<n ; i++)
////        {
////                        temp = (node *)malloc (sizeof(node));
////                        printf("\nEnter the value of node no %d : ",i+1);
////                        scanf("%d" , &temp -> data);
////                        temp ->link=NULL;
////
////                        if(root == NULL)
////                        {
////                            root = temp ;
////                        }
////                        else
////                        {
////                            p=root;
////                            while(p ->link != NULL)
////                            {
////                                p = p ->link;
////                            }
////                        }
////        }
////
////        //link = (node *) malloc (sizeof(node));
////    }
////
////    void display(node * root)
////    {
////            node *p =NULL;
////            if(root == NULL)
////                printf("\n Empty Man");
////            else
////            {
////                p=root;
////                while(p ->link !=NULL)
////                {
////                    printf("%d->", p->data);
////                    p = p ->link;
////                }
////            }
////    }
//
//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//   int data;
//   struct node *next;
//};
//
//struct node *start = NULL;
//void insert_at_begin(int);
//void insert_at_end(int);
//void traverse();
//void delete_from_begin();
//void delete_from_end();
//int count = 0;
//
//int main () {
//   int input, data;
//
//   for (;;) {
//      printf("1. Insert an element at beginning of linked list.\n");
//      printf("2. Insert an element at end of linked list.\n");
//      printf("3. Traverse linked list.\n");
//      printf("4. Delete element from beginning.\n");
//      printf("5. Delete element from end.\n");
//      printf("6. Exit\n");
//
//      scanf("%d", &input);
//
//      if (input == 1) {
//         printf("Enter value of element\n");
//         scanf("%d", &data);
//         insert_at_begin(data);
//      }
//      else if (input == 2) {
//         printf("Enter value of element\n");
//         scanf("%d", &data);
//         insert_at_end(data);
//      }
//      else if (input == 3)
//         traverse();
//      else if (input == 4)
//         delete_from_begin();
//      else if (input == 5)
//         delete_from_end();
//      else if (input == 6)
//         break;
//      else
//         printf("Please enter valid input.\n");
//   }
//
//   return 0;
//}
//
//void insert_at_begin(int x) {
//   struct node *t;
//
//   t = (struct node*)malloc(sizeof(struct node));
//   count++;
//
//   if (start == NULL) {
//      start = t;
//      start->data = x;
//      start->next = NULL;
//      return;
//   }
//
//   t->data = x;
//   t->next = start;
//   start = t;
//}
//
//void insert_at_end(int x) {
//   struct node *t, *temp;
//
//   t = (struct node*)malloc(sizeof(struct node));
//   count++;
//
//   if (start == NULL) {
//      start = t;
//      start->data = x;
//      start->next = NULL;
//      return;
//   }
//
//   temp = start;
//
//   while (temp->next != NULL)
//      temp = temp->next;
//
//   temp->next = t;
//   t->data    = x;
//   t->next    = NULL;
//}
//
//void traverse() {
//   struct node *t;
//
//   t = start;
//
//   if (t == NULL) {
//      printf("Linked list is empty.\n");
//      return;
//   }
//
//   printf("There are %d elements in linked list.\n", count);
//
//   while (t->next != NULL) {
//      printf("%d\n", t->data);
//      t = t->next;
//   }
//   printf("%d\n", t->data);
//}
//
//void delete_from_begin() {
//   struct node *t;
//   int n;
//
//   if (start == NULL) {
//      printf("Linked list is already empty.\n");
//      return;
//   }
//
//   n = start->data;
//   t = start->next;
//   free(start);
//   start = t;
//   count--;
//
//   printf("%d deleted from beginning successfully.\n", n);
//}
//
//void delete_from_end() {
//   struct node *t, *u;
//   int n;
//
//   if (start == NULL) {
//      printf("Linked list is already empty.\n");
//      return;
//   }
//
//   count--;
//
//   if (start->next == NULL) {
//      n = start->data;
//      free(start);
//      start = NULL;
//      printf("%d deleted from end successfully.\n", n);
//      return;
//   }
//
//   t = start;
//
//   while (t->next != NULL) {
//      u = t;
//      t = t->next;
//   }
//
//   n = t->data;
//   u->next = NULL;
//   free(t);
//
//   printf("%d deleted from end successfully.\n", n);
//}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int a;
    struct node *next;
};

void generate(struct node **);
void display(struct node*);
void delete(struct node **);

int main()
{
    struct node *head = NULL;

    generate(&head);
    display(head);
    delete(&head);
    return 0;
}

void generate(struct node **head)
{
    int num = 10, i;
    struct node *temp;

    for (i = 0; i < num; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->a = i;
        if (*head == NULL)
        {
            *head = temp;
            (*head)->next = NULL;
        }
        else
        {
            temp->next = *head;
            *head = temp;
        }
    }
}

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d   ", head->a);
        head = head->next;
    }
    printf("\n");
}

void delete(struct node **head)
{
    struct node *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
