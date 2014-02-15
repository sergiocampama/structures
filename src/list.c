#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

list_t* list_create(const char *key, int value)
{
  list_t *new_list = malloc(sizeof(list_t));
  new_list->next = NULL;
  new_list->prev = NULL;
  if (key != NULL) {
    new_list->key = malloc(strlen(key) + 1);
    strcpy(new_list->key, key);
  }
  new_list->value = value;

  return new_list;
}

void list_destroy(list_t *list)
{
  while (list != NULL) {
    list_t *old_list = list;
    list = list->next;
    free(old_list->key);
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

void list_print(list_t *list) {
  int i = 1;
  while (list != NULL) {
    if (list->key != NULL) 
      printf("Node %d: Key: %s => Value: %d\n", i++, list->key, list->value);
    else
      printf("Node %d: Sentinel\n", i++);
    list = list->next;
  }
}
