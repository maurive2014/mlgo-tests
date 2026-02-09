__attribute__((noinline))
int heavy(int x) {
  int r = x;
  for (int i = 0; i < 20; i++)
    r = r * 33 + i;
  return r;
}

int f1(int x) { return heavy(x) + 1; }
int f2(int x) { return heavy(x) + 2; }
int f3(int x) { return heavy(x) + 3; }
int f4(int x) { return heavy(x) + 4; }
int f5(int x) { return heavy(x) + 5; }

int main() {
  int s = 0;
  for (int i = 0; i < 500000; i++) {
    s += f1(i) + f2(i) + f3(i) + f4(i) + f5(i);
  }
  return s;
}