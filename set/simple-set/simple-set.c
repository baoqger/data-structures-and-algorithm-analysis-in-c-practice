#include <stdlib.h>
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
void add(ET ele, SimpleSet s) {
    if (isFull(s)) { // if simpleset is full, then resize it
        resizeSimpleSet(s);
    }
    // todo: find the element
}

/* find the target element in the set
 * return -1: the target element is not found
 * return the index of the target: the target is found
 * */

int find(ET elem, SimpleSet s) {
    for(int i = 0; i <= 1; i++ ) {
        if(s->Array[i] == elem) {
            return i;
        }
    }
    return -1;
}


static void resizeSimpleSetArray(ET **array, int length) {
    *array = realloc(*array, sizeof(ET)*length);
}

static void resizeSimpleSet(SimpleSet s) {
    s->Capacity *= 2;
    resizeSimpleSetArray(&(s->Array), s->Capacity);
}
