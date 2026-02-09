#include <stdint.h>

#define NOINLINE __attribute__((noinline))

static int add(int a, int b) { return a + b; }
static int mul(int a, int b) { return a * b; }
static int mod(int a, int b) { return a % b; }

static int compute1(int x) { return add(x, 3); }
static int compute2(int x) { return mul(x, 7); }
static int compute3(int x) { return mod(x, 11); }

static NOINLINE int pipeline(int x) {
  x = compute1(x);
  x = compute2(x);
  x = compute3(x);
  return x;
}

int main() {
  volatile int acc = 0;
  for (int i = 0; i < 150000000; ++i)
    acc += pipeline(i);
  return acc;
}
