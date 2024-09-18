#include<bits/stdc++.h>
using namespace std;
class Compare{
    public:
        bool operator()(pair<int,int>a,pair<int,int>b){
            return a.second>b.second;
        }
};
void dijkstra(int V,int sr,vector<pair<int,int>>list[]){
    int cost[V];
    for(int i=0;i<V;i++){
        cost[i]=INT_MAX;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>myQ;
    myQ.push({sr,0});
    cost[sr]=0;
    while(!myQ.empty()){
        auto current=myQ.top();
        myQ.pop();
        int vertex=current.first;
        int weight=current.second;
        for(auto x:list[vertex]){
            int nextVertex=x.first;
            int nextWeight=x.second;
            int total=nextWeight+weight;
            if(total<cost[nextVertex]){
                cost[nextVertex]=total;
                myQ.push({nextVertex,total});
            }
        }
    }
    cout<<"Cost to reach each vertices from source:"<<endl;
    for(int i=0;i<V;i++)
        cout<<i<<" -> "<<cost[i]<<endl;
}
int main(){
    int V,Source,Destination;
    cin>>V>>Source>>Destination;
    int arr[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            cin>>arr[i][j];
    }
    vector<pair<int,int>>list[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i!=j&&arr[i][j]>=0)
                list[i].push_back({j,arr[i][j]});
        }
    }
    dijkstra(V,Source-1,list);
    return 0;
}