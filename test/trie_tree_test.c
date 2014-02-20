#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CuTest.h"

#include "trie_tree.h"

void TestTrieTreeCreate(CuTest* tc)
{
  trie_tree_t *trie = trie_tree_create(0);
  CuAssert(tc, "trie_tree_create does not return NULL", NULL != trie);
  trie_tree_destroy(trie);
}

CuSuite* getTrieTreeTestSuite(void)
{
  CuSuite* suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, TestTrieTreeCreate);

  return suite;
}