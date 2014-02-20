#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t* list_create(const char *key, void *value, size_t size)
{
  list_t *new_list = malloc(sizeof(list_t));
  new_list->next = NULL;
  new_list->prev = NULL;
  new_list->key = NULL;
  new_list->value = NULL;

  if (key != NULL) {
    new_list->key = malloc(strlen(key) + 1);
    strcpy(new_list->key, key);
  }
  if (value != NULL && size > 0) {
    new_list->value = malloc(size);
    memcpy(new_list->value, value, size);
  }

  return new_list;
}

void list_update(list_t *list, void *value, size_t size)
{
  if (list->value != NULL) 
    free(list->value);

  if (value != NULL) {
    list->value = malloc(size);
    memcpy(list->value, value, size);
  }
}

void list_destroy(list_t *list)
{
  while (list != NULL) {
    list_t *old_list = list;
    list = list->next;
    if (old_list->key != NULL)
      free(old_list->key);
    if (old_list->value != NULL)
      free(old_list->value);
    free(old_list);
  }
}

void list_add(list_t *list, list_t *new_list)
{
  while (list->next != NULL) 
    list = list->next;

  list->next = new_list;
  new_list->prev = list;
}

void list_remove(list_t *old_list)
{
  old_list->prev->next = old_list->next;
  if (old_list->next != NULL)
    old_list->next->prev = old_list->prev;

  free(old_list);
}

list_t* list_find_by_key(list_t *list, const char *key)
{
  while(list != NULL) {
    if (list->key != NULL && strcmp(key, list->key) == 0)
      return list;
    list = list->next;
  }

  return NULL;
}
