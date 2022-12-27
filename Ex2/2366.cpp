//
// Created by zxc02 on 2022/11/14.
// Time is 18:09
#include "cstdio"

int N1[50001];
bool Func(int num, int cnt) {
  int begin = 0, end = cnt - 1;
  int mid;
  while (begin <= end) {
    mid = begin + ((end - begin) >> 1);
    if (N1[mid] == num)
      return true;
    else if (N1[mid] > num)
      end = mid - 1;
    else
      begin = mid + 1;
  }
  return false;
}
int main() {
  int num1, num2, num;
  bool f = false;
  scanf("%d", &num1);
  for (int i = 0; i < num1; ++i)
    scanf("%d", &N1[i]);
  scanf("%d", &num2);
  for (int i = 0; i < num2; ++i) {
    scanf("%d", &num);
    if (Func(10000 - num, num1))
      f = true;
  }
  if (f)
    printf("YES");
  else
    printf("NO");
  return 0;
}