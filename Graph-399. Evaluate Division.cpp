class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {

        int n = equations.size(), idx = 0;
        Map<String,List<Pair>> graph = new HashMap<>();
        
        for(List<String> equation:equations){

            String u = equation.get(0);
            String v = equation.get(1);
            double val = values[idx++];

            graph.putIfAbsent(u,new ArrayList<>());
            graph.get(u).add(new Pair(v,val));
            graph.putIfAbsent(v,new ArrayList<>());
            graph.get(v).add(new Pair(u,1.0/val));

        }

        double [] res = new double [queries.size()];

        for(int i=0;i<queries.size();i++){

            String s = queries.get(i).get(0);
            String d = queries.get(i).get(1);

            if (!graph.containsKey(s) || !graph.containsKey(d)) {
                res[i] = -1.0;
                continue;
            }

            Set<String> visited = new HashSet<>();
            double ans = dfs(graph,visited,s,d,1.0);
            res[i] = ans;

        }
        
        return res;
    }

    private double dfs(Map<String,List<Pair>>graph, Set<String> visited, String s, String d, double product){

        visited.add(s);

        if(s.equals(d)){
            return product;
        }

        for(var ngbr: graph.getOrDefault(s,Collections.emptyList())){
            if(!visited.contains(ngbr.eq)){
               double ans = dfs(graph,visited,ngbr.eq,d,product*ngbr.val);
               if(ans != -1.0) return ans;
            }
        }

        return -1.0;
    }
}

class Pair{

    String eq;
    double val;

    public Pair(String eq,double val){
        this.eq = eq;
        this.val = val;
    }
}
