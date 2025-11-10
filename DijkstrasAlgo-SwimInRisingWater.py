import heapq
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:

        n = len(grid)
        INF = float('inf')
        dist = [[INF]*n for _ in range(n)]
        pq = [(grid[0][0],0,0)]
        dist[0][0] = grid[0][0]
        direction = [(0,1),(1,0),(0,-1),(-1,0)]


        while len(pq) >0 :

            time,x,y = heapq.heappop(pq)
            if x == n-1 and y == n-1 :
                return time
            for dx,dy in direction:
                new_x, new_y = x+dx,y+dy
                if new_x<0 or new_y<0 or new_x>=n or new_y>=n:
                 continue
                new_time = max(time,grid[new_x][new_y])
                if new_time<dist[new_x][new_y]:
                    dist[new_x][new_y] = new_time
                    heapq.heappush(pq,(new_time,new_x,new_y))
        
        
        return dist[n-1][n-1]


        
