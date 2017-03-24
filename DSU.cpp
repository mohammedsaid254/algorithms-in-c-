const int N = 1e5 + 5;
int p[N] , w[N];
int n;

int f(int u){
    if(u == p[u])return u;
    return p[u] = f(p[u]);
}

bool is_connected(int a , int b){
    return f(a) == f(b);
}

void connect(int a , int b){
    a = f(a);
    b = f(b);
    if(a == b)return;
    if(w[a] < w[b])swap(a,b);
    w[a] += w[b];
    p[b] = a;
}

void init(){
    for(int i = 0 ; i < N ; i++)
        p[i] = i , w[i] = 1;
}
