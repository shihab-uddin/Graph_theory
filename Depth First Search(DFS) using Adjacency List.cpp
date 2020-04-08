#include<bits/stdc++.h>
using namespace std;

vector<int> adjList[100];
vector<int> result;
bool visited[100];

void dfs(int src){
    if(visited[src] == true){
        return;
    }

    visited[src] = true;
    result.push_back(src);

    for(int i=0;i<adjList[src].size();i++){
        int v = adjList[src][i];
        if(visited[v] == false){
            dfs(v);
        }
    }
}

void printVisitResult(){
    cout<<"DFS Traversing : ";
    for(int i = result.size()-1; i >= 0; i--){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int totalEdge, n1, n2;
    freopen("input_dfsAdjList.txt","r",stdin);
    cin>>totalEdge;
    for(int i=0; i<totalEdge; i++){
        cin>>n1>>n2;
        adjList[n1].push_back(n2);
        adjList[n2].push_back(n1);

    }

    dfs(0);

    printVisitResult();

    return 0;
}

/*

Input :

7
0 1
0 2
1 3
2 4
2 5
3 6
3 7

Output :

DFS Traversing : 5 4 2 7 6 3 1 0

*/

