// parser.c
static int is_digit(char c) {
  return c >= '0' && c <= '9';
}

static int parse_number(const char *s) {
  int v = 0;
  for (; is_digit(*s); ++s)
    v = v * 10 + (*s - '0');
  return v;
}

int main() {
  const char *str = "12345";
  int sum = 0;
  for (int i = 0; i < 1000000; ++i)
    sum += parse_number(str);
  return sum;
}
