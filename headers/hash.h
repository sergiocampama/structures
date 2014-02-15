#include "list.h"

#ifndef _HASH_H
#define _HASH_H

#define HASH_TABLE_SIZE 100
#define HASH_BIG_PRIME 982451653LLU
#define HASH_RADIX 128

typedef struct _hash_t {
  list_t* table[HASH_TABLE_SIZE];
  int table_size;
  int param_a;
  int param_b;
  long long unsigned param_p;
} hash_t;

hash_t* hash_create();
void hash_destroy();

void hash_add_value_for_key(hash_t *hash, const char *key, int value);
int hash_get_value_for_key(hash_t *hash, const char *key);
void hash_delete_value_for_key(hash_t *hash, const char *key);

void hash_print(hash_t *hash);

#endif
