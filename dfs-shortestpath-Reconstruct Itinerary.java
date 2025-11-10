
/**
the idea is to visit all airport in lexicographically/smallest name order from one airport use priorityQueue for traversing in smalllest airport first order,
post construct the result as there may be dead end so its better to travel later.

**/

class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        
        Map<String,PriorityQueue<String>> graph = new HashMap<>();

        for(List<String> ticket:tickets){

            String dep = ticket.get(0);
            String arr = ticket.get(1);

            graph.putIfAbsent(dep,new PriorityQueue<>());
            graph.get(dep).add(arr);

        }
        List<String> result = new LinkedList<>();
        dfs("JFK",graph,result);
        return result;
    }

    private void dfs(String dep,Map<String,PriorityQueue<String>>graph,List<String> result){

        PriorityQueue<String>  arrivals = graph.get(dep);
        while(arrivals != null && !arrivals.isEmpty()){
            String newDeparture = arrivals.poll();
            dfs(newDeparture,graph,result);
        }
        result.addFirst(dep);
    }
}
