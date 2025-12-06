// 210. Course Schedule II

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        
        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<indegree.size();i++){
             if(indegree[i]==0) q.push(i);
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            
            int t=q.front();
            q.pop();
            ans.push_back(t);
            
            for(int j=0;j<adj[t].size();j++){
                indegree[adj[t][j]]--;
                if(indegree[adj[t][j]]==0) q.push(adj[t][j]);
            }
            
        }
        
        if(ans.size()==numCourses) return ans;
        else{ ans.clear(); return ans;}
        
        
    
	
         
    }
};
// java code 

class Solution {
    public int[] findOrder(int num, int[][] pre) {
        
          
          Map<Integer,List<Integer>> graph = new HashMap<>();
          int [] indegree = new int[num];
          for(int [] p:pre){

               int a = p[0];
               int b = p[1];
               graph.putIfAbsent(b,new ArrayList<>());
               graph.get(b).add(a);
               indegree[a]++;
          }
          
          Queue<Integer> q = new LinkedList<>();
          for(int i=0;i<num;i++){
            if(indegree[i] == 0) q.offer(i);
          }

          int [] result = new int[num];
          int idx = 0;

          while(!q.isEmpty()){

            int course = q.poll();
            result[idx++] = course;
            for( var ngbr: graph.getOrDefault(course,new ArrayList<>())){
                 indegree[ngbr] = indegree[ngbr] -1;
                 if(indegree[ngbr] == 0){
                    q.offer(ngbr);
                 }
            }
          }
          
          int [] invalid = new int[num];
          if(idx != num) return new int[0];
          return result;
    }
}
