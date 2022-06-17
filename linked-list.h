#ifndef _LIST_H
#define _LIST_H


struct _Node;
typedef int ElementType;
typedef struct _Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

List MakeEmptyList(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X,List L);
Position FindPrevious(ElementType X,List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif 
