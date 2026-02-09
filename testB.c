int g(int);

int f(int x) {
  if (x <= 0) return 1;
  return g(x - 1) + 1;
}

int g(int x) {
  if (x <= 0) return 1;
  return f(x - 1) + 1;
}

int main() {
  int s = 0;
  for (int i = 0; i < 100000; i++)
    s += f(10);
  return s;
}
