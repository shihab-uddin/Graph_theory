#include<bits/stdc++.h>
using namespace std;

int totalVertex;
int arr[100][100];
int arr_weighted[100][100];

class Node{
public:
    int data;
    Node *next;
};

class VertexList{
public:
    Node *vertexHead;
};

class Graph{
public:
    VertexList *VL;
};

Graph *createGraph(int n){
    Graph *myGraph = new Graph();
    myGraph->VL = new VertexList[n+1];
    for(int i = 0; i < n+1; i++){
        myGraph->VL[i].vertexHead = NULL;
    }
    return myGraph;
}

Node *createNode(int value){
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEdge(Graph *G, int u, int v){
    Node *newNode1 = createNode(u);
    Node *newNode2 = createNode(v);

    if(G->VL[u].vertexHead == NULL){
        G->VL[u].vertexHead = newNode2;
    }else{
        newNode2->next = G->VL[u].vertexHead;
        G->VL[u].vertexHead = newNode2;
    }
}

void print(Graph *G){
    for(int i = 0; i < totalVertex; i++){
        cout<<i+1<<"->";
        while(G->VL[i+1].vertexHead != NULL){
            cout<<G->VL[i+1].vertexHead->data<<" ";
            G->VL[i+1].vertexHead = G->VL[i+1].vertexHead->next;
        }
        cout<<endl;
    }

}

//---------------Undirected Weighted Graph Adjacent List Start------------------

class WeightedNode{
public:
    int data;
    int weight;
    WeightedNode *next;
};

class WeightedVertexList{
public:
    WeightedNode *vertexHead;
};

class WeightGraph{
public:
    WeightedVertexList *VLweighted;
};

WeightGraph *create_weight_Graph(int n){
    WeightGraph *myGraph = new WeightGraph();
    myGraph->VLweighted = new WeightedVertexList[n+1];
    for(int i = 0; i < n+1; i++){
        myGraph->VLweighted[i].vertexHead = NULL;
    }
    return myGraph;
}

WeightedNode *createNode_weighted(int value, int w){
    WeightedNode *newNode = new WeightedNode();
    newNode->data = value;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void insert_weighted_Edge(WeightGraph *WG, int u, int v, int wgt){
    WeightedNode *newNode1 = createNode_weighted(u, wgt);
    WeightedNode *newNode2 = createNode_weighted(v, wgt);

    if(WG->VLweighted[v].vertexHead == NULL){
        WG->VLweighted[v].vertexHead = newNode1;
    }else{
        newNode1->next = WG->VLweighted[v].vertexHead;
        WG->VLweighted[v].vertexHead = newNode1;
    }

    if(WG->VLweighted[u].vertexHead == NULL){
        WG->VLweighted[u].vertexHead = newNode2;
    }else{
        newNode2->next = WG->VLweighted[u].vertexHead;
        WG->VLweighted[u].vertexHead = newNode2;
    }
}

void print_weighted_graph(WeightGraph *WG){
    for(int i = 0; i < totalVertex; i++){
        cout<<i+1<<"->";
        while(WG->VLweighted[i+1].vertexHead != NULL){
            cout<<"("<<WG->VLweighted[i+1].vertexHead->data<<",";
            cout<<WG->VLweighted[i+1].vertexHead->weight<<")";
            WG->VLweighted[i+1].vertexHead = WG->VLweighted[i+1].vertexHead->next;
        }
        cout<<endl;
    }
}

/*-----------------Undirected Weighted Graph Adjacent List End--------------------*/

/*-----------------------Weighted Directed Graph Adjacency List Start---------------------*/

void insert_weighted_Edge_Directed(WeightGraph *WG, int u, int v, int wgt){
    WeightedNode *newNode1 = createNode_weighted(u, wgt);
    WeightedNode *newNode2 = createNode_weighted(v, wgt);
    if(WG->VLweighted[u].vertexHead == NULL){
        WG->VLweighted[u].vertexHead = newNode2;
    }else{
        newNode2->next = WG->VLweighted[u].vertexHead;
        WG->VLweighted[u].vertexHead = newNode2;
    }
}

/*-----------------------Weighted Directed Graph Adjacency List Start---------------------*/

/*-----------------------Weighted Directed Matrix Start---------------------*/

void adjMatrix_directed_weighted(int u, int v, int w){
    for(int i = 1; i <= totalVertex; i++){
        for(int j = 1; j <= totalVertex; j++){
            arr_weighted[u][v] = w;
        }
    }
}

/*-----------------------Weighted Directed Matrix End---------------------*/

/*-----------------------Undirected Unweighted Adjacency Matrix Start------------------*/

void adjMatrix(int u, int v){
    for(int i = 1; i <= totalVertex; i++){
        for(int j = 1; j <= totalVertex; j++){
            arr[u][v] = 1;
        }
    }
}

void printAdjMatrix(){
    for(int i = 1; i <= totalVertex; i++){
        for(int j = 1; j <= totalVertex; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

/*-----------------------Undirected Unweighted Adjacency Matrix End---------------------*/

/*---------------Weighted Undirected Adjacency Matrix Start-------------------*/

void adjMatrix_weighted(int u, int v, int w){
    for(int i = 1; i <= totalVertex; i++){
        for(int j = 1; j <= totalVertex; j++){
            arr_weighted[u][v] = w;
            arr_weighted[v][u] = w;
        }
    }
}

/*---------------Weighted Undirected Adjacency Matrix End-------------------*/

void printAdjMatrix_weighted(){
    for(int i = 1; i <= totalVertex; i++){
        for(int j = 1; j <= totalVertex; j++){
            cout<<arr_weighted[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    ifstream input("Input Graph 1.txt");

    string str1, str2;
    input>>str1>>str2;
    fclose(stdin);

    int node1, node2, w;

    if(str1 == "Directed" && str2 == "UnWeighted"){

        input>>totalVertex;

        Graph *newGraph = createGraph(totalVertex);

        while(input>>node1>>node2){
            cin>>node1>>node2;
            insertEdge(newGraph, node1, node2);
            adjMatrix(node1, node2);
        }
        input.close();

        cout<<"Adjacency List for Directed Unweighted Graph : "<<endl<<endl;
        print(newGraph);
        cout<<endl;
        cout<<"Adjacency Matrix for Directed Unweighted Graph : "<<endl<<endl;
        printAdjMatrix();

    }else if(str1 == "Undirected" && str2 == "Weighted"){

        input>>totalVertex;
        WeightGraph *newGraph_weighted = create_weight_Graph(totalVertex);

        while(input>>node1>>node2>>w){
            cin>>node1>>node2>>w;
            insert_weighted_Edge(newGraph_weighted, node1, node2, w);
            adjMatrix_weighted(node1, node2, w);
        }
        input.close();

        cout<<"Adjacency List for Undirected Weighted Graph : "<<endl<<endl;
        print_weighted_graph(newGraph_weighted);
        cout<<endl;
        cout<<"Adjacency Matrix for Undirected weighted Graph : "<<endl<<endl;
        printAdjMatrix_weighted();

    }else if(str1 == "Directed" && str2 == "Weighted"){

        input>>totalVertex;
        WeightGraph *newGraph_directed_weighted = create_weight_Graph(totalVertex);

        while(input>>node1>>node2>>w){
            cin>>node1>>node2>>w;
            insert_weighted_Edge_Directed(newGraph_directed_weighted, node1, node2, w);
            adjMatrix_directed_weighted(node1, node2, w);
        }
        input.close();

        cout<<"Adjacency List for Directed Weighted Graph : "<<endl<<endl;
        print_weighted_graph(newGraph_directed_weighted);
        cout<<endl;
        cout<<"Adjacency Matrix for Directed Weighted Graph : "<<endl<<endl;
        printAdjMatrix_weighted();
    }

    return 0;
}
