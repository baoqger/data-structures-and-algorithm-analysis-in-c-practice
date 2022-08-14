#include <string.h>
#include "dict.h"
#include "person.h"

void test_dictionary_value_int(); 
void test_dictionary_value_str();
void test_dictionary_value_person();
struct person* initializePerson(char*, int);
void test_keyExist();
char* print_value_int(void*);
char* print_value_str(void*);
char* print_value_person(void*);

int
main(void)
{
  printf("///////////////////////\n");
  printf("// DICTIONARY \n");
  printf("///////////////////////\n");  

  test_dictionary_value_int();
  test_dictionary_value_str();
  test_dictionary_value_person();
  // test_keyExist();
  return 0;
}

void
test_dictionary_value_int()
{
  printf("TEST: generic  dictionary put and rehash for int value\n");
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
test_dictionary_value_str()
{
  printf("TEST: generic dictionary put and rehash for string type value\n");
  HashTable H = initializeTable(4);
  printDictionary(H, print_value_str);
  printf("\n");
  printf("put chris: abc into the dictionary.\n");
  H = put("chris",(void*)"abc", H);
  printDictionary(H, print_value_str);
  printf("\n");

  printf("put bao: def into the dictionary.\n");
  H = put("bao",(void*)"def",H);
  printDictionary(H, print_value_str);
  printf("\n");

  printf("put paule: hij into the dictionary.\n");
  H = put("paule",(void*)"hij",H);
  printDictionary(H, print_value_str);
  DestroyTable(H);
}

void
test_dictionary_value_person()
{
  printf("TEST: generic dictionary put and rehash for struct person type value\n");
  HashTable H = initializeTable(4);
  printDictionary(H, print_value_person);
  printf("\n");
  printf("put 1a34bc: {chris, 36} into the dictionary.\n\n");
  struct person *p1 = initializePerson("chris", 36);
  H = put("1a34bc",(void*)p1, H);
  printDictionary(H, print_value_person);
  printf("\n");

  printf("put 2233ab: {paule: 30} into the dictionary.\n\n");
  struct person *p2 = initializePerson("paule", 30);
  H = put("2233ab",(void*)p2, H);
  printDictionary(H, print_value_person);
  printf("\n");

  printf("put 3344ok: {roro: 18} into the dictionary.\n\n");
  struct person *p3 = initializePerson("roro", 18);
  H = put("3344ok",(void*)p3, H);
  printDictionary(H, print_value_person);
  
  printf("increase roro's age by 1\n");
  struct person *roro = retrieve("3344ok", H);
  roro->age += 1;
  printDictionary(H, print_value_person);

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

char* 
print_value_str(void* v) {
    return (char*)v;
}

char*
print_value_person(void* v) {
    char *s = NULL;
    s = malloc(sizeof(char) * 20);
    sprintf(s, "{name: %s, age: %d}", ((struct person*)v)->name, ((struct person*)v)->age);
    return s;
}

struct person*
initializePerson(char* name, int age) {
    struct person *p = malloc(sizeof(struct person));
    // p->name = malloc(sizeof(char) * 20);
    strcpy(p->name, name);
    p->age = age;
    return p;
}








