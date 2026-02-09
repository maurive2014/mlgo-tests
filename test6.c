#include <stdint.h>

#define NOINLINE __attribute__((noinline))

static int is_digit(char c) {
  return c >= '0' && c <= '9';
}

static int value(char c) {
  return c - '0';
}

static NOINLINE int parse(const char *s) {
  int v = 0;
  for (int i = 0; is_digit(s[i]); ++i)
    v = v * 10 + value(s[i]);
  return v;
}

int main() {
  const char *str = "123456789";
  volatile int sum = 0;
  for (int i = 0; i < 200000000; ++i)
    sum += parse(str);
  return sum;
}
