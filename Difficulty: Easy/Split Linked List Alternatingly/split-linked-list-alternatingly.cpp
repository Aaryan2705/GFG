//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        Node *list1, *list2, *list1_curr, *list2_curr;
        Node *curr = head;
        list1 = new Node(curr->data);
        curr = curr->next;
        list2 = new Node(curr->data);
        curr = curr->next;
        list1_curr = list1, list2_curr = list2;
        int i = 1;
        while(curr)
        {
            if(i % 2 == 1)
            {
                list1_curr->next = new Node(curr->data);
                list1_curr = list1_curr->next;
            }
            else
            {
                list2_curr->next = new Node(curr->data);
                list2_curr = list2_curr->next;
            }
            curr = curr->next;
            i++;
        }
        return {list1, list2};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends