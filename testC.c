__attribute__((noinline))
int cold(int x) {
  for (int i = 0; i < 1000; i++)
    x = x * 17 + i;
  return x;
}

int hot(int x) {
  return x + 1;
}

int f(int x) {
  if (x == 123456)
    return cold(x);
  return hot(x);
}

int main() {
  int s = 0;
  for (int i = 0; i < 1000000; i++)
    s += f(i);
  return s;
}
