#include<bits/stdc++.h>
using namespace std;

char grid[100][100];
bool visited[100][100];
int row, column;

int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

void floodfill(int i, int j){

    if(i < 0 || j < 0 || i >= row || j >= column){ //base case
        return;
    }
    if(grid[i][j] == '.' && visited[i][j] == false){

        visited[i][j] = true;
        grid[i][j] = '+';

        for(int m = 0; m < 8; m++){ //"Using direction array to make it small & simple"
            int x = i + fx[m];
            int y = j + fy[m];
            floodfill(x, y);
        }

    }
}


int main(){

    int i,j,cnt;
    cnt = 0;
    memset(visited, 0, sizeof(visited));

    cin>>row>>column;
    getchar();

    for(i=0; i<row; i++){
        for(j=0; j<column; j++){
            scanf("%c",&grid[i][j]);
        }
        getchar();
    }

    //Traverse 2D array
    for(i=0; i<row; i++){
        for(j=0; j<column; j++){
            if(grid[i][j]=='.' && visited[i][j]==false){
                cnt++;
                floodfill(i,j);
            }
        }
    }

    cout<<"Number of colored region is : "<<cnt<<endl;
    cout<<"New 2D array is : "<<endl;

    for(i=0; i<row; i++){
        for(j=0; j<column; j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }

    return 0;
}

/*

Input:

12 25
@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@*************@@@@@@
@@@@@@*....*     ..@@@@@@
@@@@@@*....*   ....@@@@@@
@.@@@@*....*      .@@@@@@
@@@@@@*....********@@..@@
@@@@@@*...........*@@@...
@@@@@@*...........*@@@..@
@@@@@@*************@@@@.@
@@@@@@@@@.....@@@@@@@@@@@
@@@@@@@@@.....@@@@@@@@@@@

Output:

Number of colored region is: 5
New 2D array is:
@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@*************@@@@@@
@@@@@@*++++*     ++@@@@@@
@@@@@@*++++*   ++++@@@@@@
@+@@@@*++++*      +@@@@@@
@@@@@@*++++********@@++@@
@@@@@@*+++++++++++*@@@+++
@@@@@@*+++++++++++*@@@++@
@@@@@@*************@@@@+@
@@@@@@@@@+++++@@@@@@@@@@@
@@@@@@@@@+++++@@@@@@@@@@@

*/

/*
"if not using direction array"
    floodfill(i+1,j);
    floodfill(i-1,j);
    floodfill(i,j+1);
    floodfill(i,j-1);
    floodfill(i+1,j+1);
    floodfill(i+1,j-1);
    floodfill(i-1,j+1);
    floodfill(i-1,j-1);
*/
