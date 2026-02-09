#define GEN(N) \
int f##N(int x) { \
  int r = x; \
  for (int i = 0; i < 20; i++) r = r * 33 + i; \
  return r; \
}

GEN(1)  GEN(2)  GEN(3)  GEN(4)  GEN(5)
GEN(6)  GEN(7)  GEN(8)  GEN(9)  GEN(10)
GEN(11) GEN(12) GEN(13) GEN(14) GEN(15)

int main() {
  int s = 0;
  for (int i = 0; i < 2000000; i++) {
    s += f1(i)+f2(i)+f3(i)+f4(i)+f5(i);
  }
  return s;
}
