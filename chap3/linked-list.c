#include <stdlib.h>
#include "linked-list.h"
#include "../fatal.h"

struct _Node {
    ElementType Element;
    Position Next;
};

List MakeEmptyList(List L) {
    if(L != NULL)
        DeleteList(L);
    L = malloc(sizeof(struct _Node));
    if(L == NULL)
        FatalError("Out of Memory!");
    L->Next = NULL;
    return L;
}

int IsEmpty(List L) {
    return L->Next == NULL; 
}

int IsLast(Position P, List L) {
    return P->Next == NULL;
} 

Position Find(ElementType X, List L) {
    Position P;
    P = L->Next;
    while(P != NULL && P->Element != X) {
        P = P->Next;
    }
    return P;
}

void Delete(ElementType X, List L) {
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if(!IsLast(P, L)) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    } 
} 

Position FindPrevious(ElementType X, List L) {
    Position P;

    P = L;
    while(P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P;
}

void Insert(ElementType X, List L, Position P) {
    Position TmpCell;

    TmpCell = malloc(sizeof(struct _Node));
    if(TmpCell == NULL)
        FatalError("Out of space!!!");
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;

}

void DeleteList(List L) {
    Position P, TmpCell;
    P = L->Next;
    L->Next = NULL;
    while(P != NULL) {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}

Position Header(List L) {
    return L;
}

Position First(List L) {
    return L->Next;
}

Position Advance(Position P) {
    return P->Next;
}

ElementType Retrieve(Position P) {
    return P->Element;
}


