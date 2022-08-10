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
  printf("TEST: dictionary put and rehash\n");
  HashTable H = initializeTable(4);
  printDictionary(H);
  printf("\n");
  printf("put chris:2 into the dictionary.\n");
  H = put("chris",2, H);
  printDictionary(H);
  printf("\n");

  printf("put bao:1 into the dictionary.\n");
  H = put("bao",1,H);
  printDictionary(H);
  printf("\n");

  printf("put paule:3 into the dictionary.\n");
  H = put("paule",3,H);
  printDictionary(H);
  DestroyTable(H);
}


void 
test_keyExist() {
    printf("TEST: dictionary keyExist.\n");

    HashTable H = initializeTable(4);
    H = put("abc", 2, H);
    H = put("def", 23, H);
    keyExist("abc", H);
    printDictionary(H);
    printf("Key：%s %s\n", "abc", keyExist("abc", H) ? "exist" : "doesn't exist");
    printf("Key：%s %s\n", "chris", keyExist("chris", H) ? "exist" : "doesn't exist");

}
