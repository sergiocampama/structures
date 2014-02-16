#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CuTest.h"

#include "hash.h"
#include "list.h"

void TestHashCreate(CuTest* tc)
{
  hash_t *hash = hash_create();
  CuAssert(tc, "hash_create does not return NULL", NULL != hash);
  hash_destroy(hash);
}

void TestHashAddValue(CuTest* tc)
{
  hash_t *hash = hash_create();
  int number = 20;
  hash_add_value_for_key(hash, "test", &number, sizeof(number));
  void *value = hash_get_value_for_key(hash, "test");

  CuAssert(tc, "hash_get_value_for_key does not return NULL for valid key", value != NULL);
  CuAssert(tc, "hash_get_value_for_key returns correct value", *((int *)value) == 20);
  hash_destroy(hash);
}

void TestHashRemoveValue(CuTest* tc)
{
  hash_t *hash = hash_create();
  int number = 20;
  hash_add_value_for_key(hash, "test", &number, sizeof(number));
  hash_delete_value_for_key(hash, "test");
  void *value = hash_get_value_for_key(hash, "test");

  CuAssert(tc, "hash_get_value_for_key does return NULL for removed key", value == NULL);
  hash_destroy(hash);
}

void TestHashAddAndRemoveValue(CuTest* tc)
{
  hash_t *hash = hash_create();
  int number = 20;
  hash_add_value_for_key(hash, "test", &number, sizeof(number));
  int int_value1 = *((int *)hash_get_value_for_key(hash, "test"));
  number = 40;
  hash_add_value_for_key(hash, "test", &number, sizeof(number));
  int int_value2 = *((int *)hash_get_value_for_key(hash, "test"));
  hash_delete_value_for_key(hash, "test");
  void *value = hash_get_value_for_key(hash, "test");

  CuAssert(tc, "hash_add_value_for_key sets correct value", int_value1 == 20);
  CuAssert(tc, "hash_get_value_for_key updates correct value", int_value2 == 40);
  CuAssert(tc, "hash_get_value_for_key does return NULL for removed key", value == NULL);
  hash_destroy(hash);
}

CuSuite* getTestSuite(void)
{
  CuSuite* suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, TestHashCreate);
  SUITE_ADD_TEST(suite, TestHashAddValue);
  SUITE_ADD_TEST(suite, TestHashRemoveValue);
  SUITE_ADD_TEST(suite, TestHashAddAndRemoveValue);

  return suite;
}
