#include<bits/stdc++.h>
#define PAIR pair<int , int>
#define INF 100000000
using namespace std;

int totalNode, node1, node2, weight, src;
vector<vector<PAIR > > adjList(10000); /*Declaring Adjacency List*/

vector<int> parent;
vector<int> dist;

void pathFind(int dst){
    if(dst == src){ /* Base case : destination == source */
        cout<<src;
        return;
    }
    pathFind(parent[dst]);
    cout<<" "<<dst;
}

void bellmanFord(int source){

    dist[source] = 0; /*Distance of source = 0*/

    for(int i = 0; i < totalNode-1; i++){/* Since We have to continue iteration till (n-1) nodes.*/
        for(int u = 0; u < totalNode; u++){ /* Traversing all the elements of Adjacency List*/
            for(int j = 0; j < adjList[u].size(); j++){
                PAIR v = adjList[u][j]; /*Here second element = distance of u to i && First element = node2*/
                if(dist[u] == INF){ /*In Relaxing Condition (INF - 5 < INF). But Logically it is false. So To avoid this using the Condition*/
                    continue;
                }
                if(dist[u] + v.second < dist[v.first]){ /*Relaxation condition : distance of u + distance of u to v < distance of v then update */
                    dist[v.first] = dist[u] + v.second;
                    parent[v.first] = u; /*Update the parent*/

                }
            }
        }
    }
    /*So we need to do another Iteration(Relaxing all the edges) for detecting whether the Graph is containing Negative Cycle or not*/
    bool hasCycle = false;

    for(int u = 0; u < totalNode; u++){
        for(int j = 0; j < adjList[u].size(); j++){
            PAIR v = adjList[u][j]; /*Here second element = distance of u to i && First element = node2*/
            if(dist[u] == INF){
                continue;
            }
            if(dist[u] + v.second < dist[v.first]){
                hasCycle = true;
                break;
            }
        }
        if(hasCycle)
            break;
    }

    if(hasCycle){
        cout<<"The Graph has Negative Cycle"<<endl;
    }else{
        int destination;
        cout<<"Enter destination : ";
        cin>>destination;
        if(dist[destination] == INF){  /*"Distance of Destination" is still infinity means not possible to reach there*/
            cout<<"Path not Found";
        }
        else{
            cout<<"Cost : "<<dist[destination]<<endl;
            cout<<"Shortest Path : ";
            pathFind(destination);
        }
    }
}

int main(){

    ifstream input("input_bellmanFort.txt");
    if(!input.is_open()){
        cout<<"Input File not found"<<endl;
        return 0;
    }
    else{
        input>>totalNode;
        while(input>>node1>>node2>>weight){
            adjList[node1].push_back(make_pair(node2, weight));
        }
    }
    input.close();

    parent.assign(totalNode, -1); /*Since at the beginning no node has any parent. So assign (-1) for all nodes*/
    dist.assign(totalNode, INF); /*Since at the beginning all nodes have infinite distance*/

    cout<<"Enter Source node : ";
    cin>>src;

    bellmanFord(src);

    return 0;
}

/**
----> Algorithm : Bellman Ford Algorithm.
----> TIME COMPLEXITY : O(V * E)
----> NB : Bellman Ford Algorithm can work with Negative Weighted Edge and it can just detect Negative Cycle of a Graph.
*/

/*Input :

5 ------->Total Vertex.
0 1 -1 -->n1, n2, weight.
0 2 2
0 3 4
1 0 2
1 2 3
2 3 5
2 4 3
3 2 -1
4 3 4
4 1 -3

Output :

Enter Source node : 3
Enter destination : 0
Cost : 1
Shortest Path : 3 2 4 1 0

*/
