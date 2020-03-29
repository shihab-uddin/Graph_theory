#include<bits/stdc++.h>
using namespace std;

int edge, u, v, w;
int n;
int c[100][100];
int cost[100];
int d[100];
int path[100];
int stage = 5;

void multistageGraph(){
    int mini;
    cost[n] = 0;
    for(int i = n-1; i >= 1; i--){
        mini = 99999;
        for(int k = i+1; k <= n; k++){
            if(c[i][k] != 0 && c[i][k] + cost[k] < mini){
                mini = c[i][k] + cost[k];
                d[i] = k;
            }
        }
        cost[i] = mini;
    }
    path[1] = 1;
    path[stage] = n;
    for(int i = 2; i < stage; i++){
        path[i] = d[path[i-1]];
        cout<<path[i]<<" ";
    }
}

int main(){

    freopen("in.txt", "r", stdin);
    cin>>n>>edge;
    for(int i = 1; i<=edge; i++){
        cin>>u>>v>>w;
        c[u][v] = w;
    }

    multistageGraph();

    return 0;
}
