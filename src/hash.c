#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

hash_t* hash_create() {
  hash_t *hash = malloc(sizeof(hash_t));

  hash->table_size = HASH_TABLE_SIZE;
  hash->param_p = HASH_BIG_PRIME;
  hash->param_a = (rand() % (hash->param_p - 2)) + 1;
  hash->param_b = rand() % (hash->param_p - 1);

  for (int i = 0; i < hash->table_size; i++) 
    hash->table[i] = NULL;

  return hash;
}

void hash_destroy(hash_t *hash) {
  for(int i = 0; i < hash->table_size; i++) {
    list_destroy((hash->table)[i]);
  }
  free(hash);
}

int hash_index_for_key(hash_t *hash, const char *key) {
  int length = strlen(key);
  int converted_key = 0;
  for (int i = 0; i < length; i++)
    converted_key = HASH_RADIX * converted_key + (int)key[i];

  return ((hash->param_a * converted_key + hash->param_b) % hash->param_p) % hash->table_size;
}

void hash_add_value_for_key(hash_t *hash, const char *key, int value) {
  int table_index = hash_index_for_key(hash, key);

  if ((hash->table)[table_index] == NULL)
    (hash->table)[table_index] = list_create(NULL, 0);

  list_add((hash->table)[table_index], list_create(key, value));
}

int hash_get_value_for_key(hash_t *hash, const char *key) {
  int table_index = hash_index_for_key(hash, key);

  list_t *list = (hash->table)[table_index];
  list_t *key_node = list_find_by_key(list, key);
  if (key_node == NULL)
    return 0;
  return key_node->value;
}

void hash_delete_value_for_key(hash_t *hash, const char *key)
{
  int table_index = hash_index_for_key(hash, key);

  list_t **list = &((hash->table)[table_index]);
  list_t *key_node = list_find_by_key(*list, key);
  if (key_node != NULL)
    list_remove(key_node);

}

void hash_print(hash_t *hash) {
  for (int i = 0; i < hash->table_size; i++) {
    if (hash->table[i] != NULL) {
      printf("Table index %d: \n", i);  
      list_print(hash->table[i]);
    }
  }
    
}
