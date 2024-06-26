//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	bool isprime(int n){
	    for(int i=2;i<=sqrt(n);i++){
	        if(n%i==0) return false;
	    }
	    return true;
	}
	vector<int>bruteforce(int n){
	    vector<int>result;
	    for(int i=2;i<=n;i++){
	        if(n%i==0 and isprime(i)){
	            result.push_back(i);
	        }
	    }
	    
	    return result;
	}
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	    return bruteforce(N);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends