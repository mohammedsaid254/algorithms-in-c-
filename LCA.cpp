#include<bits/stdc++.h>
using namespace std;


const int N = 100010;
const int LG = 30;
vector <int> adj[N];
int depth[N], dp[N], anc[N][LG];
int tin[N], tout[N], timer;
int n;

void dfs(int u, int par = 0, int dep = 0) {
    depth[u] = dep;
    dp[u] = 1;
    tin[u] = timer++;
    anc[u][0] = par;

    for (int i = 1; i < LG; i++){
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    }

    for (int i = 0; i < adj[u].size(); i++){
        int to = adj[u][i];
        if (to != par) {
            dfs(to, u, dep + 1);
            dp[u] += dp[to];
        }
    }

    tout[u] = timer++;
}

bool ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int go_up(int a, int b) {
    for (int i = LG - 1; i >= 0; i--) {
        if (!ancestor(anc[a][i], b)){
            a = anc[a][i];
        }
    }
    return a;
}

int lca(int a, int b) {
    int result = -1;
    if (ancestor(a, b)){
        result = a;
    } else if (ancestor(b, a)){
        result = b;
    } else {
        result = anc[go_up(a, b)][0];
    }

    return result;
}

int main(){

    return 0;
}


//--------------------------------------------------------------------------------------------
const int N = 10001;
vector<int> adj[N];
int lvl[N], anc[N][25];
int n;

void dfs(int u = 0 , int par = 0 , int l = 0){
    lvl[u] = l;
    anc[u][0] = par;
    for(auto nxt : adj[u])
        dfs(nxt , u , l+1);
}

void buildLCA() {
    int lg = ceil(log2(n));
    for(int j = 1 ; j < lg ; j++)
        for(int i = 0 ; i < n ; i++)
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
}

int LCA(int i, int j){
    int lg = ceil(log2(n));
    int st = lg;
    if (lvl[i] > lvl[j])swap(i, j);
    int cur = lvl[j];
    for (; st >= 0; st--)
        if (cur - (1 << st) >= lvl[i])
            cur -= (1 << st), j = anc[j][st];
    if (i == j)return 2 * i - j;
    cur = lvl[i];
    for (st = lg; st >= 0; st--)
        if (anc[i][st] != anc[j][st])
            cur -= (1 << st), i = anc[i][st], j = anc[j][st];
    return anc[i][0];
}
