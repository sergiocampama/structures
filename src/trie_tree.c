#include <stdlib.h>
#include <string.h>

#include "trie_tree.h"

trie_tree_t* trie_tree_create(char key) {
  trie_tree_t *trie = malloc(sizeof(trie_tree_t));
  trie->key = key;
  trie->value = NULL;
  trie->sibling = NULL;
  trie->child = NULL;
  return trie;
}

void trie_tree_destroy(trie_tree_t *trie) {
  trie_tree_t *sibling = trie->sibling, *child = trie->child;

  if (sibling != NULL)
    trie_tree_destroy(sibling);

  if (child != NULL)
    trie_tree_destroy(child);

  if (trie->value != NULL)
    free(trie->value);
  free(trie);
}

void trie_tree_set_value(trie_tree_t *trie, void *value, size_t size) {
  if (trie->value != NULL)
    free(trie->value);
  if (value != NULL && size > 0) {
    trie->value = malloc(size);
    memcpy(trie->value, value, size);
  }
}

void trie_add_value_for_key(trie_tree_t *trie, char *key, void *value, size_t size)
{
  trie_tree_t *parent = trie, *older_sibling;
  trie_tree_t *child = parent->child;
  
  int length = strlen(key); 
  for (int i = 0; i < length; i++) {

    if (child == NULL) {
      //Create first node in parent
      parent->child = trie_tree_create(key[i]);
    } else {
      older_sibling = NULL;
      while(child != NULL && child->key != key[i]) {
        older_sibling = child;
        child = child->sibling;
      }
      if (child == NULL) {
        child = trie_tree_create(key[i]); 
        older_sibling->sibling = child;
      }
    }

    parent = child;
    child = parent->child;
  }

  trie_tree_set_value(parent, value, size);
}

void *trie_get_value_for_key(trie_tree_t *trie, char *key)
{
  trie_tree_t *child = trie->child;

  int length = strlen(key); 
  for (int i = 0; i < length; i++) {

    while(child != NULL && child->key != key[i]) {
      child = child->sibling;
    }

    if (child == NULL) {
      return NULL;
    }

    child = child->child;
  }

  if (child == NULL) {
    return NULL;
  }

  return child->value;
}