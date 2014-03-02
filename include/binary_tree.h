#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

typedef struct _binary_tree_node_t {
  struct _binary_tree_node_t *parent, *left, *right;
  int key;
  void *value;
} binary_tree_node_t;

typedef struct _binary_tree_t {
  struct _binary_tree_node_t *root;
} binary_tree_t;

binary_tree_t* binary_tree_create();
void binary_tree_destroy(binary_tree_t *tree);

void binary_tree_add_value_for_key(binary_tree_t *tree, int key, void *value, size_t size);
binary_tree_node_t* binary_tree_get_node_for_key(binary_tree_t *tree, int key);
void binary_tree_delete_node(binary_tree_t *tree, binary_tree_node_t *node);

binary_tree_node_t* binary_tree_node_maximum(binary_tree_node_t *node);
binary_tree_node_t* binary_tree_node_minimum(binary_tree_node_t *node);

binary_tree_node_t* binary_tree_node_successor(binary_tree_node_t *node);
binary_tree_node_t* binary_tree_node_predecessor(binary_tree_node_t *node);

#endif