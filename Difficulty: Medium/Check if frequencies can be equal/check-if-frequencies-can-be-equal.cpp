//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
{
    map<char, int> mp1;
        map<int, int> mp2;
    
        for(int i=0;i<s.length();i++)
        {
            mp1[s[i]]++;
        }
    
        if(mp1.size() == 1)
        {
            return true;
        }
        
        if(mp1.size() == 2)
        {
            int max = INT_MIN;
            for(auto itr : mp1)
            {
                if(itr.second>max)
                {
                    max = itr.second;
                }
            }
            
            for(auto itr : mp1)
            {
                if(itr.second != max)
                {
                    if((max-1) == itr.second)
                    {
                        return true;
                    }
                }
            }
        }
 
        for(auto itr : mp1)
        {
            mp2[itr.second]++;
        }
        
        if(mp2.size() == 1)
        {
            return true;
        }
        
        int mini = INT_MAX;
        int tmp = 0;
        for(auto itr : mp2)
        {
            if(itr.second<mini)
            {
                tmp = itr.first;
                mini = itr.second;
            }
        }
        int prik = 0;
        for(auto itr : mp2)
        {
            if(itr.first != tmp && mp2.size()<=2)
            {
                if(((tmp - 1) == itr.first && mp2[tmp]==1) || (tmp-1) == 0 && mp2[tmp]<=1)
                {
                    return true;
                }
            }
        }
 
        return false;
}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends