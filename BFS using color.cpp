#include<bits/stdc++.h>
#define WHITE 1
#define GRAY 2
#define BLACK 3
#define INT_MIN -999999
using namespace std;

int totalNodes, totalEdges, node1, node2, source;

int adj[100][100];
int color[1000];
int dist[100];
int parent[1000];

queue<int> q;

void BFS(int src){
    for(int i = 1; i <= totalNodes; i++){ /* At the beginning Color of all nodes = White & Distance = infinity and they have no parents*/
        color[i] = WHITE;
        dist[i] = INT_MIN;
        parent[i] = -1;
    }

    color[src] = GRAY;
    dist[src] = 0;  // Distance of Source = 0
    parent[src] = -1;
    q.push(src);

    while(!q.empty()){
        int x;
        x = q.front();
        q.pop();
        color[x] = GRAY;
        cout<<x<<" ";
        for(int i = 1; i <= totalNodes; i++){ // Traversing all the adjacent of a vertex
            if(adj[x][i] == 1){
                if(color[i] == WHITE){
                    q.push(i);
                    dist[i] = dist[x] + 1; // Child's distance = (Parent's distance + 1)
                    color[i] = GRAY;
                    parent[i] = x;
                }
            }
        }
        color[x] = BLACK;
    }
}

int main(){

    ifstream input("input_bfs_color.txt");
    input>>totalNodes>>totalEdges;

    while(input>>node1>>node2){
        adj[node1][node2] = 1;
        adj[node2][node1] = 1;
    }
    input.close();
//  cout<<"Enter source : ";
//  cin>>source;
    BFS(0);
    cout<<endl;
    cout<<"Parent of 5 : "<<parent[5]<<endl;
    cout<<"Distance of 5 : "<<dist[5]<<endl;

    return 0;
}


/*
Input :
8 7
0 1
0 2
1 3
2 4
2 5
3 6
3 7
*/

