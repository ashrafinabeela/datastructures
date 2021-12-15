#include <stdio.h>
#include <malloc.h>
struct node *start = NULL;
struct node *create_ll(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *insert_bef(struct node *start);
struct node *insert_after(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_bef(struct node *start);
struct node *delete_after(struct node *start);
struct node *delete_list(struct node *start);
struct node *display(struct node *start);

struct node
{
    int data;
    struct node *next;
};
int main(int argc, char const *argv[])
{
    start = create_ll(start);
    start = display(start);
    start = insert_beg(start);
    start = display(start);
    start = insert_end(start);
    start = display(start);
    start = delete_beg(start);
    start = display(start);
    start = delete_end(start);
    start = display(start);

    return 0;
}
struct node *create_ll(struct node *start)
{

    struct node *newNode, *ptr;
    int num;
    printf("Enter num");
    scanf("%d", &num);
    while (num != -1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;

        if (start == NULL)
        {
            start = newNode;
            newNode->next = NULL;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = NULL;
        }
        printf("Enter a num or press -1 for exit");
        scanf("%d", &num);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    printf("\n List Elements are :");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return start;
}
// easiest
struct node *insert_beg(struct node *start)
{
    struct node *ptr, *newNode;
    int num;
    printf("\nEnter num to insert beg");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    //only changing the pointers and pointing them
    newNode->data = num;
    newNode->next = start;
    start = newNode;
    return start;
}
struct node *insert_end(struct node *start)
{
    struct node *ptr, *newNode;
    int num;
    printf("\nEnter num to insert end");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    //only changing the pointers and pointing them
    newNode->data = num;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = NULL;
    return start;
}
struct node *insert_bef(struct node *start)
{
}
struct node *insert_after(struct node *start)
{
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *preptr, *ptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);

    return start;
}
struct node *delete_bef(struct node *start)
{
    return start;
}
struct node *delete_after(struct node *start)
{
    return start;
}

struct node *delete_list(struct node *start)
{
    struct node *ptr;
    if (start != NULL)
    {
        ptr = start;
        while (ptr != NULL)
        {
            printf("\n%d is to be deleted next.", ptr->data);
            start = delete_beg(start);
            ptr = start;
        }
    }
    return start;
}
