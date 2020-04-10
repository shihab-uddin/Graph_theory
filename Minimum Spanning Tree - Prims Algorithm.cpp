#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int adj_matrix[100][100];

class Node{
public:
    int v,cost;
    Node(){
    }
    Node(int vtx,int wgt){
        v = vtx;
        cost = wgt;
    }
};

bool operator<(Node a, Node b){
    return a.cost > b.cost;
}


class prims_algo{
    int vertex, edge, u, v, weight, i, j, ans = 0;
    bool visited[100] = {false};
public:
    void input(){
        cin>>vertex>>edge;
        for(i = 1; i <= edge; i++){
            cin>>u>>v>>weight;
            adj_matrix[u][v] = weight;
            adj_matrix[v][u] = weight;
        }
    }

    void calculate(){
        priority_queue<Node> pq;
        pq.push(Node(0,0));
        while(!pq.empty()){
            Node tmp = pq.top();
            pq.pop();
            if(visited[tmp.v] == 1)
                continue;
            //cout<<tmp.v<< ' '<<tmp.cost<<endl;
            ans += tmp.cost;
            visited[tmp.v] = 1;

            for(i = 0; i < vertex; i++){
                if(visited[i] == 1)
                    continue;
                if(adj_matrix[tmp.v][i] != 0){
                    pq.push(Node(i,adj_matrix[tmp.v][i]));
                }
            }
        }
        cout<<"Minimum cost is : "<<ans<<endl;
    }
};

int main(){

    freopen("input_prims.txt", "r", stdin);
    prims_algo object;
    object.input();
    object.calculate();

    return 0;
}
