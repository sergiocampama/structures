#include <stdio.h>
#include "CuTest.h"

CuSuite* getHashTestSuite();
CuSuite* getTrieTreeTestSuite();
CuSuite* getBinaryTreeTestSuite();

void run_tests() {
  CuString *output = CuStringNew();
  CuSuite *suite = CuSuiteNew();

  CuSuiteAddSuite(suite, getHashTestSuite());
  CuSuiteAddSuite(suite, getTrieTreeTestSuite());
  CuSuiteAddSuite(suite, getBinaryTreeTestSuite());
  
  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);

  printf("%s\n", output->buffer);
}

int main() {
  run_tests();
  return 0;
}