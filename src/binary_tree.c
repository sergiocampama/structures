#include <stdlib.h>
#include <string.h>

#include "binary_tree.h"

binary_tree_t *binary_tree_create() {
  binary_tree_t *tree = malloc(sizeof(binary_tree_t));
  tree->root = NULL;
  return tree;
}

binary_tree_node_t* binary_tree_node_create(int key, void *value, size_t size) {
  binary_tree_node_t *node = malloc(sizeof(binary_tree_node_t));
  
  node->parent = NULL;
  node->left = NULL;
  node->right = NULL;

  node->key = key;

  if (value != NULL && size > 0) {
    node->value = malloc(size);
    memcpy(node->value, value, size);  
  }
  
  return node;
}

void binary_tree_node_destroy(binary_tree_node_t *node) {
    if (node->left != NULL)
      binary_tree_node_destroy(node->left);
    if (node->right != NULL)
      binary_tree_node_destroy(node->right);

    if (node->value != NULL)
      free(node->value);
    free(node);
}

void binary_tree_destroy(binary_tree_t *tree) {
  //I know I'm missing the nodes
  if (tree->root != NULL)
    binary_tree_node_destroy(tree->root);

  free(tree);
}

binary_tree_node_t* binary_tree_add_value_for_key(binary_tree_t *tree, int key, void *value, size_t size) {
  binary_tree_node_t *node = binary_tree_node_create(key, value, size);

  binary_tree_node_t *tree_node = tree->root, *prev_tree_node = NULL;

  while (tree_node != NULL) {
    prev_tree_node = tree_node;
    if (key >= tree_node->key)
      tree_node = tree_node->right;
    else
      tree_node = tree_node->left;
  }

  node->parent = prev_tree_node;

  if (prev_tree_node == NULL) {
    tree->root = node;
  } else if (key >= prev_tree_node->key) {
    prev_tree_node->right = node;
  } else {
    prev_tree_node->left = node;
  }

  return node;
}

binary_tree_node_t* binary_tree_get_node_for_key(binary_tree_t *tree, int key) {
  binary_tree_node_t *node = tree->root;

  while (node != NULL && node->key != key) {
    if (key > node->key)
      node = node->right;
    else if (key < node->key)
      node = node->left;
  }

  return node;
}

void binary_tree_transplant(binary_tree_t *tree, binary_tree_node_t *old_node, binary_tree_node_t *new_node) {
  if (old_node->parent == NULL) {
    tree->root = new_node;
  } else if (old_node->parent->left == old_node) {
    old_node->parent->left = new_node;
  } else {
    old_node->parent->right = new_node;
  }

  if (new_node != NULL)
    new_node->parent = old_node->parent;
}

void binary_tree_delete_node(binary_tree_t *tree, binary_tree_node_t *node) {
  if (node->left == NULL)
    binary_tree_transplant(tree, node, node->right);
  else if (node->right == NULL)
    binary_tree_transplant(tree, node, node->left);
  else {

    binary_tree_node_t *successor = binary_tree_node_successor(node);
    
    if (successor->parent != node) {
      binary_tree_transplant(tree, successor, successor->right);
      successor->right = node->right;
      successor->right->parent = successor;
    }
    binary_tree_transplant(tree, node, successor);
    successor->left = node->left;
    successor->left->parent = successor;
  }

  node->left = NULL;
  node->right = NULL;

  binary_tree_node_destroy(node);
}

binary_tree_node_t* binary_tree_node_maximum(binary_tree_node_t *node) {
  if (node == NULL)
    return NULL;

  while(node->right != NULL)
    node = node->right;

  return node;
}

binary_tree_node_t* binary_tree_node_minimum(binary_tree_node_t *node) {
  if (node == NULL)
    return NULL;

  while(node->left != NULL)
    node = node->left;

  return node;
}

binary_tree_node_t* binary_tree_node_successor(binary_tree_node_t *node) {
  if (node->right != NULL)
    return binary_tree_node_minimum(node->right);

  while (node->parent != NULL && node->parent->right == node) {
    node = node->parent;
  }

  return node->parent;

}

binary_tree_node_t* binary_tree_node_predecessor(binary_tree_node_t *node) {
  if (node->left != NULL)
      return binary_tree_node_maximum(node->left);

    while (node->parent != NULL && node->parent->left == node) {
      node = node->parent;
    }

    return node->parent;
}

