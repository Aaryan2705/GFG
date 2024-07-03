//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        if(head==NULL || head->next==NULL) return head;
        
        struct Node *prev=NULL;
        struct Node *curr=head;
        Node *head1=new Node(-1);
        Node *head2=head1;
        while(curr!=NULL){
            if(prev==NULL && curr->data!=curr->next->data){
                Node *temp=new Node(curr->data);
                head1->next=temp;
                head1=temp;
            }
            else if(curr->next==NULL && curr->data!=prev->data){
                Node *temp=new Node(curr->data);
                head1->next=temp;
                head1=temp;
            }
            else if(prev!=NULL && curr->next!=NULL && curr->data!=prev->data && curr->data!=curr->next->data){
                Node *temp=new Node(curr->data);
                head1->next=temp;
                head1=temp;
            }
            prev=curr;
            curr=curr->next;
        }
        return head2->next;


    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends