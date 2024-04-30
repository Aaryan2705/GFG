//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to reverse the linked list
    struct Node* reverse(struct Node* head){
        struct Node* temp = head;
        struct Node* nxt = head;
        struct Node* prev = NULL;
        while(temp!=NULL){
            nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // removing the non - significant zeros
        struct Node* t1 = num1;
        struct Node* t2 = num2;
        while(t1!=NULL and t1->data==0){
            t1 = t1->next;
        }
        while(t2!=NULL and t2->data==0){
            t2 = t2->next;
        }
        // edge case 
        if(t1==NULL) return (t2==NULL)? new struct Node(0) : t2;
        if(t2==NULL) return (t1==NULL)? new struct Node(0) : t1;
        // reverse the numbers
        struct Node* revnum1 = reverse(t1);
        struct Node* revnum2 = reverse(t2);
        
        // new linked list to store the answer
        struct Node* dummy = new struct Node(-1);
        struct Node* ptr = dummy;
        
        struct Node* temp1 = revnum1;
        struct Node* temp2 = revnum2;
        
        int carry = 0;
        while(temp1!=NULL && temp2!=NULL){
            int val = carry + temp1->data + temp2->data;
            if(val>9) carry = 1;
            else carry = 0;
            val = val%10;
            struct Node* temp = new struct Node(val);
            ptr->next = temp;
            ptr = ptr->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        // if num2 > num1, to add the remaining digits;
        if(temp1==NULL){
            if(carry == 0) ptr->next = temp2;
            else{
                while(temp2!=NULL){
                    int val = carry + temp2->data;
                    if(val>9) carry = 1;
                    else carry = 0;
                    val = val%10;
                    struct Node* temp = new struct Node(val);
                    ptr->next = temp;
                    ptr = ptr->next;
                    temp2 = temp2->next;
                }
                //if there is still a carry at the end
                if(carry == 1) ptr->next = new struct Node(1);
            }
        }
        if(temp2 == NULL){
            if(carry == 0) ptr->next = temp1;
            else{
                while(temp1!=NULL){
                    int val = carry + temp1->data;
                    if(val>9) carry = 1;
                    else carry = 0;
                    val = val%10;
                    struct Node* temp = new struct Node(val);
                    ptr->next = temp;
                    ptr = ptr->next;
                    temp1 = temp1->next;
                }
                // if there is still a carry at the end
                if(carry == 1) ptr->next = new struct Node(1);
            }
        }
        // return the reverse
        return reverse(dummy->next);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends