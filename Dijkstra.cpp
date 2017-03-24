const int N = 1e5 + 5;
const long long INF = 1e17;

vector<pair<int,int> > adj[N];
long long dis[N];

void Dijkstra(int s){
    priority_queue < pair<long long,int>, vector<pair<long long,int> > , greater<pair<long long,int> > > pq;
    pq.push(make_pair(0,s));
    fill(dis,dis+N,INF);
    dis[s]=0;

    while(!pq.empty()){
        int u=pq.top().second;
        long long w=pq.top().first;
        pq.pop();

        if(dis[u]< w)continue;

        for(int i=0;i<adj[u].size();i++){
            if(dis[u]+adj[u][i].first < dis[adj[u][i].second]){
                dis[adj[u][i].second]=dis[u]+adj[u][i].first;
                pq.push(make_pair(dis[adj[u][i].second],adj[u][i].second));
            }
        }
    }
}
