#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hash.h"
#include "list.h"

int main() {
  hash_t *hash = hash_create();
  srand(time(NULL));

  hash_add_value_for_key(hash, "first", 20);
  hash_add_value_for_key(hash, "second", 374);
  hash_add_value_for_key(hash, "third", 617);

  int value = hash_get_value_for_key(hash, "first");
  printf("Value saved was %d\n", value);
  value = hash_get_value_for_key(hash, "second");
  printf("Value saved was %d\n", value);
  value = hash_get_value_for_key(hash, "third");
  printf("Value saved was %d\n", value);

  hash_delete_value_for_key(hash, "third");

  value = hash_get_value_for_key(hash, "third");
  printf("Value saved was %d\n", value);

  hash_print(hash);
  
  hash_destroy(hash);

  list_t *start = list_create("0", 0);
  list_add(start, list_create("1", 1));
  list_add(start, list_create("2", 2));

  list_destroy(start);

  return 0;
}
