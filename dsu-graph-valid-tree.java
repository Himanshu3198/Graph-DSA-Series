class Solution {
    public boolean validTree(int n, int[][] edges) {

        if(edges.length != n-1) return false;

        int [] parent = new int[n];
        int [] rank = new int[n];

        for(int i=0; i<n ; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        
        for(int []edge:edges){
            int u = edge[0];
            int v = edge[1];
            if(!merge(u,v,rank,parent)) return false;
        }
        
        return true;

    }

    private int findPar(int x,int [] parent){
        if(x == parent[x]) return parent[x];
        return parent[x] = findPar(parent[x],parent);
    }

    private boolean merge(int u, int v, int[] rank, int[] parent){
        
        int x = findPar(u,parent);
        int y= findPar(v,parent);

        if(x == y) return false;
        if(rank[x] > rank[y]){
            parent[y] = x;
            rank[x]++;
        }else{
            parent[x] = y;
            rank[y]++;
        }

        return true;

    }

}
