

const int N = 10005;
vector<int> adj[N][2];//1 for reversed graph
int comp[N] , vis[N];
int vis_id;
vector<int> stk;

void dfs(int u , int flag , int c = 0){
    vis[u] = vis_id;
    if(flag)
        comp[u] = c;
    else
        stk.push_back(u);

    for(int nxt : adj[u][flag])
        if(vis[nxt] != vis_id)
            dfs(nxt , flag , c);
}
