//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}




void displayList(Node *head)
{
    //Head to Tail
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
    
    
    
}


int getLength(Node * head)
{
    Node *temp=head;
    
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}




bool verify(Node* head)
{
    int fl=0;
    int bl=0;
    
    Node *temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
        fl++;
    }
    
    while(temp->prev)
    {
        temp=temp->prev;
        bl++;
    }
    
    return fl==bl;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/

class Solution
{
public:

    Node* bruteforce(struct Node* head){
        struct Node* res= new Node(0);
        struct Node* result=res;
        struct Node* temp=head;
        unordered_map<int,int>mp;
        while(temp){
            if(mp.find(temp->data)==mp.end()){
                struct Node* newNode = new Node(temp->data);
                res->next=newNode;
                res=res->next;
            }
            mp[temp->data]++;
            temp=temp->next;
        }
        
        return result->next;
    }
    Node* optimal(struct Node* head){
        struct Node* temp = head;
        while(temp){
            int value=temp->data;
            struct Node* temp1=temp;
            while(temp1 and temp1->data==value){
                temp1=temp1->next;
            }
            temp->next=temp1;
            if(temp1) temp1->prev=temp;
            temp=temp->next;
        }
        return head;
    }
    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        // return bruteforce(head); //time O(N) space (2N)
        return optimal(head); //time O(N) space (2N)
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL, *tail=NULL;
        int x;
	    cin>>x;
	    head = newNode(x);
	    tail = head;
	    
	    for(int i=0;i<n - 1;i++)
	    {
	        cin>>x;
	        Node* temp=newNode(x);
	        tail->next=temp;
	        temp->prev= tail;
	        tail = temp;
	    }
	    Solution obj;
	    head=obj.removeDuplicates(head);
	    
	    
	    if(verify(head))
	    displayList(head);
	    else
	    cout<<"Your pointers are not correctly connected";
 
	    cout<<endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends