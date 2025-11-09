import java.util.*;

class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        
        int[] dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[k] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(p -> p.distance));
        List<List<Pair>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            graph.get(u).add(new Pair(w, v)); 
        }

        pq.add(new Pair(0, k));

        while (!pq.isEmpty()) {
            Pair minTime = pq.poll();
            int u = minTime.src;
            int currDist = minTime.distance;

            if (currDist > dist[u]) continue;

            for (Pair edge : graph.get(u)) {
                int v = edge.src;
                int w = edge.distance;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.add(new Pair(dist[v], v)); 
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == Integer.MAX_VALUE) return -1;
            maxTime = Math.max(maxTime, dist[i]);
        }

        return maxTime;
    }
}

class Pair {
    int src;       
    int distance;  

    public Pair(int distance, int src) {
        this.src = src;
        this.distance = distance;
    }
}
