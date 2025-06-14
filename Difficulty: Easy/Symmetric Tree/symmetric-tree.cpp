/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool check(Node* left, Node* right){
        if(left == NULL && right == NULL) return true;
        if(!(left && right)) return false;
        
        
        if(left -> data == right -> data){
            bool check1 = check(left -> right, right -> left);
            bool check2 = check(left -> left, right -> right);
            
            return (check1 && check2);
        }
        
        return false;
    }
  
    bool isSymmetric(Node* root) {
        return check(root, root);
    }
};