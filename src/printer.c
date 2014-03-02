#include <stdio.h>
#include "printer.h"

void hash_print(hash_t *hash) {
  for (int i = 0; i < hash->table_size; i++) {
    if (hash->table[i] != NULL) {
      printf("Table index %d: \n", i);  
      list_print(hash->table[i]);
    }
  }
}

void list_print(list_t *list) {
  int i = 0;
  while (list != NULL) {
    if (list->key != NULL) 
      printf("Node %d: Key: %s => Value: %d\n", i++, list->key, *((int *)list->value));
    else
      printf("Node %d: Sentinel\n", i++);
    list = list->next;
  }
}

void binary_tree_print(binary_tree_t *tree) {

}