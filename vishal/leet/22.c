/* Run in terminal: gcc .\vishal\leet\22.c -o .\vishal\leet\22.exe; .\vishal\leet\22.exe */
#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct ListNode
{
    int val;
    struct ListNode *next;
};

/* Create a new node */
struct ListNode* createNode(int value)
{
    struct ListNode* newNode = malloc(sizeof(struct ListNode));

    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}

/* Create linked list */
struct ListNode* createList(int n)
{
    struct ListNode* head = NULL;
    struct ListNode* temp = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);

        struct ListNode* newNode = createNode(value);

        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

/* Merge two sorted linked lists */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL)
        return list2;

    if (list2 == NULL)
        return list1;

    struct ListNode* result = NULL;
    struct ListNode* temp = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            if (result == NULL)
            {
                result = temp = list1;
            }
            else
            {
                temp->next = list1;
                temp = list1;
            }

            list1 = list1->next;
        }
        else
        {
            if (result == NULL)
            {
                result = temp = list2;
            }
            else
            {
                temp->next = list2;
                temp = list2;
            }

            list2 = list2->next;
        }
    }

    if (list1 != NULL)
        temp->next = list1;

    if (list2 != NULL)
        temp->next = list2;

    return result;
}

/* Display linked list */
void display(struct ListNode* head)
{
    struct ListNode* temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->val);

        if (temp->next != NULL)
            printf(" ");

        temp = temp->next;
    }

    printf("\n");
}

/* Free linked list */
void freeList(struct ListNode* head)
{
    struct ListNode* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int n1, n2;

    /* Number of nodes in first list */
    scanf("%d", &n1);

    /* First sorted list */
    struct ListNode* list1 = createList(n1);

    /* Number of nodes in second list */
    scanf("%d", &n2);

    /* Second sorted list */
    struct ListNode* list2 = createList(n2);

    /* Merge */
    struct ListNode* result = mergeTwoLists(list1, list2);

    /* Display merged list */
    display(result);

    /* Free memory */
    freeList(result);

    return 0;
}