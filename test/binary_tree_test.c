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
  binary_tree_destroy(tree);
}

CuSuite* getBinaryTreeTestSuite()
{
  CuSuite* suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, TestBinaryTreeCreate);
  SUITE_ADD_TEST(suite, TestBinaryTreeAdd);

  return suite;
}
