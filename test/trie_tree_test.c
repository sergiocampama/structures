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

void TestTrieTreeAdd(CuTest* tc)
{
  trie_tree_t *trie = trie_tree_create(0);
  int number = 45;
  trie_tree_add_value_for_key(trie, "hello", &number, sizeof(number));
  int *value = (int *)trie_tree_get_value_for_key(trie, "hello");
  CuAssert(tc, "trie_tree_add_value_for_key sets the correct value", *value == number);
  trie_tree_destroy(trie);
}

void TestTrieTreeReplace(CuTest* tc)
{
  trie_tree_t *trie = trie_tree_create(0);
  int number = 45;
  trie_tree_add_value_for_key(trie, "hello", &number, sizeof(number));
  number = 23;
  trie_tree_add_value_for_key(trie, "hello", &number, sizeof(number));
  int *value = (int *)trie_tree_get_value_for_key(trie, "hello");
  CuAssert(tc, "trie_tree_add_value_for_key replaces the original value", *value == number);
  trie_tree_destroy(trie);
}

void TestTrieTreeAddSubKeys(CuTest* tc)
{
  trie_tree_t *trie = trie_tree_create(0);
  int number1 = 45;
  int number2 = 23;

  trie_tree_add_value_for_key(trie, "hello", &number1, sizeof(number1));
  trie_tree_add_value_for_key(trie, "goodbye", &number2, sizeof(number2));

  int *value1 = (int *)trie_tree_get_value_for_key(trie, "hello");
  int *value2 = (int *)trie_tree_get_value_for_key(trie, "goodbye");

  CuAssert(tc, "trie_tree works with multiple keys", *value1 == number1 && *value2 == number2);

  trie_tree_destroy(trie);
}

CuSuite* getTrieTreeTestSuite()
{
  CuSuite* suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, TestTrieTreeCreate);
  SUITE_ADD_TEST(suite, TestTrieTreeAdd);
  SUITE_ADD_TEST(suite, TestTrieTreeReplace);
  SUITE_ADD_TEST(suite, TestTrieTreeAddSubKeys);

  return suite;
}