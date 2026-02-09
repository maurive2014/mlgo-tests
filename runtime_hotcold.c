#include <stdio.h>

__attribute__((noinline))
int cold(int x) {
  volatile int r = x;
  for (int i = 0; i < 800; i++)
    r = r * 31 + i;
  return r;
}

int hot(int x) {
  return x + 1;
}

int f(int x) {
  if (__builtin_expect(x == 1234567, 0))
    return cold(x);
  return hot(x);
}

int main() {
  int s = 0;
  for (int i = 0; i < 30000000; i++)
    s += f(i);
  printf("%d\n", s);
}
