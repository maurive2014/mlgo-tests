#include <stdint.h>

#define NOINLINE __attribute__((noinline))

typedef enum { S0, S1, S2, S3 } State;

static State step0(int x) { return (x & 1) ? S1 : S2; }
static State step1(int x) { return (x & 2) ? S3 : S0; }
static State step2(int x) { return (x & 4) ? S0 : S1; }
static State step3(int x) { return (x & 8) ? S2 : S3; }

static NOINLINE State step(State s, int x) {
  switch (s) {
    case S0: return step0(x);
    case S1: return step1(x);
    case S2: return step2(x);
    case S3: return step3(x);
  }
  return S0;
}

int main() {
  State s = S0;
  for (int i = 0; i < 200000000; ++i)
    s = step(s, i);
  return s;
}
