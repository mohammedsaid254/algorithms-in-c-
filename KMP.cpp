const int N = 1e7;
char pat[N], str[N];
int f[N];

int PF(int len, char c) {
  while (len && pat[len] != c)
    len = f[len - 1];
  if (pat[len] == c)
    len++;
  return len;
}

void computeF() {
  f[0] = 0;
  int len = 0;
  if (*pat) {
    for (int i = 1; pat[i]; i++) {
      len = PF(len, pat[i]);
      f[i] = len;
    }
  }
}

vector<int> match() {
  vector<int> ind;
  int len = 0;
  for (int i = 0; str[i]; i++) {
    len = PF(len, str[i]);
    if (!pat[len])
      ind.push_back(i - len + 1), len = f[len - 1];
  }
  return ind;
}
