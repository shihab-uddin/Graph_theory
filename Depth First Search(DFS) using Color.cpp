#include<bits/stdc++.h>
#define WHITE 1
#define GRAY 2
#define BLACK 3
using namespace std;

int totalNodes, totalEdges, node1, node2, source;

int adjMatrix[100][100];
int color[1000];

int Time = 1;
int startTime[100];
int endTime[100];

void dfs(int x){
    color[x] = GRAY;
    startTime[x] = Time;
    ++Time;
    //some work start
    for(int i = 1; i <= totalNodes; i++){
        if(adjMatrix[x][i] == 1){
            if(color[i] == WHITE){
                dfs(i);
            }
        }
    }
    //some work done.
    color[x] = BLACK;
    endTime[x] = Time;
    ++Time;
    //cout<<x<<" ";
}

void dfsVisit(){
    for(int i = 1; i <= totalNodes; i++){
        color[i] = WHITE;
    }
    for(int i = 1; i <= totalNodes; i++){
        if(color[i] == WHITE){
            dfs(i);
        }
    }
}

int main(){

    ifstream input("dfs_input_color.txt");
    input>>totalNodes>>totalEdges;
    while(input>>node1>>node2){
        adjMatrix[node1][node2] = 1;
        adjMatrix[node2][node1] = 1;
    }
    input.close();

    dfsVisit();

    for(int i = 1; i <= totalNodes; i++){
        cout<<"Node "<<(char)('A' + (i-1))<<" : "<<"Discovery Time : "<<startTime[i]<<" Finishing Time : "<<endTime[i]<<endl;
    }

    return 0;
}

/*

Input :

8 7 ---> Total Nodes, Total Edges.
0 1 ---> Node1, Node2
0 2
1 3
2 4
2 5
3 6
3 7

Output :

Node A : Discovery Time : 1 Finishing Time : 8
Node B : Discovery Time : 9 Finishing Time : 14
Node C : Discovery Time : 2 Finishing Time : 7
Node D : Discovery Time : 10 Finishing Time : 11
Node E : Discovery Time : 12 Finishing Time : 13
Node F : Discovery Time : 3 Finishing Time : 4
Node G : Discovery Time : 5 Finishing Time : 6
Node H : Discovery Time : 15 Finishing Time : 16

*/
