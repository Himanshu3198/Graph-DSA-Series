// 752. Open the Lock

class Solution {
public:
    
       /* In this problem we need to make lock pattern in minimum no of operation 
       but keep in mind during generating the  possible pattern current pattern will 
       not equal to deadends if it is then  we cannot  move onward from that particular
       pattern  we generate it using bfs effectively by increament or decreament pattern
        and we can use set to know wheater current pattern is not equal to deadend */
    int openLock(vector<string>& deadends, string target) {
        
        
         unordered_set<string>vis;
        
        
        for(string it:deadends){
            vis.insert(it);
        }
        
        
        queue<string>q;
        
        q.push("0000");
        
        if(vis.count("0000")){
            return -1;
        }
        vis.insert("0000");
        
        int step=0;
        
        while(!q.empty()){
            
            
            int size=q.size();
          
            while(size--){
             string str=q.front();
              q.pop();
                for(int i=0;i<4;i++){
                    
                    if(str==target){
                        return step;
                    }
                      
                    char ch=str[i];
                    
                    
                    int op1=str[i]-'0';
                      op1++;
                    int op2=str[i]-'0';
                    op2--;
                    
                    if(op1==10){
                        op1=0;
                    }
                    if(op2==-1){
                        op2=9;
                    }
                    
                    str[i]=op1+'0';
          
                      if(!vis.count(str)){
                          vis.insert(str);
                         q.push(str);
                      }
                    
                    
                    str[i]=op2+'0';
                    
                    if(!vis.count(str)){
                        vis.insert(str);
                        q.push(str);
                    }
                      
                    str[i]=ch;
                    
                }
               
            }
             step++;
        }
        
        return -1;
    }
};
