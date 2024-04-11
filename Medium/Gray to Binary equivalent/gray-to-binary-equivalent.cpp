//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
        int ans=0,prev=0,curr;
        for(int i=31;i>=0;i--){
            // check the ith bit in n
            curr= (n>>i) & 1;
            
            // xor it with the previous bit
            curr^=prev;
            
            // store the current bit as previous for next iteration
            prev=curr;
            
            // if the curr bit after xor is 1, add its value to the ans 
            if(curr){
                ans+=(1<<i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends