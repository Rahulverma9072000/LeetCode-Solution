//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printBFS(vector<int> adj[],int n,int sv,bool* visited,vector<int> &res)
    {
        if(n==0) return ;
        queue<int> data;
        //Push the current starting vertex 
        data.push(sv);
        visited[sv] = true;
        while(!data.empty())
        {
            int curr = data.front();
            data.pop();
            res.push_back(curr);
            for(int j = 0;j<adj[curr].size();j++)
            {
                int currv = adj[curr][j];
                if(!visited[currv])
                {
                    data.push(currv);
                    visited[currv] = true;
                }
            }
        }
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        vector<int> res;
        //Have to return the BFS of the Graph 
        //Maintain a visited Array 
        bool* visited = new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i] = false;
        }
        printBFS(adj,n,0,visited,res);
        // for(int i=0;i<n;i++)
        // {
        //     if(!visited[i])
        //     {
        //         printBFS(adj,n,i,visited,res);
        //     }
        // }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends