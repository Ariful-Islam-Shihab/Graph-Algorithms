#include<bits/stdc++.h>
using namespace std;
void BFS(vector<int>list[],int source,int V){
    bool vis[V+1];
    memset(vis,false,sizeof(vis));
    queue<int>myQ;
    myQ.push(source);
    vis[source]=true;
    while(!myQ.empty()){
        cout<<myQ.front()<<" ";
        int parent=myQ.front();
        myQ.pop();
        for(int x:list[parent]){
            if(!vis[x]){
                myQ.push(x);
                vis[x]=true;
            }
        }
    }
    return;
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<int>list[V+1];
    while(E--){
        int a,b;
        cin>>a>>b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    int source;
    cin>>source;
    BFS(list,source,V);
    return 0;
}