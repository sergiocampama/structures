#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CuTest.h"

#include "binary_tree.h"

void TestBinaryTreeCreate(CuTest* tc)
{
  binary_tree_t *tree = binary_tree_create();
  
  CuAssert(tc, "binary_tree_create does not return NULL", NULL != tree);
  binary_tree_destroy(tree);
}

void TestBinaryTreeAdd(CuTest* tc)
{
  binary_tree_t *tree = binary_tree_create();
  
  int value = 25;
  binary_tree_add_value_for_key(tree, 5, &value, sizeof(value));
  binary_tree_node_t *node = binary_tree_get_node_for_key(tree, 5);
  
  CuAssert(tc, "binary_tree_add_value_for_key adds correct value", *((int *)(node->value)) == value);
  CuAssert(tc, "tree->root is correctly set for first node", tree->root == node);
  binary_tree_destroy(tree);
}

void TestBinaryTreeAddLeftChild(CuTest* tc)
{
  binary_tree_t *tree = binary_tree_create();
  
  int value = 25;
  binary_tree_add_value_for_key(tree, 5, &value, sizeof(value));
  binary_tree_add_value_for_key(tree, 2, &value, sizeof(value));
  
  binary_tree_node_t *node = binary_tree_get_node_for_key(tree, 2);
  
  CuAssert(tc, "binary_tree_add_value_for_key set node as child of root", node->parent == tree->root);
  CuAssert(tc, "node is correctly set as left child", tree->root->left == node);
  binary_tree_destroy(tree);
}

void TestBinaryTreeAddRightChild(CuTest* tc)
{
  binary_tree_t *tree = binary_tree_create();
  
  int value = 25;
  binary_tree_add_value_for_key(tree, 5, &value, sizeof(value));
  binary_tree_add_value_for_key(tree, 7, &value, sizeof(value));
  
  binary_tree_node_t *node = binary_tree_get_node_for_key(tree, 7);
  
  CuAssert(tc, "binary_tree_add_value_for_key set node as child of root", node->parent == tree->root);
  CuAssert(tc, "node is correctly set as right child", tree->root->right == node);
  binary_tree_destroy(tree);
}

void TestBinaryTreeSuccessor(CuTest* tc)
{
  binary_tree_t *tree = binary_tree_create();
  
  int value = 25;
  binary_tree_add_value_for_key(tree, 5, &value, sizeof(value));
  binary_tree_node_t *last_node = binary_tree_add_value_for_key(tree, 7, &value, sizeof(value));
  binary_tree_add_value_for_key(tree, 6, &value, sizeof(value));
  
  binary_tree_node_t *node1 = binary_tree_node_successor(tree->root);
  binary_tree_node_t *node2 = binary_tree_node_successor(last_node);

  CuAssert(tc, "successor exists", node1->key == 6);
  CuAssert(tc, "successor does not exist", node2 == NULL);
  binary_tree_destroy(tree);
}

void TestBinaryTreePredecessor(CuTest* tc)
{
  binary_tree_t *tree = binary_tree_create();
  
  int value = 25;
  binary_tree_add_value_for_key(tree, 5, &value, sizeof(value));
  binary_tree_node_t *first_node = binary_tree_add_value_for_key(tree, 3, &value, sizeof(value));
  binary_tree_add_value_for_key(tree, 4, &value, sizeof(value));
  
  binary_tree_node_t *node1 = binary_tree_node_predecessor(tree->root);
  binary_tree_node_t *node2 = binary_tree_node_predecessor(first_node);

  CuAssert(tc, "predecessor exists", node1->key == 4);
  CuAssert(tc, "predecessor does not exist", node2 == NULL);
  binary_tree_destroy(tree);
}

void TestBinaryTreeDelete(CuTest* tc)
{
  binary_tree_t *tree = binary_tree_create();
  
  int value = 25;
  binary_tree_add_value_for_key(tree, 5, &value, sizeof(value));
  binary_tree_node_t *new_root = binary_tree_add_value_for_key(tree, 10, &value, sizeof(value));
  binary_tree_add_value_for_key(tree, 9, &value, sizeof(value));
  binary_tree_add_value_for_key(tree, 8, &value, sizeof(value));
  
  binary_tree_delete_node(tree, tree->root);

  CuAssert(tc, "root gets correctly changed", tree->root->key == 10);

  binary_tree_add_value_for_key(tree, 4, &value, sizeof(value));
  binary_tree_delete_node(tree, tree->root);

  CuAssert(tc, "root gets correctly changed", tree->root->key == 9);

  binary_tree_add_value_for_key(tree, 15, &value, sizeof(value));
  binary_tree_add_value_for_key(tree, 10, &value, sizeof(value));
  
  binary_tree_delete_node(tree, tree->root);

  CuAssert(tc, "root gets correctly changed", tree->root->key == 10);
  
  binary_tree_destroy(tree);
}

CuSuite* getBinaryTreeTestSuite()
{
  CuSuite* suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, TestBinaryTreeCreate);
  SUITE_ADD_TEST(suite, TestBinaryTreeAdd);
  SUITE_ADD_TEST(suite, TestBinaryTreeAddLeftChild);
  SUITE_ADD_TEST(suite, TestBinaryTreeAddRightChild);
  SUITE_ADD_TEST(suite, TestBinaryTreeSuccessor);
  SUITE_ADD_TEST(suite, TestBinaryTreePredecessor);
  SUITE_ADD_TEST(suite, TestBinaryTreeDelete);

  return suite;
}
