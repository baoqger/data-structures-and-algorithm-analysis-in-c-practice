#include <string.h>
#include "dict.h"
#include "person.h"

void test_hash();
void test_dictionary_value_int(); 
void test_dictionary_value_str();
void test_dictionary_value_person();
void test_dictionary_reput();
void test_dictionary_removeKey();
void test_dictionary_removeKey_collision(); 
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

  test_hash();
  test_dictionary_value_int();
  test_dictionary_value_str();
  test_dictionary_value_person();
  test_keyExist();
  test_dictionary_reput();
  test_dictionary_removeKey();
  test_dictionary_removeKey_collision();
  return 0;
}


void 
test_hash() {
    printf("TEST: generic dictionary hash function.\n");
    char *key1 = "3344ok";
    char *key2 = "4433ok";
    char *key3 = "123456";
    int TableSize = 10;
    printf("hash of %s is : %d.\n", key1, hash(key1, TableSize));
    printf("hash of %s is : %d.\n", key2, hash(key2, TableSize));
    printf("hash of %s is : %d.\n", key3, hash(key3, TableSize));
    printf("simple hash of %s is : %d.\n", key1, simpleHash(key1, TableSize));
    printf("simple hash of %s is : %d.\n", key2, simpleHash(key2, TableSize));
    printf("simple hash of %s is : %d.\n", key3, simpleHash(key3, TableSize));

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
test_dictionary_reput() {
    printf("\nTEST: generic dictionary reput with identical keys\n");
    HashTable H = initializeTable(4);
    printDictionary(H, print_value_person);
    printf("\n");
    printf("put 3344ok: {roro: 18} into the dictionary.\n\n");
    struct person *p3 = initializePerson("roro", 18);
    H = put("3344ok",(void*)p3, H);
    printDictionary(H, print_value_person);

    printf("put 334404 again, this time value changes to {roro: 19}.\n\n");
    struct person *p4 = initializePerson("roro", 19);
    H = put("3344ok", (void*)p4, H); 
    printDictionary(H, print_value_person);
  
    DestroyTable(H);
}

void 
test_keyExist() {
    printf("TEST: dictionary keyExist.\n");
    HashTable H = initializeTable(4);
    printDictionary(H, print_value_person);
    printf("\n");
    // if the target key does not exist, add the object
    // else update the object
    if (!keyExist("3344ok", H)) {
        printf("key 33440k doesn't exist. Add it.\n\n");
        struct person *roro = initializePerson("roro", 17);
        H = put("3344ok", (void*)roro, H);
        printDictionary(H, print_value_person);
    }
    if (keyExist("3344ok", H)) {
        printf("key 33440k exist. Update it\n\n");
        struct person *roro = retrieve("3344ok", H);
        roro->age += 1;
        printDictionary(H, print_value_person);
    }

    DestroyTable(H);

}

void 
test_dictionary_removeKey() {
    printf("TEST: dictionary removeKey.\n");
    HashTable H = initializeTable(4);
    printDictionary(H, print_value_person);
    printf("\n");
    // if the target key does not exist, add the object
    // else update the object
    if (!keyExist("3344ok", H)) {
        printf("key 33440k doesn't exist. Add it.\n\n");
        struct person *roro = initializePerson("roro", 17);
        H = put("3344ok", (void*)roro, H);
        printDictionary(H, print_value_person);
    }
    printf("\n key 3344ok %s\n", keyExist("3344ok", H) ? "exist" : "doesn't exist" ); 
    printf("remove key 3344ok.\n");
    H = removeKey("3344ok", H);
    printDictionary(H, print_value_person); 
    printf("\n key 3344ok %s\n", keyExist("3344ok", H) ? "exist" : "doesn't exist" ); 
    
    printf("reput key 3344ok with {chris, 36}.\n");
    struct person *chris = initializePerson("chris", 36);
    H = put("3344ok", chris, H);
    printDictionary(H, print_value_person);
    DestroyTable(H);

}

void  
test_dictionary_removeKey_collision() {
    printf("Test removekey and collision resolution.\n");
    HashTable H = initializeTable(4);
    struct person *roro = initializePerson("roro", 17);
    struct person *chris = initializePerson("chris", 36);
    H = put("3344ok", roro, H);
    H = put("4433ok", chris, H);
    printDictionary(H, print_value_person);
    
    printf("remove key 3344ok\n");
    H = removeKey("3344ok", H);
    printDictionary(H, print_value_person);
    printf("\n key 4433ok %s\n", keyExist("4433ok", H) ? "exist" : "doesn't exist");
    printf("\n key 5533ok %s\n", keyExist("5533ok", H) ? "exist" : "doesn't exist");
    printf("put 7788ab: {jack, 50}\n");
    struct person *jack = initializePerson("jack", 50);
    H = put("7788ab", jack, H);
    printDictionary(H, print_value_person);
    DestroyTable(H);
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


