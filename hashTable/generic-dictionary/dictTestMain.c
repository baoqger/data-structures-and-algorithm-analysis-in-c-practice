#include "dict.h"

void test_dictionary(); 
void test_keyExist();
char* print_value_int(void*);
char* print_value_str(void*);


int
main(void)
{
  printf("///////////////////////\n");
  printf("// DICTIONARY \n");
  printf("///////////////////////\n");  

  test_dictionary();
  // test_keyExist();
  return 0;
}

void
test_dictionary()
{
  printf("TEST: dictionary put and rehash\n");
  HashTable H = initializeTable(4);
  printDictionary(H, print_value_int);
  printf("\n");
  printf("put chris:2 into the dictionary.\n");
  int i = 2;
  H = put("chris",(void*)&i, H);
  printDictionary(H, print_value_int);
  printf("\n");

  printf("put bao:1 into the dictionary.\n");
  int j = 3;
  H = put("bao",(void*)&j,H);
  printDictionary(H, print_value_int);
  printf("\n");

  printf("put paule:3 into the dictionary.\n");
  int k = 4;
  H = put("paule",(void*)&k,H);
  printDictionary(H, print_value_int);
  DestroyTable(H);
}


void 
test_keyExist() {
    printf("TEST: dictionary keyExist.\n");

    HashTable H = initializeTable(4);
    H = put("abc", (void*)2, H);
    H = put("def", (void*)23, H);
    keyExist("abc", H);
    printDictionary(H, print_value_int);
    printf("Key：%s %s\n", "abc", keyExist("abc", H) ? "exist" : "doesn't exist");
    printf("Key：%s %s\n", "chris", keyExist("chris", H) ? "exist" : "doesn't exist");
}

char* 
print_value_int(void* v) {
    char *s = NULL;
    s = malloc(sizeof(char) * 20);
    sprintf(s, "%d", *(int*)v);
    return s;
}





