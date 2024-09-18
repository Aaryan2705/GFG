//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x) {
        int len = 0;
        for(char ch: x) {
            if(ch == '{' || ch == '(' || ch == '[') 
                x[len++] = ch;
            else if(ch == '}' && x[len-1] == '{') 
                len--;
            else if(ch == ')' && x[len-1] == '(') 
                len--;
            else if(ch == ']' && x[len-1] == '[') 
                len--;
            else 
                return false;
        }
        return len == 0;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends