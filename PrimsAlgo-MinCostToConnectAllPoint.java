class Solution {
    public int minCostConnectPoints(int[][] points) {
        
        int n = points.length;
        PriorityQueue<Pair> minHeap = new PriorityQueue<>(Comparator.comparingInt(x->x.distance));
        int [] visited = new int[n];
        Arrays.fill(visited,0);
        int totalCost = 0;
        minHeap.add(new Pair(0,0));

        while(!minHeap.isEmpty()){

            Pair top = minHeap.poll();
            int distance = top.distance;
            int i = top.x;

            if(visited[i] == 1) continue;
            visited[i] = 1;
            totalCost = totalCost + distance;

            for(int j=0;j<n;j++){

                if(visited[j] == 1) continue;
                int dist = Math.abs(points[i][0]-points[j][0]) + Math.abs(points[i][1]-points[j][1]);
                minHeap.add(new Pair(dist,j));
            }

        }

        return totalCost;
    }
}

class Pair{
    int distance;
    int x;

    public Pair(int distance,int x){
        this.distance = distance;
        this.x = x;
    }
}
