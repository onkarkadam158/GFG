//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int>bruteforce(vector<int> &a, vector<int> &b){
        map<int,int>mp;
        for(auto x:a)mp[x]++;
        for(auto x:b)mp[x]++;
        vector<int>res;
        for(auto a:mp)res.push_back(a.first);
        return res;
    }
    vector<int>optimal(vector<int> &a, vector<int> &b){
        vector<int>res;
        int i=0,j=0,n=a.size(),m=b.size();
        while(i<n and j<m){
            if(a[i]<b[j]){
                if(res.size()==0 or res[res.size()-1]!=a[i]) 
                    res.push_back(a[i]);
                i++;
            }   
            else if(a[i]>b[j]){
                if(res.size()==0 or res[res.size()-1]!=b[j]) 
                    res.push_back(b[j]);
                j++;
            }
            else{
                if(res.size()==0 or res[res.size()-1]!=a[i]) res.push_back(a[i]);
                i++,j++;
            }
        }
        while(i<n){
            if(res.size()==0 or res[res.size()-1]!=a[i]) 
                res.push_back(a[i]);
            i++;
        }
        while(j<m){
            if(res.size()==0 or res[res.size()-1]!=b[j]) 
                res.push_back(b[j]);
            j++;
        }
        return res;
    }
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        return bruteforce(a,b);
        return optimal(a,b);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends