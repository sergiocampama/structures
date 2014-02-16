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
}

CuSuite* getTestSuite(void)
{
  CuSuite* suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, TestHashCreate);
  /*SUITE_ADD_TEST(suite, TestCuStrCopy);
  SUITE_ADD_TEST(suite, TestFail);
  SUITE_ADD_TEST(suite, TestAssertStrEquals);
  SUITE_ADD_TEST(suite, TestAssertStrEquals_NULL);
  SUITE_ADD_TEST(suite, TestAssertStrEquals_FailStrNULL);
  SUITE_ADD_TEST(suite, TestAssertStrEquals_FailNULLStr);
  SUITE_ADD_TEST(suite, TestAssertIntEquals);
  SUITE_ADD_TEST(suite, TestAssertDblEquals);

  SUITE_ADD_TEST(suite, TestCuTestNew);
  SUITE_ADD_TEST(suite, TestCuTestInit);
  SUITE_ADD_TEST(suite, TestCuAssert);
  SUITE_ADD_TEST(suite, TestCuAssertPtrEquals_Success);
  SUITE_ADD_TEST(suite, TestCuAssertPtrEquals_Failure);
  SUITE_ADD_TEST(suite, TestCuAssertPtrNotNull_Success);
  SUITE_ADD_TEST(suite, TestCuAssertPtrNotNull_Failure);
  SUITE_ADD_TEST(suite, TestCuTestRun);

  SUITE_ADD_TEST(suite, TestCuSuiteInit);
  SUITE_ADD_TEST(suite, TestCuSuiteNew);
  SUITE_ADD_TEST(suite, TestCuSuiteAddTest);
  SUITE_ADD_TEST(suite, TestCuSuiteAddSuite);
  SUITE_ADD_TEST(suite, TestCuSuiteRun);
  SUITE_ADD_TEST(suite, TestCuSuiteSummary);
  SUITE_ADD_TEST(suite, TestCuSuiteDetails_SingleFail);
  SUITE_ADD_TEST(suite, TestCuSuiteDetails_SinglePass);
  SUITE_ADD_TEST(suite, TestCuSuiteDetails_MultiplePasses);
  SUITE_ADD_TEST(suite, TestCuSuiteDetails_MultipleFails);*/

  return suite;
}
