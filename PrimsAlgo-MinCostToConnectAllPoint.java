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

// python code


import heapq
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        visited = [0 for _ in range(0,n)]
        min_heap = [(0,0)]
        total_cost = 0;

        while len(min_heap) > 0 :
            distance,i = heapq.heappop(min_heap);
            if visited[i] == 1 :
                continue;
            total_cost = total_cost + distance
            visited[i] = 1

            for j in range(0,n):
                if visited[j] == 1:
                    continue
                dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])
                heapq.heappush(min_heap,(dist,j))
        
        return total_cost
        
