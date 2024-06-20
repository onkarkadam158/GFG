//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        int a,b,c,d;
        string a1="",b1="",c1="",d1="";
        int i=0;
        while(str[i]!='/')a1+=str[i++];
        i++;
        while(str[i]!=',')b1+=str[i++];
        i+=2;
        while(str[i]!='/')c1+=str[i++];
        i++;
        while(i<str.size())d1+=str[i++];
        
        a=stoi(a1);b=stoi(b1);c=stoi(c1);d=stoi(d1);
        
        double a2=a, b2=b, c2=c, d2=d ;
        if( (a2/b2) == (c2/d2) ) return "equal";
        else if((a2/b2) > (c2/d2) ) return to_string(a)+"/"+to_string(b);
        return to_string(c)+"/"+to_string(d);
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends