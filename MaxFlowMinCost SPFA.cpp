#include <bits/stdc++.h>
using namespace std;


#define MAXN 50000
#define MAXM MAXN * 5

const int INF = 1e9; // $infinity$: be careful to make this big enough!!!
int src , snk;
int n , edge_cnt;
// ra[a]: edges connected to a (NO MATTER WHICH WAY!!!); clear this in the beginning
vector<int> ra[MAXN];
int kend[MAXM], cap[MAXM], cost[MAXM]; // size: TWICE the number of edges

// Adds an edge from a to b with capacity c and cost d and returns the number of the new edge
int addedge(int a, int b, int c, int d) {
	int i = 2 * edge_cnt;
	kend[i] = b;
	cap[i] = c;
	cost[i] = d;
	ra[a].push_back(i);
	kend[i + 1] = a;
	cap[i + 1] = 0;
	cost[i + 1] = -d;
	ra[b].push_back(i + 1);
	edge_cnt++;
	return i;
}

int dst[MAXM], pre[MAXM], pret[MAXM];
bool spfa() {
	for (int i = 0; i < MAXN; ++i)
		dst[i] = INF;
	dst[src] = 0;
	queue<int> que;
	que.push(src);
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		for (int t : ra[x]) {
			int y = kend[t], nw = dst[x] + cost[t];
			if (cap[t] > 0 && nw < dst[y]) {
				dst[y] = nw;
				pre[y] = x;
				pret[y] = t;
				que.push(y);
			}
		}
	}
	return dst[snk] != INF;
}

// returns the maximum flow and the minimum cost for this flow
pair<long long, long long> solve() {
	long long totw = 0, totf = 0;
	while (spfa()) {
		int minflow = INF;
		for (int x = snk; x != src; x = pre[x]) {
			minflow = min(minflow, cap[pret[x]]);
		}
		for (int x = snk; x != src; x = pre[x]) {
			cap[pret[x]] -= minflow;
			cap[pret[x] ^ 1] += minflow;
		}
		totf += minflow;
		totw += minflow * dst[snk];
	}
	return make_pair(totf, totw);
}

void init(){
    edge_cnt = 0;
    for (int i = 0; i < MAXN; ++i)
        ra[i].clear();

}

