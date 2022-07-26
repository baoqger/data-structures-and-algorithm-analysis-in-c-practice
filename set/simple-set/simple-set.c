#include <stdlib.h>
#include <string.h>
#include "simple-set.h"

#define EmptyToS (-1)
static void resizeSimpleSet(SimpleSet);

struct SetRecord {
    int Capacity; // the maximum number of elements in the Set
    int Size;     // the current number of elements in the Set
    ET *Array;
};

/* Create a SimpleSet */
SimpleSet createSimpleSet(int maxElements) {
    SimpleSet s = malloc(sizeof(struct SetRecord));
    s->Capacity = maxElements;
    s->Size = EmptyToS;
    s->Array = calloc(s->Capacity, sizeof(ET)); 
    return s;
}

/*Check if SimpleSet is full */
int isFull(SimpleSet s) {
    return s->Size == s->Capacity - 1; 
}

/* Add new element into SimpleSet */
void add(ET elem, SimpleSet s) {
    if (isFull(s)) { // if simpleset is full, then resize it
        resizeSimpleSet(s);
    }
    if (find(elem, s) == -1) { // if the elem doesn't exit, add it
        // char array is not assignable, need copy the string
        strcpy(s->Array[++s->Size], elem);  // increase the size by one      
    }
    // do nothing, if the element already exists
}

/* find the target element in the set
 * return -1: the target element is not found
 * return the index of the target: the target is found
 * */

int find(ET elem, SimpleSet s) {
    for(int i = 0; i <= 1; i++ ) {
        if(strcmp(s->Array[i], elem) == 0){ // strcmp return 0 if two strings are equal
            return i;
        }
    }
    return -1;
}

/*
 * remove the target element from the SimpleSet
 * */
void remove(ET elem, SimpleSet s) {
   int index;
   index = find(elem, s); 
   if (index == -1) { // if the element doesn't exist
        return;  
   } else {
       for (int i = index; i <= s->Size -1; i++) {
            strcpy(s->Array[i], s->Array[i + 1]);
       }
       s->Size--; // decrease the size by one
   }
}


static void resizeSimpleSetArray(ET **array, int length) {
    *array = realloc(*array, sizeof(ET)*length);
}

static void resizeSimpleSet(SimpleSet s) {
    s->Capacity *= 2;
    resizeSimpleSetArray(&(s->Array), s->Capacity);
}
