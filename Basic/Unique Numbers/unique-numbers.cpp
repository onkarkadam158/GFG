//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> uniqueNumbers(int L,int R)
    {
        // Write Your Code here
        unordered_map<int,int>mp;
        vector<int>res;
        for(int i=L;i<=R;i++){
            int n=i;
            int count=0;
            while(n){
                count++;
                mp[n%10]++;
                n=n/10;
            }
            if(count==mp.size()) res.push_back(i);
            mp.clear();
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l,r ;
        cin >> l >> r;
		Solution ob;
		vector<int> numbers = ob.uniqueNumbers(l,r);
		
		for(int num : numbers){
		   cout<<num<<" ";
		}
		cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends