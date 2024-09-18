#include<bits/stdc++.h>
using namespace std;
bool visit[1000];
void DFS(vector<int>list[],int source){
    visit[source]=true;
    cout<<source<<" ";
    for(int x:list[source]){
        if(!visit[x])
            DFS(list,x);
    }
    return;
}
int main(){
    int V,E;
    cin>>V>>E;
    memset(visit,false,sizeof(visit));
    vector<int>list[V+1];
    while(E--){
        int a,b;
        cin>>a>>b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    int source;
    cin>>source;
    DFS(list,source);
    return 0;
}