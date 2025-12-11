class Solution {
 
    private boolean isValid(int i,int j,int n,int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    private int dfs(int [][]grid,int i,int j,int n,int m,int id){

        if(!isValid(i,j,n,m)) return 0;
        if(grid[i][j]!= 1) return 0;
        grid[i][j] = id;
        int left = dfs(grid,i,j-1,n,m,id);
        int right = dfs(grid,i,j+1,n,m,id);
        int up = dfs(grid,i-1,j,n,m,id);
        int down = dfs(grid,i+1,j,n,m,id);

        return 1 + left + right + up + down;
    }
    public int largestIsland(int[][] grid) {
        
        int n = grid.length;
        int id = 2;
        Map<Integer,Integer> area = new HashMap<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 1){
                    int currentArea = dfs(grid,i,j,n,n,id);
                    area.put(id,currentArea);
                    id++;
                }
            }
        }

        int ans = 1;
        int[][] dir  = {{-1,0},{1,0},{0,-1},{0,1}};
        boolean isZero = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 0){
                    isZero = true;
                    int currAns = 1;
                    Set<Integer> seen = new HashSet<>();
                    for(int k=0;k<4;k++){
                        int newI = i+dir[k][0];
                        int newJ = j+dir[k][1];
                        if(!isValid(newI,newJ,n,n) || grid[newI][newJ]== 0) continue;
                        if(seen.contains(grid[newI][newJ])) continue;
                        currAns += area.get(grid[newI][newJ]);
                        seen.add(grid[newI][newJ]);
                    }
                    ans = Math.max(ans,currAns);
                }
            }
        }
        
        if(!isZero) return n*n;
        return ans;

    }
}
