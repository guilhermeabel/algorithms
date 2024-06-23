#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int valor;
    struct elemento *prox;
};

/* function prototypes */
struct elemento *SortedMerge(struct elemento *a, struct elemento *b);

void FrontBackSplit(struct elemento *source, struct elemento **frontRef, struct elemento **backRef);

/* sorts the linked list by changing prox pointers (not valor) */
void MergeSort(struct elemento **inicioRef)
{
    struct elemento *inicio = *inicioRef;
    struct elemento *a;
    struct elemento *b;

    /* Base case -- length 0 or 1 */
    if (!(inicio) || !(inicio->prox))
    {
        return;
    }

    /* Split inicio into 'a' and 'b' sublists */
    FrontBackSplit(inicio, &a, &b);

    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);

    /* answer = merge the two sorted lists together */
    *inicioRef = SortedMerge(a, b);
}

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this  
function */
struct elemento *SortedMerge(struct elemento *a, struct elemento *b)
{
    struct elemento *result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->valor <= b->valor)
    {
        result = a;
        result->prox = SortedMerge(a->prox, b);
    }
    else
    {
        result = b;
        result->prox = SortedMerge(a, b->prox);
    }
    return (result);
}

/* UTILITY FUNCTIONS */
/* Split the elementos of the given list into front and back halves, 
    and return the two lists using the reference parameters. 
    If the length is odd, the extra elemento should go in the front list. 
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(struct elemento *source,
                    struct elemento **frontRef, struct elemento **backRef)
{
    struct elemento *fast;
    struct elemento *slow;
    slow = source;
    fast = source->prox;

    /* Advance 'fast' two elementos, and advance 'slow' one elemento */
    while (fast != NULL)
    {
        fast = fast->prox;
        if (fast != NULL)
        {
            slow = slow->prox;
            fast = fast->prox;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two 
    at that point. */
    *frontRef = source;
    *backRef = slow->prox;
    slow->prox = NULL;
}

/* Function to print elementos in a given linked list */
void printList(struct elemento *elemento)
{
    while (elemento != NULL)
    {
        printf("%d ", elemento->valor);
        elemento = elemento->prox;
    }
}

/* Function to insert a elemento at the beginging of the linked list */
void inserir(struct elemento **inicio_ref, int new_valor)
{
    /* allocate elemento */
    struct elemento *new_elemento = (struct elemento *)malloc(sizeof(struct elemento));

    /* put in the valor */
    new_elemento->valor = new_valor;

    /* link the old list off the new elemento */
    new_elemento->prox = (*inicio_ref);

    /* move the inicio to point to the new elemento */
    (*inicio_ref) = new_elemento;
}

/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct elemento *res = NULL;
    struct elemento *a = NULL;

    /* Let us create a unsorted linked lists to test the functions 
Created lists shall be a: 2->3->20->5->10->15 */
    inserir(&a, 15);
    inserir(&a, 10);
    inserir(&a, 5);
    inserir(&a, 20);
    inserir(&a, 3);
    inserir(&a, 2);

    printf("\n(un)sorted Linked List is: \n");
    printList(a);
    /* Sort the above created Linked List */
    MergeSort(&a);

    printf("\nSorted Linked List is: \n");
    printList(a);

    getchar();
    return 0;
}