//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    // code to perforn in-order traversal of BSTs and form two sorted arrays
    
    void inOrderTraversal(Node* root, vector<int>& ans) {
        stack<Node*> s;
        Node* temp = root;
    
        while (!s.empty() || temp!=NULL) {
            while (temp!=NULL) {
                s.push(temp);
                temp = temp->left;
        }
        temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        temp = temp->right;
    }
}
    // code to merge two sorted vector using merge sort
    
    vector<int> MergeSortedVectors(vector<int>& v1,vector<int>& v2) {
        vector<int> mergedArr;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) {
                mergedArr.push_back(v1[i]);
                i++;
            } 
            else {
                mergedArr.push_back(v2[j]);
                j++;
            }
        }
        while (i < v1.size()) {
            mergedArr.push_back(v1[i]);
            i++;
        }
        while (j < v2.size()) {
            mergedArr.push_back(v2[j]);
            j++;
        }
        return mergedArr;
    }

    vector<int> merge(Node *root1, Node *root2) {
        vector<int> v1, v2;
        inOrderTraversal(root1, v1);
        inOrderTraversal(root2, v2);
        return MergeSortedVectors(v1, v2);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends