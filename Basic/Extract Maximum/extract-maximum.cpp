//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
  public:
    
    int extractMaximum(string S) 
    { 
        //code here.
        vector<string>res;
        string temp="";
        for(auto a:S){
            if(a<='9' and a>='0'){
                temp+=a;
            }
            else{
                if(temp!="") res.push_back(temp);
                temp="";
            }
        }
        if(temp!=""){
            res.push_back(temp);
        }
        if(res.size()==0) return -1;
        int result=INT_MIN;
        for(auto a:res){
            result=max(result,stoi(a));
        }
        return result;
    } 
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.extractMaximum(S)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends