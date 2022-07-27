#include <stdio.h>
#include <stdlib.h>
#include "simple-set.h"


void test_createSimpleSet();
void test_add();
void test_find();
void test_resize();
void test_removeElement();


int main() {
    test_createSimpleSet();
    test_add();
    test_find();
    test_resize();
    test_removeElement();
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

void test_find() {
    printf("Test find element.\n");
    SimpleSet s = createSimpleSet(10);
    add("172.10.0.1",s);
    add("172.10.0.2",s);
    add("172.10.0.3",s);
    printSimpleSet(s);
    char *ip1 = "172.10.0.1";
    if (find(ip1, s) == -1) {
        printf("IP address: %s doesn't exist.\n", ip1);
    } else {
        printf("IP address: %s exist.\n", ip1);
    }
    char *ip2 = "172.10.0.0";
    if (find(ip2, s) == -1) {
        printf("IP address: %s doesn't exist.\n", ip2);
    } else {
        printf("IP address: %s exist.\n", ip2);
    }

    disposeSimpleSet(s);

}

void test_resize() {
    printf("Test resize SimpleSet.\n");
    SimpleSet s = createSimpleSet(2);
    add("172.10.0.1",s);
    add("172.10.0.2",s);
    printSimpleSet(s);
    add("172.10.0.3",s);
    printSimpleSet(s);
    disposeSimpleSet(s);
}

void test_removeElement() {
    printf("Test remove element.\n");
    SimpleSet s = createSimpleSet(10);
    add("172.10.0.1",s);
    add("172.10.0.2",s);
    add("172.10.0.3",s);
    printSimpleSet(s);
    char *ip1 = "172.10.0.1";
    removeElement(ip1, s);
    printSimpleSet(s);
    disposeSimpleSet(s);
}


