int LG[100100];
int arr[100100];
int sTable[100100][17];

void build() {
  LG[0] = -1;
  for (int i = 0; i < n; i++) {
    LG[i + 1] = LG[i] + !(i & (i + 1));
    sTable[i][0] = i;
  }
  for (int j = 1; (1 << j) <= n; j++)
    for (int i = 0; i + (1 << j) <= n; i++) {
      int a = sTable[i][j - 1];
      int b = sTable[i + (1 << (j - 1))][j - 1];
      sTable[i][j] = (arr[a] < arr[b] ? a : b);
    }
}

int findMinIdx(int s, int e) {
  int len = e - s + 1;
  int lg = LG[len];
  int a = sTable[s][lg];
  int b = sTable[e - (1 << lg) + 1][lg];
  return (arr[a] < arr[b] ? a : b);
}
