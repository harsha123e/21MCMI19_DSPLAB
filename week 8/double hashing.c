#include <stdio.h>

#include<stdlib.h>

#define TABLE_SIZE 10

int h[TABLE_SIZE] = {NULL};

void insert() {

  int key, index, i, flag = 0, hkey, hash2;
  printf("\nEnter a value to insert into hash table\n");
  scanf("%d", & key);
  hkey = key % TABLE_SIZE;
  hash2 = 7 - (key % 7);
  for (i = 0; i < TABLE_SIZE; i++) {
    index = (hkey + i * hash2) % TABLE_SIZE;
    if (h[index] == NULL) {
      h[index] = key;
      break;
    }
  }
  if (i == TABLE_SIZE)
    printf("\nElement cannot be inserted\n");
}
int search() {
  int key, index, i, flag = 0, hash2, hkey;
  printf("\nEnter element\n");
  scanf("%d", & key);
  hkey = key % TABLE_SIZE;
  hash2 = 7 - (key % 7);
  for (i = 0; i < TABLE_SIZE; i++) {
    index = (hkey + i * hash2) % TABLE_SIZE;
    if (h[index] == key)
      return index;
  }
  if (i == TABLE_SIZE)
    return -1;
}
void display() {

  int i;
  printf("\nelements in the hash table are \n");
  for (i = 0; i < TABLE_SIZE; i++)
    printf("\nat index %d \t value =  %d", i, h[i]);

}
void _delete() {
  int i = search();
  if (i == -1)
    printf("Element not found\n");
  else
    h[i] = NULL;
}
int main() {
  int opt, i;
  while (1) {
    printf("\nPress ");
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Display");
    printf("\n4. Search");
    printf("\n5.Exit\n");
    scanf("%d", & opt);
    if (opt == 1)
      insert();
    if (opt == 2)
      _delete();
    if (opt == 3)
      display();
    if (opt == 4) {
      i = search();
      if (i == -1)
        printf("Element not found\n");
      else
        printf("Element found at index %d\n", i);
    }
    if (opt == 5)
      exit(0);

  }
  return 0;
}
