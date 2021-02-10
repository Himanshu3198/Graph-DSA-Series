#include<bits/stdc++.h>
using namespace std;

struct node{
    int parent;
    int rank;
};
vector<node> dsuf;
int find(int v){
    if(dsuf[v].parent==-1)
    return v;
    return dsuf[v].parent=find(dsuf[v].parent);
}
void union_op(int from,int top){
    if(dsuf[from].rank>dsuf[top].rank)
    dsuf[top].parent=from;

    else if(dsuf[from].rank<dsuf[top].rank)
    dsuf[from].parent=top;

    else
    {
        dsuf[from].parent=top;
        dsuf[top].rank+=1;
    }
    
}
bool isCyclic(vector<pair<int,int>> & edge_List)
{
    for(auto p:edge_List)
    {
        int from=find(p.first);
        int top=find(p.second);

        if(from==top)
        return true;


        union_op(from,top);
    }
    return false;
}





int main(){
    int E,V;
    cin>>E>>V;
    dsuf.resize(V);        /*mark all vertex as seprate subset  */
    for(int i=0;i<V;i++){
        dsuf[i].parent=-1;
        dsuf[i].rank=0;
    }

    vector<pair<int,int>>edge_List;
    for(int i=0;i<E;++i){
        int from,to;
        cin>>from>>to;
        edge_List.push_back({from,to});

    }

    if(isCyclic(edge_List))
       cout<<"true\n";

       else
       {
           cout<<"false\n";
       }
       return 0;
       

}