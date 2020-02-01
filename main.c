#include "sub1.h"
#include "sub2.h"
#include "workload.h"
#include "stdlib.h"

int main(int argc, char *argv[]) {
  long arg = 40;
  if (argc > 1) {
    char* p;
    arg = strtol(argv[1], &p, 10);
    if (*p != '\0')
      return 1;
  }

  int MaxFibFact = 0;

  /* sub1 runs workload() once with the given input. */
  MaxFibFact = max(MaxFibFact, sub1(3));

  /* Run workload() on a large input that depends on the program input.
     It's intended to take a second or so. */
  MaxFibFact = max(MaxFibFact, workload(arg));

  /* sub2 calls functions in three other modules.
     These may be compiled ahead of time. */
  MaxFibFact = max(MaxFibFact, sub2(4));

  return (MaxFibFact > 0) ? 0 : 1;
}
