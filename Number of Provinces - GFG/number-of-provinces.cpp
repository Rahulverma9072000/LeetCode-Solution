//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void traverse(vector<vector<int> > adj,int n,int sv,bool* visited)
    {
        visited[sv] = true;
        for(int i=0;i<n;i++)
        {
            if(adj[sv][i]==1 and !visited[i])
            {
                traverse(adj,n,i,visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int n) {
        //Undirected graph 
        //have to return the number of Province 
        int res = 0;
        //Visited array 
        bool* visited = new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i] = false;
        }
        //Find the result 
        for(int i = 0;i<n;i++)
        {
            if(!visited[i])
            {
                res++;
                traverse(adj,n,i,visited);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends