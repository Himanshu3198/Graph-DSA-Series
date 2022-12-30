// 797. All Paths From Source to Target


class Solution {
public:
    vector<vector<int>>res;
    void dfs(unordered_map<int,vector<int>>&graph,vector<int>temp,int src,int dest){
        
        if(src==dest){
            temp.push_back(src);
            res.push_back(temp);
            return;
        }
        temp.push_back(src);
        for(auto &it:graph[src]){
             dfs(graph,temp,it,dest);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>&g) {
        
        unordered_map<int,vector<int>>graph;
        int n=g.size()-1;
        for(int i=0;i<=n;i++){
            vector<int>curr=g[i];
            graph[i]=curr;
        }
        vector<int>temp;
        dfs(graph,temp,0,n);
        return res;
    }
};

class Solution {
    public void dfs(int[][]graph,List<Integer>temp,List<List<Integer>>res,int src,int dest){
        if(src==dest){
            res.add(new ArrayList<Integer>(temp));
            return;
        }
        for(int it:graph[src]){
            temp.add(it);
            dfs(graph,temp,res,it,dest);
            temp.remove(temp.size()-1);
        }
    }
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>>res=new ArrayList<>();
        List<Integer>temp=new ArrayList<>();
        int n=graph.length;
        temp.add(0);
        dfs(graph,temp,res,0,n-1);
        return res;
    }
}
