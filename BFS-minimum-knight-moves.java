class Pair{

    int dist;
    int x1;
    int y1;

    public Pair(int dist,int x1,int y1){
        this.dist = dist;
        this.x1 = x1;
        this.y1 = y1;
    }
}
class Solution {

    public int minKnightMoves(int x, int y) {
        
        x = Math.abs(x);
        y = Math.abs(y);
        int[][] dir = {{-1,-2},{-1,2},{-2,-1},{-2,1},{1,-2},{1,2},{2,-1},{2,1}}; 

        Queue<Pair> q = new LinkedList<>();
        Set<String> seen = new HashSet<>();

        q.offer(new Pair(0,0,0));
        seen.add(new String("0,0"));


        while(!q.isEmpty()){

            Pair curr = q.poll();
            if( curr.x1 == x && curr.y1 == y){
                return curr.dist;
            }
            for(int k = 0;k<8;k++){
                int dx = curr.x1+dir[k][0];
                int dy = curr.y1+dir[k][1];
                if(dx < -2 || dy < -2) continue;
                String visit = String.valueOf(dx)+","+String.valueOf(dy);
                if(!seen.contains(visit)){
                     q.offer(new Pair(curr.dist+1,dx,dy));
                     seen.add(visit);
                }
                 
            }
        }

        return -1;

    }
}
