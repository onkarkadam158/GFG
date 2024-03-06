//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            //bruteforce 
            vector<int>result;
            int n=pattern.size(),m=text.size();
            for(int i=0;i<m;i++){
                int left=i,right=0;
                while(left<m and right < n){
                    if(text[left]==pattern[right]){
                        left++,right++;
                    }
                    else{
                        break;
                    }
                }
                if(right==n) result.push_back(i+1);
            }
            return result;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends