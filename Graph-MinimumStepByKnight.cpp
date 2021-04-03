#include<bits/stdc++.h>
#define N 6
using namespace std;

int Knight(int chess[N][N],vector<int>&KnightPos,vector<int>&targetPos,int n){

 int x1=KnightPos[0];
 int y1=KnightPos[1];
 int x2=targetPos[0];
 int y2=targetPos[1];

 if(x1==x2 and y1==y2){
     return 0;
 }

 queue<pair<int,int>>q;
 q.push(make_pair(x1-1,y1-1));

 while(!q.empty()){

     auto cur=q.front();
     int i=cur.first;
     int j=cur.second;
     q.pop();


     if((i+1)>=0 and (i+1)<n and (j+2)>=0 and (j+2)<n and )

 }

   

}

int main(){

    int chess[N][N];
    vector<int>knightPos={4,5};
    vector<int>targetPos={1,1};

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            chess[i][j]=0;
        }
    }

    cout<<Knight(chess,knightPos,targetPos,N);
}