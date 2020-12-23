#include<iostream>
#include<list>
#define E endll;
using namespace std;
class Graph{

    int V;
    list<int>*adj;

     
      
    public:

         Graph(int V);
        void addEdge(int u,int v);

        void BFS(int s);

};

  Graph::Graph(int V)
  {
      this->V=V;
      adj=new list<int>[V];
  }

 void  Graph:: addEdge(int u,int v)
   {
       adj[u].push_back(v);
   }

   void Graph::BFS(int s){

       bool *visited =new bool[V];
       for(int i=0;i<V;i++)
         visited[i]=false;

         list<int>queue;

         visited[s]=true;
         queue.push_back(s);

          while(!queue.empty())
          {

              s=queue.front();
              cout<<s<<" ";
              queue.pop_front();

              for(auto i:adj[s]){

                  if(visited[i]==false)
                  {
                      visited[i]=true;
                      queue.push_back(i);
                  }

              }
          }
        


   }
int main(){

    Graph g(6);
          g.addEdge(1,2);
           g.addEdge(1,3);
            g.addEdge(2,4);
             g.addEdge(2,5);
              g.addEdge(3,5);
               g.addEdge(4,6);
                g.addEdge(5,6);


         g.BFS(1);
         return 0;


}