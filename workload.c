#include "workload.h"
#include "stdint.h"

/*#include "stdio.h"*/

int max(int a, int b) {
  return a > b ? a : b;
}

static int fact(uint64_t Fib) {
  uint64_t i, j;
  int res = 0;
  for (i = 2; i <= Fib; i++) {
    if (Fib % i == 0) {
      int isPrime = 1;
      for (j = 2; j <= i / 2; j++) {
        if (i % j == 0) {
          isPrime = 0;
          break;
        }
      }
      if (isPrime == 1) {
        res = i;
      }
    }
  }

  /*printf("%llu -> %d\n", Fib, res);*/
  return res;
}

/* Largest prime factor of Nth Fibonacci number */
int workload(int N) {
  uint64_t t1 = 0;
  uint64_t t2 = 1;

  /* 65th Fibonacci number is the first one with
     prime factor exceeding 32bit: 0x36E58A951 */
  N = (N <= 64) ? N : 64;

  int i;
  for (i = 1; i < N; ++i) {
    uint64_t nextTerm = t1 + t2;
    t1 = t2;
    t2 = nextTerm;
  }

  return fact(t2);
}
