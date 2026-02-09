// api.c
static inline int add(int a, int b) { return a + b; }
static inline int mul(int a, int b) { return a * b; }

static int compute(int x) {
  return add(mul(x, 3), 5);
}

int main() {
  int r = 0;
  for (int i = 0; i < 10000000; ++i)
    r += compute(i);
  return r;
}
