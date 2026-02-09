#include <stdint.h>

#define NOINLINE __attribute__((noinline))
#define N 1024

static uint32_t hash(uint32_t x) {
  x ^= x >> 16;
  x *= 0x7feb352d;
  x ^= x >> 15;
  return x & (N - 1);
}

static NOINLINE int lookup(int *t, int k) {
  uint32_t h = hash(k);
  return t[h];
}

int main() {
  static int table[N];
  for (int i = 0; i < N; ++i) table[i] = i;

  volatile int sum = 0;
  for (int i = 0; i < 200000000; ++i)
    sum += lookup(table, i);
  return sum;
}
