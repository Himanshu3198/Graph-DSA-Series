/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    void dfs(Node *curr,Node *node,vector<Node*>&visit){
        visit[node->val]=node;
        for(auto ele:curr->neighbors){
            if(visit[ele->val]==NULL){
                Node *newnode=new Node(ele->val);
                node->neighbors.push_back(newnode);
                dfs(ele,newnode,visit);
            }
            else{
                 node->neighbors.push_back(visit[ele->val]); 
            }
          
            
            
        }
    }
    Node* cloneGraph(Node* node) {
        
        if(node==NULL){
            return NULL ;
        }
           vector<Node*>visit (1000,NULL);
        
        Node *copy=new Node(node->val);
         visit[node->val]=copy;
        
        for(auto nodefriend:node->neighbors){
            if(visit[nodefriend->val]==NULL){
            
                  Node *newnode=new Node(nodefriend->val);
                copy->neighbors.push_back(newnode);
                dfs(nodefriend,newnode,visit);
            }
            else{
                copy->neighbors.push_back(visit[nodefriend->val]);   
            }
        }
        
        return copy;
        
    }
};
