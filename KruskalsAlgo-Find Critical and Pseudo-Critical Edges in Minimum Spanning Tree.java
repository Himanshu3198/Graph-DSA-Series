/**
  the idea is find the edge that exlusion will result in increase in wt of mst - crtical one , while some can be part of mst but when removal can be increase mst wt pseudo critical solved using kruskals 
**/

import java.util.*;

class Edge implements Comparable<Edge> {
    int src, dest, wt, index;
    public Edge(int src, int dest, int wt, int index) {
        this.src = src;
        this.dest = dest;
        this.wt = wt;
        this.index = index;
    }
    @Override
    public int compareTo(Edge other) {
        return this.wt - other.wt;
    }
}

class Dsu {
    int[] parent, rank;
    public Dsu(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    public int findPar(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findPar(parent[x]);
    }

    public boolean union(int x, int y) {
        int u = findPar(x), v = findPar(y);
        if (u == v) return false;
        if (rank[u] < rank[v]) parent[u] = v;
        else if (rank[v] < rank[u]) parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
        return true;
    }
}

class Solution {
    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
        List<Edge> edgeList = new ArrayList<>();
        for (int i = 0; i < edges.length; i++) {
            edgeList.add(new Edge(edges[i][0], edges[i][1], edges[i][2], i));
        }

        Collections.sort(edgeList);
        int expectedWt = findMstWt(edgeList, n, -1, null);

        List<Integer> criticalEdges = new ArrayList<>();
        List<Integer> pseudoEdges = new ArrayList<>();

        for (Edge edge : edgeList) {
            // Case 1: skip this edge
            int withoutEdge = findMstWt(edgeList, n, edge.index, null);
            if (withoutEdge > expectedWt) {
                criticalEdges.add(edge.index);
                continue;
            }

            // Case 2: force include this edge
            int withForcedEdge = findMstWt(edgeList, n, -1, edge);
            if (withForcedEdge == expectedWt)
                pseudoEdges.add(edge.index);
        }

        return Arrays.asList(criticalEdges, pseudoEdges);
    }

    private int findMstWt(List<Edge> edges, int n, int skipIndex, Edge forceEdge) {
        Dsu ds = new Dsu(n);
        int totalWt = 0;
        int count = 0;

        if (forceEdge != null && ds.union(forceEdge.src, forceEdge.dest)) {
            totalWt += forceEdge.wt;
            count++;
        }

        for (Edge e : edges) {
            if (e.index == skipIndex) continue;
            if (ds.union(e.src, e.dest)) {
                totalWt += e.wt;
                count++;
            }
        }

        return count == n - 1 ? totalWt : Integer.MAX_VALUE;
    }
}
