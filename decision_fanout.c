__attribute__((noinline))
int leaf(int x) { return x * 7 + 3; }

#define CALL(N) int f##N(int x) { return leaf(x) + N; }

CALL(1) CALL(2) CALL(3) CALL(4) CALL(5)
CALL(6) CALL(7) CALL(8) CALL(9) CALL(10)

int main() {
  int s = 0;
  for (int i = 0; i < 1000000; i++) {
    s += f1(i)+f2(i)+f3(i)+f4(i)+f5(i);
  }
  return s;
}
