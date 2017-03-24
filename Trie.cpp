struct Hash{
  int operator()(const pair<int,char>&p)const{
    return p.first*128+p.second;
  }
};

unordered_map<pair<int,char>,int,Hash> trie;
vector<bool> isEnd;

int addNode(){
  isEnd.push_back(false);
  return sz(isEnd)-1;
}

void init(){
  trie.clear();
  isEnd.clear();
  addNode();
}

bool insert(const char* s){
  int cur=0;
  for(;*s;s++){
    int nxt=trie.insert({{cur,*s},-1}).first->second;
    if(nxt==-1)nxt=trie[{cur,*s}]=addNode();
    cur=nxt;
    if(isEnd[cur])return true;
  }
  isEnd[cur]=true;
  return false;
}

---------------------------------------------------------------------------------------


int trie[100100][128];
bool isEnd[100100];
int nodeCnt;

int addNode(){
  memset(trie[nodeCnt],-1,sizeof trie[nodeCnt]);
  isEnd[nodeCnt]=false;
  return nodeCnt++;
}

void init(){
  nodeCnt=0;
  addNode();
}

void insert(const char* s){
  int cur=0;
  for(;*s;s++){
    int &nxt=trie[cur][(int)*s];
    if(nxt==-1)nxt=addNode();
    cur=nxt;
  }
  isEnd[cur]=true;
}

---------------------------------------------------------------------------------------------------


int addNode(){
  trie.push_back(vector<int>(128,-1));
  isEnd.push_back(false);
  return sz(isEnd)-1;
}

void init(){
  trie.clear();
  isEnd.clear();
  addNode();
}

void insert(const char* s){
  int cur=0;
  for(;*s;s++){
    int nxt=trie[cur][(int)*s];
    if(nxt==-1)nxt=trie[cur][(int)*s]=addNode();
    cur=nxt;
  }
  isEnd[cur]=true;
}

