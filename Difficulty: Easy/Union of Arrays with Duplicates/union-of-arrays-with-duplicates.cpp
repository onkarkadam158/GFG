//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        
        
        set<int>st;
        for(int i=0;i<a.size();i++)
            st.insert(a[i]);
        for(int i=0;i<b.size();i++)
            st.insert(b[i]);
        return st.size();
        
        int m=a.size(),n=b.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        int i=0,j=0;
        int count=0;
        
        while(i<m and j<n){
            if(a[i]==b[j]){
                i++,j++;
            }
            else if(a[i]<b[j]){
                i++;
            }
            else{
                j++;
            }
            count++;
        }
        return count + m-i+n-j;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> a;
        vector<int> b;

        string input;
        // For a
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // For b
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        cout << ob.findUnion(a, b) << endl;
        cout << '~' << endl;
    }

    return 0;
}
// } Driver Code Ends