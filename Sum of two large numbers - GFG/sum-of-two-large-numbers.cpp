//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string removeZero(string a)
    {
        if(a[0]!='0') return a;
        //If yes than return 
        int len = 0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='0') len++;
            else
            break;
        }
        return a.substr(len,a.size()-len);
    }
    string findSum(string a, string b) {
        // Your code goes here
        //Optimal Way 
        string res = "";
        //Remove the front zero's 
        a = removeZero(a);
        b = removeZero(b);
        if(a.size()==0 and b.size()==0)
        {
            return "0";
        }
        int i = a.size() - 1;
        int j = b.size() - 1;
        // cout<<"a = "<<a<<"b = "<<b<<endl;
        int carry = 0;
        while(i>=0 or j>=0 or carry)
        {
            int i_val = i>=0 ? a[i]-'0' : 0;
            int j_val = j>=0 ? b[j]-'0' : 0;
            i--;
            j--;
            int sum = i_val + j_val + carry;
            carry = sum/10;
            sum = sum%10;
            char curr_dig = sum + '0';
            res = curr_dig+res;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends