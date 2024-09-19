#include<bits/stdc++.h>
using namespace std;
int dis[1000];
int parent[1000];
class cmp{
    public:
        bool operator()(int a,int b){
            return dis[a]<dis[b];
        }
};
void desFind(int x){
    if(parent[x]==x){
        cout<<x<<" ";
        return;
    }
    desFind(parent[x]);
    cout<<x<<" ";
    return;
}
int mst(vector<pair<int,int>>list[],int source,int V){
    dis[source]=0;
    parent[source]=source;
    priority_queue<int,vector<int>,cmp>myQ;
    myQ.push(source);
    while(!myQ.empty()){
        int par=myQ.top();
        myQ.pop();
        for(auto x:list[par]){
            int u=par;
            int v=x.first;
            int w=x.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                parent[v]=u;
                myQ.push(v);
            }
        }
    }
    int O=0;
    for(int i=0;i<V;i++){
       O+=dis[i]-dis[parent[i]];
    }
    return O;
}
int main(){
    int V,E;
    cin>>V>>E;
    for(int i=0;i<V;i++)
    {
        dis[i]=INT_MAX;
        parent[i]=i;
    }

    memset(parent,-1,sizeof(parent));
    vector<pair<int,int>>list[V];
    while(E--){
        int a,b,w;
        cin>>a>>b>>w;
        list[a].push_back({b,w});
        list[b].push_back({a,w});
    }
    cout<<mst(list,0,V)<<endl;
    int x;
    cin>>x;
    desFind(x);
    return 0;
}