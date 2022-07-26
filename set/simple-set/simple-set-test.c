#include <stdio.h>
#include <stdlib.h>
#include "simple-set.h"


void test_createSimpleSet();
void test_add();

int main() {
    test_createSimpleSet();
    test_add();
}

void test_createSimpleSet() {
    printf("Test create empty SimpleSet.\n");
    SimpleSet s = createSimpleSet(10);
    printSimpleSet(s);
    disposeSimpleSet(s);
}

void test_add() {
    printf("Test add element.\n");
    SimpleSet s = createSimpleSet(10);
    add("172.10.0.1",s);
    printSimpleSet(s);
    add("172.10.10.10",s);
    printSimpleSet(s);
    add("172.10.10.10",s);
    printSimpleSet(s);
    disposeSimpleSet(s);
}


