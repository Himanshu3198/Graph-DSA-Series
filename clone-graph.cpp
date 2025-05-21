/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {

    private Node dfs(Node node,Node[]visited){
       if(visited[node.val]!=null) return visited[node.val];
       Node cloneNode = new Node(node.val);
       visited[cloneNode.val]=cloneNode;

       for(Node ngr:node.neighbors){
           cloneNode.neighbors.add(dfs(ngr,visited));
       }
       return cloneNode;
    }
    public Node cloneGraph(Node node) {
        
       if(node == null) return null;
       Node[] visited = new Node[101];
       return dfs(node,visited);

    }
}
