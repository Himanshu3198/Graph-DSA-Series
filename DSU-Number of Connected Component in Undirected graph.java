class Solution {
    public int findPar(int x, int[] parent) {
        if (parent[x] == x) return x;
        return parent[x] = findPar(parent[x], parent);
    }

    public void merge(int x, int y, int[] rank, int[] parent) {
        int px = findPar(x, parent);
        int py = findPar(y, parent);
        if (px == py) return;

        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[py] > rank[px]) {
            parent[px] = py;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }

    public int countComponents(int n, int[][] edges) {
        int[] parent = new int[n];
        int[] rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;   // self parent
            rank[i] = 1;
        }

        for (int[] edge : edges) {
            merge(edge[0], edge[1], rank, parent);
        }

        Set<Integer> result = new HashSet<>();
        for (int i = 0; i < n; i++) {
            result.add(findPar(i, parent));
        }
        return result.size();
    }
}
