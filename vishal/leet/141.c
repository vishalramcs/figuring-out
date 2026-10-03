/* run in terminal: gcc  .\vishal\leet\141.c -o .\vishal\leet\141.exe; .\vishal\leet\141.exe */

/*
 * Linked List Cycle Detection (Floyd's Tortoise and Hare)
 *
 * The list is built from input (n, pos, then n values). A cycle is created
 * by pointing the tail node's next pointer back to the node at index pos
 * (pos = -1 means no cycle). hasCycle then runs two pointers, slow (1 step)
 * and fast (2 steps); if they meet, a cycle exists.
 *
 * Example: n = 4, pos = 1, values = 3 2 0 -4
 *   3 -> 2 -> 0 -> -4
 *        ^__________|     (tail -4 points back to index 1)
 *   Output: Cycle detected
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int value) {
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

/* Reads n values from stdin, builds the list, and links the tail
   to node at index pos (pos = -1 means no cycle). */
struct ListNode* createList(int n, int pos) {
    if (n <= 0) return NULL;

    struct ListNode *head = NULL, *tail = NULL, *cycleTarget = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) != 1) value = 0;

        struct ListNode* node = createNode(value);

        if (head == NULL) head = node;
        else tail->next = node;
        tail = node;

        if (i == pos) cycleTarget = node;
    }

    if (cycleTarget != NULL)
        tail->next = cycleTarget;   /* create the cycle */

    return head;
}

bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

/* Frees exactly n nodes, so it is safe even if the list has a cycle. */
void freeList(struct ListNode* head, int n) {
    for (int i = 0; i < n && head != NULL; i++) {
        struct ListNode* next = head->next;
        free(head);
        head = next;
    }
}

int main() {
    int n, pos;

    /* Number of nodes */
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    /* Build list: reads n values, then pos */
    /* Read values first, so pos must come after them: handle via two-step input */
    /* Simpler: read pos before values */
    if (scanf("%d", &pos) != 1) return 1;

    struct ListNode* head = createList(n, pos);

    if (hasCycle(head))
        printf("Cycle detected\n");
    else
        printf("No cycle detected\n");

    freeList(head, n);
    return 0;
}