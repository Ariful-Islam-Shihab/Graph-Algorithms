#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
        int u,v,c;
        Edge(int u,int v,int c){
            this->u=u;
            this->v=v;
            this->c=c;
        }
};
int main(){
    int V,E;
    cin>>V>>E;
    vector<Edge>EdgeList;
    while (E--){
        int u,v,c;
        cin>>u>>v>>c;
        EdgeList.push_back(Edge(u,v,c));
    }
    int dis[V+1];
    for(int i=0;i<V+1;i++)
        dis[i]=INT_MAX;
    dis[1]=0;
    for(int i=0;i<V-1;i++){
        for(Edge x:EdgeList){
            int u=x.u;
            int v=x.v;
            int c=x.c;
            if(dis[u]<INT_MAX&&dis[u]+c<dis[v]){
                dis[v]=dis[u]+c;
            }
        }
    }
    cout<<"Distance of each vertices from source:"<<endl;
    for(int i=1;i<=V;i++){
        if(dis[i]==INT_MAX)
            cout<<"Can't reach "<<endl;
        else
        cout<<i<<"->"<<dis[i]<<endl;
    }
    return 0;
}