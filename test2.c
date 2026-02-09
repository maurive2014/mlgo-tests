// pipeline.c
static int clamp(int x) {
  return x < 0 ? 0 : (x > 255 ? 255 : x);
}

static int brighten(int x) { return clamp(x + 10); }
static int contrast(int x) { return clamp((x - 128) * 2 + 128); }
static int invert(int x)   { return 255 - x; }

static int process(int x) {
  x = brighten(x);
  x = contrast(x);
  x = invert(x);
  return x;
}

int main() {
  int acc = 0;
  for (int i = 0; i < 10000000; ++i)
    acc += process(i & 255);
  return acc;
}
