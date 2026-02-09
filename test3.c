// hash.c
#define N 1024

typedef struct {
  int key;
  int value;
} Entry;

static unsigned hash(int k) {
  return (unsigned)k * 2654435761u % N;
}

static int lookup(Entry *t, int k) {
  unsigned h = hash(k);
  if (t[h].key == k)
    return t[h].value;
  return -1;
}

int main() {
  Entry table[N] = {0};
  table[42].key = 42;
  table[42].value = 7;

  int s = 0;
  for (int i = 0; i < 10000000; ++i)
    s += lookup(table, 42);
  return s;
}
