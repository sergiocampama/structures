#ifndef _LIST_H
#define _LIST_H

typedef struct _list_t {
  struct _list_t *next;
  struct _list_t *prev;
  char *key;
  int value;
} list_t;

list_t* list_create(const char *key, int value);
void list_destroy(list_t *list);

void list_add(list_t *list, list_t *new_list);
void list_remove(list_t *old_list);
list_t* list_find_by_key(list_t *list, const char *key);

void list_print(list_t *list);

#endif
