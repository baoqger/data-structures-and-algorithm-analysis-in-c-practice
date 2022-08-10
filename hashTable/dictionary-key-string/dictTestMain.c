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
  H = put("chris",2, H);
  H = put("bao",1,H);
  printDictionary(H);
  printf("\n");
  H = put("paule",3,H);
  printDictionary(H);
  DestroyTable(H);
}


void 
test_keyExist() {
    printf("TEST: dictionary keyExist.\n");

    HashTable H = initializeTable(10);
    H = put("abc", 2, H);
    H = put("def", 23, H);
    keyExist("abc", H);
    printDictionary(H);
    printf("Key：%s %s\n", "abc", keyExist("abc", H) ? "exist" : "doesn't exist");
    printf("Key：%s %s\n", "chris", keyExist("chris", H) ? "exist" : "doesn't exist");

}
