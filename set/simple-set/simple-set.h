// This is a simple Set implementation based on array.
// The time complexity will be linear

#ifndef _SIMPLE_SET_H
#define _SIMPLE_SET_H 

// ET is shortfor ElementType
typedef char ET[20];
struct SetRecord;
typedef struct SetRecord *SimpleSet;

void NewSimpleSet(SimpleSet *s);
SimpleSet createSimpleSet(int);
int isFull(SimpleSet);
void add(ET, SimpleSet);
int find(ET, SimpleSet);
void removeElement(ET, SimpleSet);
void printSimpleSet(SimpleSet);
void disposeSimpleSet(SimpleSet);
#endif 

