//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends

stack<int>st;
void push(stack<int>& s, int a){
	// Your code goes here
	if(st.empty() or st.top()>=a) st.push(a);
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return s.size()>=n;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.empty();
}

int pop(stack<int>& s){
	// Your code goes here
// 	if(st.empty()) return -1;
	while(!st.empty() and s.top()==st.top())st.pop(); 
	s.pop();
}

int getMin(stack<int>& s){
	// Your code goes here
// 	if(st.empty()) return -1;
	return st.top();
}