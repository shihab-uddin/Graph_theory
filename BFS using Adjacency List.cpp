#include<bits/stdc++.h>
using namespace std;

vector <int> adjList[1000]; // A 2d Vector for storing all the Vertices as Adjacency List
queue <int> q;
bool visited[100];

void BFS(int src){
    q.push(src); // Firstly we have to push Source in a Queue
    visited[src] = true; // We have already visited the Source. So it's true.
    while(!q.empty()){ // While Queue is not Empty taking Front item of Queue and Traversing it's Adjacent it they are not visited.
        int u = q.front();
        cout<<u<<" ";
        q.pop(); // Remove the front item of Queue Since it is already visited.
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

    for(int i = 0;  i < totalEdges; i++){ // Taking all the edges one by one and storing those in an Adjacency List.
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout<<"Enter Source : "<<endl;
    cin>>src;
    BFS(src); // Calling BFS From Source.


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
