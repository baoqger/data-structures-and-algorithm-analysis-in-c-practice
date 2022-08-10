#include <string.h>
#include "dict.h"

static Position find(char* key, HashTable H);
static HashTable rehash(HashTable H);


enum KindOfEntry {Legitimate, Empty, Deleted};

struct data
{
    char Key[20];
    int Value;
};

struct HashEntry
{
  ET Element;
  enum KindOfEntry Info;
};

struct HashTbl
{
  int TableSize;
  int numElements; // keep track of number of elements we store
  Cell *TheCells;
};

HashTable
initializeTable(int TableSize)
{
  HashTable H;
  int i;

  H = malloc(sizeof(struct HashTbl));
  assert(H);

  H->TableSize = TableSize;
  H->numElements = 0;
  H->TheCells = malloc(sizeof(Cell) * H->TableSize);
  assert(H->TheCells);

  for(i = 0; i < H->TableSize; i++)
    H->TheCells[i].Info = Empty;

  return H;
}

void
DestroyTable(HashTable H)
{
  free(H->TheCells);
  free(H);
}

static Position
hash(char *key,
     int TableSize)
{
    unsigned int HashVal = 0;
    while(*key != '\0') {
        HashVal = (HashVal <<  5) + *key++;
    }
    return HashVal % TableSize;
}

/* indicates whehter the currentPos is already tried before or not 
 */
static int
isTried(char *currentPos, HashTable T)
{
  Position tmp = find(currentPos, T);
  if (strcmp(T->TheCells[tmp].Element.Key, currentPos) == 0 &&
      T->TheCells[tmp].Info == Legitimate)
    return 1;
  else
    return 0;
}

static Position
find(char *key,
     HashTable H)
{
  Position currentPos;
  int collisionNum;
  collisionNum = 0;

  // We use another hash table to prevent the infinite loop
  // when certain key cannot be inserted into the target hash table.
  HashTable T = initializeTable(H->TableSize); 
  
  currentPos = hash(key, H->TableSize);

  while(H->TheCells[currentPos].Info != Empty &&
        strcmp(H->TheCells[currentPos].Element.Key, key) != 0)
  {
    currentPos += 2 * ++collisionNum - 1; // quadratic hashing
    if(currentPos >= H->TableSize)
      currentPos -= H->TableSize;
    
    char pos[20];
    sprintf(pos, "%d", currentPos);
    if(isTried(pos, T))
    {
      printf("%s cannot be inserted into the table\n", key);
      break;
    }
    T = put(pos, 777, T); // we don't really care what the corresponding value is
  }
  return currentPos;
}

HashTable
put(char *key,
    int value,
    HashTable H)
{
  Position currentPos;

  currentPos = find(key, H);
  strcpy(H->TheCells[currentPos].Element.Key, key);
  H->TheCells[currentPos].Element.Value = value;
  H->TheCells[currentPos].Info = Legitimate;
  H->numElements++;
  if((float)H->numElements /(float)H->TableSize >= 0.5) // avoid integer division
    H = rehash(H);
  return H;
}
  
int
retrieve(char *key,
         HashTable H)
{
  Position pos = find(key, H);
  return H->TheCells[pos].Element.Value;
}

// judge whether the cell corresponse to the key is empty or not
// return 1 if it's empty; return 0 if it's set with value
int 
keyExist(char *key, HashTable H) {
   Position pos = find(key, H);
   return H->TheCells[pos].Info != Empty;
}

static HashTable
rehash(HashTable H)
{
  HashTable newH = initializeTable(nearestPrime(2*H->TableSize));
  int i;
  for(i = 0; i < H->TableSize; i++)
  { 
      if(H->TheCells[i].Info != Empty ) { // only copy the cell which is not empty
        put(H->TheCells[i].Element.Key, H->TheCells[i].Element.Value, newH);
      }                  
  }
  DestroyTable(H);
  return newH;
}

void
printDictionary(HashTable H)
{
  int i;
  for(i = 0; i < H->TableSize; i++)
  {
    if(H->TheCells[i].Info == Legitimate)
      printf("%d|<%s,%d>\n", i,  H->TheCells[i].Element.Key, H->TheCells[i].Element.Value);
    else
      printf("%d|\n", i);
  }
}

