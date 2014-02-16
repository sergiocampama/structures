#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hash.h"
#include "list.h"
#include "printer.h"

int main() {
  hash_t *hash = hash_create();
  srand(time(NULL));

  int first = 20;
  int second = 374;
  int third = 617;

  hash_add_value_for_key(hash, "first", &first, sizeof(first));
  hash_add_value_for_key(hash, "second", &second, sizeof(second));
  hash_add_value_for_key(hash, "third", &third, sizeof(third));

  int* value = (int *)hash_get_value_for_key(hash, "first");
  printf("Value saved was %d\n", *value);
  value = (int *)hash_get_value_for_key(hash, "second");
  printf("Value saved was %d\n", *value);
  value = (int *)hash_get_value_for_key(hash, "third");
  printf("Value saved was %d\n", *value);

  hash_delete_value_for_key(hash, "third");

  value = hash_get_value_for_key(hash, "third");
  printf("Value saved was %p\n", value);

  hash_print(hash);
  
  hash_destroy(hash);

  first = 0;
  second = 1;
  third = 2;

  list_t *start = list_create(NULL, NULL, 0);
  list_add(start, list_create("0", &first, sizeof(first)));
  list_add(start, list_create("1", &second, sizeof(second)));
  list_add(start, list_create("2", &third, sizeof(third)));

  list_print(start);

  list_destroy(start);

  return 0;
}
