// expr.c
#include <stdlib.h>

typedef enum { ADD, MUL, CONST } Kind;

typedef struct Expr {
  Kind kind;
  union {
    struct { struct Expr *a, *b; } bin;
    int value;
  };
} Expr;

static int eval(const Expr *e) {
  switch (e->kind) {
    case ADD:  return eval(e->bin.a) + eval(e->bin.b);
    case MUL:  return eval(e->bin.a) * eval(e->bin.b);
    case CONST:return e->value;
  }
  return 0;
}

int main() {
  Expr c1 = { CONST, .value = 2 };
  Expr c2 = { CONST, .value = 3 };
  Expr add = { ADD, .bin = { &c1, &c2 } };

  int sum = 0;
  for (int i = 0; i < 1000000; ++i)
    sum += eval(&add);
  return sum;
}
