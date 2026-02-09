#include <stdint.h>

#define NOINLINE __attribute__((noinline))

static int add(int a, int b) { return a + b; }
static int mul(int a, int b) { return a * b; }
static int sub(int a, int b) { return a - b; }

static NOINLINE int eval(int x) {
  int r = x;
  r = add(r, 3);
  r = mul(r, 5);
  r = sub(r, 7);
  return r;
}

int main() {
  volatile int acc = 0;
  for (int i = 0; i < 200000000; ++i)
    acc += eval(i);
  return acc;
}
