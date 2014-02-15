#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hash.h"
#include "list.h"

int main() {
  hash_t *hash = hash_create();
  srand(time(NULL));

  hash_add_value_for_key(hash, "hola", 20);
  hash_add_value_for_key(hash, "caca", 374);
  hash_add_value_for_key(hash, "peo", 617);
  int value = hash_get_value_for_key(hash, "hola");
  printf("Value saved was %d\n", value);
  value = hash_get_value_for_key(hash, "caca");
  printf("Value saved was %d\n", value);
  value = hash_get_value_for_key(hash, "peo");
  printf("Value saved was %d\n", value);

  hash_delete_value_for_key(hash, "peo");

  value = hash_get_value_for_key(hash, "peo");
  printf("Value saved was %d\n", value);

  
  hash_destroy(hash);

  list_t *start = list_create("0", 0);
  list_add(&start, list_create("1", 1));
  list_add(&start, list_create("2", 2));

  list_print(start);
  list_destroy(start);

  return 0;
}
