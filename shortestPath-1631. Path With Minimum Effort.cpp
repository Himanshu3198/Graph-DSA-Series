class Solution {
public:
    
/* the is to use dijktra's algo here but here little manipuatlion will happen instead of considering current 
   distance we have to maxium distance so far in a particular route
     Time Complexity O(m*nlog(m*n)
     Space Complexity O(m*n)
     */
    
      int dx[4]={-1,1,0,0};
      int dy[4]={0,0,1,-1};
    bool isValid(int i,int j,int n,int m){
        if(i>=0 and i<n and j>=0 and j<m) return true;
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>>dist(101,vector<int>(101));
        dist.assign(101,vector<int>(101,INT_MAX));
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int size=pq.size();
            while(size--){
                 int prevDist=pq.top().first;
                 int i=pq.top().second.first;
                 int j=pq.top().second.second;
                 pq.pop();
                 if(i==n-1 && j==m-1) return prevDist;
                 for(int k=0;k<4;k++){
                     int x=dx[k]+i;
                     int y=dy[k]+j;
                     if(isValid(x,y,n,m)){
                         int newDist=max(prevDist,abs(heights[i][j]-heights[x][y]));
                         if(newDist<dist[x][y]){
                             dist[x][y]=newDist;
                             pq.push({newDist,{x,y}});
                         }  
                     }
                 }
            }
        }
                        
        return 0;
        
        
        
    }
};

// java implementation 

class Solution {

    private boolean isValid(int x,int y,int n, int m){

        return x>=0 && y>=0 && x<n && y<m;
    }
    public int minimumEffortPath(int[][] heights) {
        
        int m = heights[0].length;
        int n = heights.length;
        int [] dx = {0,1,-1,0};
        int [] dy = {1,0,0,-1};
        
        int dist[][] = new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(dist[i],Integer.MAX_VALUE);
        }
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(p -> p.distance));
        pq.add(new Pair(0,0,0));
        dist[0][0] = 0;

        while(!pq.isEmpty()){

            Pair top = pq.poll();
            int x = top.u;
            int y = top.v;
            int w = top.distance;

            if(x == n-1 && y == m-1) return w;

            for(int k=0;k<4;k++){
                int newX = dx[k]+x;
                int newY = dy[k]+y;

                if(!isValid(newX,newY,n,m)) continue;

                int currDist = Math.max(w,Math.abs(heights[x][y]-heights[newX][newY]));
                if(currDist <dist[newX][newY]){
                    pq.add(new Pair(newX,newY,currDist));
                    dist[newX][newY] = currDist;
                }
            }
        }

         return 0;
    }
}

class Pair{
    int u;
    int v;
    int distance;

    public Pair(int u,int v,int distance){
        this.u = u;
        this.v = v;
        this.distance = distance;
    }
}
