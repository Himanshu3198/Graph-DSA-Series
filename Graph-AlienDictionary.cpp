// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++



 
class Solution{
    public:
    
  
  
    string findOrder(string dict[], int N, int K) {
        //code here
              vector<int>adj[26];
        int indegree[26];
        for(int i=0;i<26;i++){
            indegree[i]=0;
        }
        
        string ans="";
        for(int i=0;i<N-1;i++){
            string a=dict[i];
            string b=dict[i+1];
            int j=0;
            int k=0;
            while(j<a.size() && k<b.size() && a[j]==b[k]){
                j++;
                k++;
            }
            
            if(j<a.size() && k<b.size()){
                adj[a[j]-'a'].push_back(b[k]-'a');
                indegree[b[k]-'a']++;
                
            }
        }
        
        queue<int>q;
        for(int i=0;i<K;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            int s=q.size();
            while(s--){
               
                int p=q.front();
                q.pop();
               ans.push_back(p+97);
                // cout<<ans<<endl;
                for(int j=0;j<adj[p].size();j++){
                    int next=adj[p][j];
                    indegree[next]--;
                    if(indegree[next]==0){
                        q.push(next);
                    }
                }
                
                
            }
        }
        
        // cout<<ans<<endl;
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
