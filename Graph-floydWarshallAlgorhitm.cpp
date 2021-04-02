/* Floyd Warshall Algorithms for all pair shortest path
  
     author :  himanshu3198

     time Complexity O(V^3)
     space Complexity O(V^2)
  */
#include<bits/stdc++.h>
using namespace std;
#define V 6


  void floyd_warshall(int graph[V][V]){

      int clone[V][V];

      for(int i=0;i<V;i++){
          for(int j=0;j<V;j++){
              clone[i][j]=graph[i][j];
          }
      }


      for(int k=0;k<V;k++){

         for(int i=0;i<V;i++){

             for(int j=0;j<V;j++){

                 if(clone[i][k]==INT_MAX || clone[k][j]==INT_MAX)	//SKIP if K is unreachable from i or j is unreachable from k
					continue;

                 if(clone[i][k]+clone[k][j]<clone[i][j]){

                     clone[i][j]=clone[i][k]+clone[k][j];

                 }
             }
         }

      }


      // check for  negative edge cycle



      for(int i=0;i<V;i++){
              if(clone[i][i]<0){
                  cout<<"\nNegative Edge present\n";
                  return;
              }
          
      }
    
         for(int i=1;i<V;i++){
          for(int j=0;j<V;j++){
               
               cout<<i<<" to " <<j << " sp  "<<clone[i][j]<<"\n";
          }
          cout<<"\n";
      }

  }


int main(){


   int graph[V][V] = { {0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
						{INT_MAX, 0, 4, 2, 7, INT_MAX},
						{INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
						{INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
						{INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
						{INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0} };

	floyd_warshall(graph);
	return 0;

}



