#include<bits/stdc++.h>
using namespace std;

int totalNodes, totalEdges, node1, node2, weight;
vector<pair<int, pair<int, int> > > edges;
int parent[100];

int find_set(int x){
    if(parent[x] == x){
        return x;
    }
    find_set(parent[x]);
}

void unity(int n1, int n2){
    int fx = find_set(n1);
    int fy = find_set(n2);
    parent[fy] = fx;
}

void kruskal(){
    sort(edges.begin(), edges.end()); // Sort all the edges in ascending order
    int mstEdges = 0, edgeCount = 0, mstWeight = 0;

    while(mstEdges < totalNodes-1 || edgeCount < totalEdges){ //since mstEdges are less than total node or counting edges until finish
        node1 = edges[edgeCount].second.first;
        node2 = edges[edgeCount].second.second;
        weight = edges[edgeCount].first;
        if(find_set(node1) != find_set(node2)){ // if both nodes have different representative then take that edge
            mstWeight += weight;
            cout<<node1<<" "<<node2<<" "<<weight<<endl;
            unity(node1, node2);
            mstEdges++;
        }
        edgeCount++;
    }
    cout<<"Total Cost for MST : "<<mstWeight<<endl;
}

int main(){

    freopen("kruskal.txt", "r", stdin);
    cout<<"Enter the Total Number of Nodes : "<<endl;
    cin>>totalNodes;
    cout<<"Enter the Total Number of Edges : "<<endl;
    cin>>totalEdges;

    for(int i = 0; i < totalEdges; i++){
        cin>>node1>>node2>>weight;
        edges.push_back(make_pair(weight, make_pair(node1, node2)));
        edges.push_back(make_pair(weight, make_pair(node2, node1)));
    }

    for(int i = 1; i <= totalNodes; i++){
        parent[i] = i;
    }

    kruskal();

    return 0;
}


/* Sample input :

5 7    //Total Nodes and Total Edges
0 3 5  //Node1 Node2 Weight
0 1 2
1 3 5
1 2 14
1 4 4
2 4 34
3 4 58

*/
