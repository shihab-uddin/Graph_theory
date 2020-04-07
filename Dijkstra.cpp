/**
----> Algorithm : Dijkstra
----> TIME COMPLEXITY : O(V + ElogV)
*/
#include<bits/stdc++.h>
#define PAIR pair<int, int>
#define INF 1000000
using namespace std;

int totalNode, node1, node2, weight, src;
vector<vector<PAIR > > adjList(10000); /*Declaring Adjacency List*/
priority_queue<PAIR > pq; /*Declaring Priority Queue*/

vector<int> parent;
vector<int> dist;

int pathFind(int dst){
    if(dst != src && parent[dst] == -1){ /* if it is not possible to reach from source to destination */
        cout<<"Path Not Found"<<endl;
        return 0;
    }
    if(dst == src){ /* Base case : destination == source */
        cout<<src;
        return 0;
    }
    pathFind(parent[dst]);
    cout<<" "<<dst;
}

void dijkstra(int source){
    dist[source] = 0; /*Distance of source = 0*/
    pq.push(make_pair(-0, -source));/*Greatest value has highest priority in PQ, So Put (-) to manage it*/

    while(!pq.empty()){
        pair<int, int> frnt;
        frnt = pq.top(); /*Taking the first element of PQ*/
        pq.pop();
        int distance, u;
        distance = -frnt.first, u = -frnt.second; /*To make those original multiply by (-)*/

        if(distance > dist[u]){ /*Since current distance is greater then needn't explore, delete or pop it*/
            continue;
        }

        for(int i = 0; i < adjList[u].size(); i++){
            PAIR v = adjList[u][i]; /*Here second element = distance of u to i && First element = node2*/
            if(dist[u] + v.second < dist[v.first]){/*Relaxation condition :
                                                    distance of u + distance of u to v < distance of v then update */
                dist[v.first] = dist[u] + v.second;
                parent[v.first] = u; /*Update the parent*/
                pq.push(make_pair(-dist[v.first], -v.first));/*Push that lowest Distance and Vertex into PQ*/
            }
        }
    }
}

int main(){

    ifstream input("input_dijkstra.txt");
    if(!input.is_open()){
        cout<<"File not found"<<endl;
    }else{
        input>>totalNode;
        while(input>>node1>>node2>>weight){
            adjList[node1].push_back(make_pair(node2, weight));
        }
    }

    parent.assign(totalNode, -1); /*Since at the beginning no node has any parent. So assign (-1) for all nodes*/
    dist.assign(totalNode, INF); /*Since at the beginning all nodes have infinite distance*/

    cout<<"Enter Source node : ";
    cin>>src;
    dijkstra(src);

    int destination;
    cout<<"Enter destination : ";
    cin>>destination;
    cout<<"Cost : "<<dist[destination]<<endl;
    pathFind(destination);

    return 0;
}

/*Input :

5
0 4 1
1 3 3
1 4 6
2 0 6
2 1 2
2 3 7
3 4 5

*/

/*Output :

Enter Source node : 2
Enter destination : 3
Cost : 5
2 1 3

*/
