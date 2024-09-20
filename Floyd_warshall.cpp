#include<bits/stdc++.h>
using namespace std;
int main(){
    int V;
    cin>>V;
    long long int adjMat[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>adjMat[i][j];
            if(adjMat[i][j]==0)
                adjMat[i][j]=INT_MAX;
        }
    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adjMat[i][k]+adjMat[k][j]<adjMat[i][j])
                    adjMat[i][j]=adjMat[i][k]+adjMat[k][j];
            }
        }
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
