//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int bruteforce(long long int x){
        long long int res=0;
        while(1){
            if(res*res<=x){
                res++;
            }
            else{
                return res-1;
            }
        }
        return 1;
    }
    long long int floorSqrt(long long int x) {
        // Your code goes here   
        return sqrt(x);
        return bruteforce(x);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends