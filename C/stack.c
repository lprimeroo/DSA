    #include<stdio.h>
    #include<conio.h>
    #include<stdlib.h>
    #define MAX 10
    struct stack
    {
        int items[MAX];
        int top;
    };
    typedef struct stack st;
    void createEmptyStack(st *s)
    {
        s->top=-1;
    }
    int isfull(st *s)
    {
        if (s->top==MAX-1)
            return 1;
        else
            return 0;
    }
    int isempty(st *s)
    {
        if (s->top==-1)
            return 1;
        else
            return 0;
    }
    void push(st *s)
    {
        int newitem;
        printf("Enter item to be inserted: ");
        scanf("%d",&newitem);
        if (isfull(s))
        {
            printf("STACK FULL");
        }
        else
        {
            s->top++;
            s->items[s->top]=newitem;
        }
    }
    void pop (st *s)
    {
        if (isempty(s))
        {
            printf("\n STACK EMPTY \n");
        }
        else
        {
            printf("Item popped= %d",s->items[s->top]);
            s->top--;
        }
    }
    void main()
    {
        int ch;
        int loop;
        loop=1;
        st *s;
        createEmptyStack(s);
        do
        {
            printf("\n ***STACK OPERATIONS");
            printf("\n 1. PUSH");
            printf("\n 2. POP");
            printf("\n 3. EXIT");
            printf("\n ***************");
            printf("\n Enter your choice: ");
            scanf("%d", &ch);
            switch (ch)
            {
                case 1: 
                    push(s);
                    break;
                case 2:
                    pop(s);
                    break;
                case 3:
                    printf("THANK YOU");
                    loop=0;
                    exit(0);
                default:
                    printf("Invalid choice");
            }
        } while(loop);
        getch();
    }



