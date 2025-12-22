class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        

        int n = routes.length;
        if(source == target) return 0;
        Map<Integer,List<Integer>> busToRoute = new HashMap<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<routes[i].length;j++){

                busToRoute.computeIfAbsent(routes[i][j],x->new ArrayList<>()).add(i);
            }
        }
        int[] visitRoute = new int[100005];
        Set<Integer> visitStops = new HashSet<>();
        Queue<Integer> q = new LinkedList<>();

        q.offer(source);
        visitStops.add(source);
       
        int busTaken = 0;

        while(!q.isEmpty()){

             int size = q.size();
             busTaken++;
             for(int sz=0;sz<size;sz++){

                int curr = q.poll();
                for(int route:busToRoute.getOrDefault(curr,new ArrayList<>())){
      
                    if(visitRoute[route] ==1) continue;
                    visitRoute[route] = 1;
                    for(int r:routes[route]){

                        if(r == target) return busTaken;
                        if(!visitStops.contains(r)){
                            q.offer(r);
                            visitStops.add(r);
                        }
                    }
                 }

             }
        }

        return -1;

    }
}
