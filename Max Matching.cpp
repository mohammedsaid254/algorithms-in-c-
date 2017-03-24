const int MX = 405;
vector<int> adj[MX];

int r[MX] , l[MX] , vis[MX];
int vis_id , numR;

bool match(int i){
    for(int j = 0 ; j < adj[i].size() ; j++){
        if(vis[adj[i][j]] == vis_id)continue;
        vis[adj[i][j]] = vis_id;
        if(l[adj[i][j]] == -1 || match(l[adj[i][j]])){
            l[adj[i][j]] = i;
            r[i] = adj[i][j];
            return true;
        }
    }
    return false;
}

int runMatching(){
    int cc = 0;
    memset(r,-1,sizeof r);
    memset(l,-1,sizeof l);
    for(int i = 0 ; i < numR ; i++){
        vis_id++;
        if(match(i))
            cc++;
    }
    return cc;
}
