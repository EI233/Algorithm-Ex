#include <cstdio>
int n;
char str[101];
bool step(char s[101], int k) {
  n++;
  switch (s[n]) {
  case 'p':
    return k & 1;
  case 'q':
    return (k >> 1) & 1;
  case 'r':
    return (k >> 2) & 1;
  case 's':
    return (k >> 3) & 1;
  case 't':
    return (k >> 4) & 1;
  case 'N':
    return !step(s, k);
  case 'K':
    return step(s, k) & step(s, k);
  case 'A':
    return step(s, k) | step(s, k);
  case 'C':
    return !step(s, k) | step(s, k);
  case 'E':
    return step(s, k) == step(s, k);
  }
  return false;
}

bool judge(char *s) {
  for (int i = 0; i < 32; i++) {
    n = -1;
    if (!step(s, i))
      return false;
  }
  return true;
}

int main() {
  while (true) {
    scanf("%s", str);
    if (*str == '0')
      break;
    if (judge(str))
      printf("tautology\n");
    else
      printf("not\n");
  }
  return 0;
}