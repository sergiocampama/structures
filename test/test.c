#include <stdio.h>
#include "CuTest.h"

CuSuite *getTestSuite();

void run_tests() {
  CuString *output = CuStringNew();
  CuSuite *suite = CuSuiteNew();

  CuSuiteAddSuite(suite, getTestSuite());
  
  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);

  printf("%s\n", output->buffer);
}

int main() {
  puts("Starting tests:");
  run_tests();
  return 0;
}