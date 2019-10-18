////
//
//#include<stdio.h>
//#include<stdlib.h>
//
//struct Node
//{
//    int data;
//    struct Node * next;
//} *head;
//
//void insert_at_beginning()
//{
//    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
//
//    if(!new_node)
//    {
//        printf("NO");
//        return;
//    }
//    scanf("%d" , &new_node->data);
//    if(!head)
//    {
//        new_node->next = head;
//        head = new_node;
//        return;
//    }
//    else
//    {
//        new_node->next = head;
//        head = new_node;
//        return;
//    }
//}
//
//
//void delete_at_end()
//{
//    struct Node *ptr, *preptr;
//    struct Node* temp;
//    struct Node* lpr;
//
//    if(!head)
//    {
//        printf("NO");
//        return;
//    }
//
//    else if (head ->next == head)
//    {
//        head = NULL;
//        free(head);
//        printf("\nNode Deleted\n");
//    }
//    else
//    {
//        ptr = head;
//        while(ptr ->next != head)
//        {
//            preptr=ptr;
//            ptr = ptr->next;
//        }
//        preptr->next = ptr -> next;
//        free(ptr);
//        printf("\nNode Deleted\n");
//    }
//}
//
////void traversal()
////{
////    if(!head)
////        return;
////    else
////    {
////         for( struct Node* temp = head ; temp->next!=head ; temp=temp->data )
////        {
////            printf("%d" , temp->data);
////        }
////        return;
////    }
////}
//
//void traversal()
//{
//    struct node* temp;
//    for( temp=head ; temp->next!=head ; temp=temp->next)
//    {
//        printf("%4d" , temp->data);
//    }
//}
//
//int main()
//{
//    for(int i = 0 ; i<6 ; i++)
//    {
//         insert_at_beginning();
//    }
//
//    traversal();
//
//    delete_at_end();
//      traversal();
//
//}


#include<stdio.h>
#include<stdlib.h>
void create(int);
void last_delete();
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void main ()
{
    int choice,item;
    do
    {
        printf("1.Append List\n2.Delete Node from end\n3.Traverse\n4.Enter your choice?");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter the item\n");
            scanf("%d",&item);
            create(item);
            break;
            case 2:
            last_delete();
            break;
            case 3:
            traversal();
            break;
            default:
            printf("\nPlease Enter valid choice\n");
        }

    }while(choice != 3);
}
void traversal()
{
    struct node* temp;
    for( temp=head ; temp->next!=head ; temp=temp->next)
    {
        printf("%4d" , temp->data);
    }
}
void create(int item)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if(ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        ptr -> data = item;
        if(head == NULL)
        {
            head = ptr;
            ptr -> next = head;
        }
        else
        {
            temp = head;
            while(temp->next != head)
                temp = temp->next;
            ptr->next = head;
            temp -> next = ptr;
            head = ptr;
        }
    printf("\nNode Inserted\n");
    }

}
void last_delete()
{
struct node *ptr, *preptr;
    if(head==NULL)
    {
        printf("\nUNDERFLOW\n");
    }
    else if (head ->next == head)
    {
        head = NULL;
        free(head);
        printf("\nNode Deleted\n");
    }
    else
    {
        ptr = head;
        while(ptr ->next != head)
        {
            preptr=ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr -> next;
        free(ptr);
        printf("\nNode Deleted\n");
    }
}
