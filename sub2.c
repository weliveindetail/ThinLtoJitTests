#include "sub2.h"
#include "sub21.h"
#include "sub22.h"
#include "sub23.h"
#include "workload.h"

int sub2(int argc) {
  int MaxFibFact = 0;
  MaxFibFact = max(MaxFibFact, sub21(argc));
  MaxFibFact = max(MaxFibFact, sub22(argc + 1));
  MaxFibFact = max(MaxFibFact, sub23(argc + 2));
  return MaxFibFact;
}
