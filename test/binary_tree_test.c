#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CuTest.h"

#include "binary_tree.h"

CuSuite* getBinaryTreeTestSuite()
{
  CuSuite* suite = CuSuiteNew();

  return suite;
}
