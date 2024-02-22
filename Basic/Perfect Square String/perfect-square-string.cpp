//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int isSquare(string S);

int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        cout << isSquare(S) << endl;
    }
return 0;
}
// } Driver Code Ends


int isSquare(string S){
    //complete the function here
    int sum=0;
    for(auto a:S){
        sum+=(a);
    }
    int temp=sqrt(sum);
    return temp*temp == sum;
}