// This is a simple Set implementation based on array.
// The time complexity will be linear

#ifndef _SIMPLE_SET_H
#define _SIMPLE_SET_H 

// ET is shortfor ElementType
typedef char ET[20];
struct SetRecord;
typedef struct SetRecord *SimpleSet;

SimpleSet createSimpleSet(int);
int isFull(SimpleSet);
void add(ET, SimpleSet);
int find(ET, SimpleSet);
void remove(ET, SimpleSet);
#endif 

