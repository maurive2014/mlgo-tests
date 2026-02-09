__attribute__((noinline)) int hot(int x) {
  return x * 3 + 1;
}

int a(int x) { return hot(x) + 1; }
int b(int x) { return hot(x) + 2; }
int c(int x) { return hot(x) + 3; }
int d(int x) { return hot(x) + 4; }
int e(int x) { return hot(x) + 5; }

int main() {
  int s = 0;
  for (int i = 0; i < 1000000; i++) {
    s += a(i);
    s += b(i);
    s += c(i);
    s += d(i);
    s += e(i);
  }
  return s;
}
