//
// Created by zxc02 on 2022/11/14.
// Time is 18:54
#include "iostream"
#include "string"
#include <algorithm>

using namespace std;
struct node {
  string s1, s2;
} dic[100001];
int i = 0;
bool cmp(node a, node b) { return a.s2 < b.s2; }
void Func(const string &s) {
  int l = 0, r = i - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (dic[mid].s2 == s) {
      cout << dic[mid].s1 << endl;
      return;
    } else if (dic[mid].s2 > s)
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << "eh" << endl;
}

int main() {
  //	freopen("input.txt", "r", stdin);
  string s1, s2, word;
  char c;
  while (true) {
    cin >> s1;
    c = getchar();
    if (c == '\n')
      break;
    cin >> s2;
    dic[i].s1 = s1;
    dic[i++].s2 = s2;
  }
  sort(dic, dic + i, cmp);
  word = s1;
  do {
    Func(word);
  } while (cin >> word);
  return 0;
}
