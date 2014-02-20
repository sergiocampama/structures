#ifndef _TRIE_TREE_H
#define _TRIE_TREE_H

typedef struct _trie_tree_t {
  char key;
  void *value;
  struct _trie_tree_t *sibling, *child;
} trie_tree_t;

trie_tree_t* trie_tree_create(char key);
void trie_tree_destroy(trie_tree_t *trie);

void trie_add_value_for_key(trie_tree_t *trie, char *key, void *value, size_t size);
void *trie_get_value_for_key(trie_tree_t *trie, char *key);

#endif