#include "dict.h"

void test_dictionary();
void test_keyExist();

int
main(void)
{
  printf("///////////////////////\n");
  printf("// DICTIONARY \n");
  printf("///////////////////////\n");  

  test_dictionary();
  test_keyExist();
  return 0;
}

void
test_dictionary()
{
  printf("TEST: dictionary\n");
  HashTable H = initializeTable(10);
  H = put(1,2, H);
  H = put(10,1,H);
  printDictionary(H);
  printf("\n");
  H = put(10,3,H);
  printDictionary(H);
  DestroyTable(H);
}


void 
test_keyExist() {
    printf("TEST: dictionary keyExist.\n");

    HashTable H = initializeTable(10);
    H = put(1, 2, H);
    H = put(5, 23, H);
    printDictionary(H);
    printf("Key：%d %s\n", 1, keyExist(1, H) ? "exist" : "doesn't exist");
    printf("Key：%d %s\n", 2, keyExist(2, H) ? "exist" : "doesn't exist");

}
