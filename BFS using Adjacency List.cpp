#include<bits/stdc++.h>
using namespace std;

vector <int> adjList[1000];
queue <int> q;
bool visited[100];

void BFS(int src){
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(int i = 0; i < adjList[u].size(); i++){ // Traverse all the adjacent of the vertex
            int x = adjList[u][i];
            if(visited[x] == false){ // if adjacent of a vertex isn't visited then push into queue and visit that.
                q.push(x);
                visited[x] = true;
            }
        }
    }
}


int main(){

    int u, v, src, totalEdges;

    freopen("bfs_using_adjList.txt", "r", stdin);

    cin>>totalEdges;

    for(int i = 0;  i < totalEdges; i++){
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout<<"Enter Source : "<<endl;
    cin>>src;
    BFS(src);


    return 0;
}


/*Sample input :
5
1 2
2 4
1 3
3 4
4 5
1
*/

//Output : 1 2 3 4 5
