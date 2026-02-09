#include <stdint.h>

#define NOINLINE __attribute__((noinline))

static int clamp(int x) {
  if (x < 0) return 0;
  if (x > 255) return 255;
  return x;
}

static int f1(int x) { return clamp(x + 1); }
static int f2(int x) { return clamp(x * 2); }
static int f3(int x) { return clamp(x - 3); }
static int f4(int x) { return clamp(x ^ 4); }
static int f5(int x) { return clamp(x + 5); }

static NOINLINE int process(int x) {
  x = f1(x);
  x = f2(x);
  x = f3(x);
  x = f4(x);
  x = f5(x);
  return x;
}

int main() {
  volatile int acc = 0;
  for (int i = 0; i < 150000000; ++i)
    acc += process(i & 255);
  return acc;
}
