//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int ele=0,count=0;
        for(auto a:arr){
            if(count==0)
                ele=a;
            count+=(ele==a)?1:-1;
        }
        count=0;
        for(auto a:arr){
            if(ele==a)count++;
        }
        if(count>(arr.size()/2)) return ele;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends