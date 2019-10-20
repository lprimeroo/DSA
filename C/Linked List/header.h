


struct Node
{
    int data ;
    struct Node* next ;
};

struct Node* head;

//////INSERT AT BEGINNING

void insert_at_beginning()
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    if(!new_node)
    {
        printf("MEMORY NOT ALLOCATED");
        return;
    }

    scanf("%d" ,&new_node->data);

    if(!head)
    {
        head = new_node;
        new_node->next = NULL;
        return;
    }

    else
    {
        new_node->next = head ;
        head = new_node;
        return;
    }
}

///////TRAVERSAL

void traversal()
{
    struct Node* temp;

    for( temp=head ; temp!=NULL ; temp=temp->next)
    {
        printf("%2d" , temp->data);
    }
}


