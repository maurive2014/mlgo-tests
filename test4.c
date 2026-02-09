// fsm.c
typedef enum { S0, S1, S2 } State;

static State step0(int x) { return x & 1 ? S1 : S2; }
static State step1(int x) { return x & 2 ? S0 : S2; }
static State step2(int x) { return x & 4 ? S0 : S1; }

int main() {
  State s = S0;
  for (int i = 0; i < 10000000; ++i) {
    switch (s) {
      case S0: s = step0(i); break;
      case S1: s = step1(i); break;
      case S2: s = step2(i); break;
    }
  }
  return s;
}
