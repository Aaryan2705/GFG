//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void anss(stack<char>&s,unordered_map<char,vector<char>>&mp,char c,int arr[])
    {
        for(auto i:mp[c])
        {
            if(arr[i-'a']>0)
            {
                arr[i-'a']=0;
                anss(s,mp,i,arr);
            }
        }
        s.push(c);
    }
    
    string findOrder(string dict[], int n, int k) {
        //code here
        unordered_map<char,vector<char>>mp;
        string s,stt;
        stack<char>st;
        char c;
        int j=0,a,b,arr[26]={0};
        for(int i=0;i<n-1;i++)
        {
            s=dict[i];
            stt=dict[i+1];
            a=s.length();
            b=stt.length();
            j=0;
            while(j<a&&j<b)
            {
                if(s[j]==stt[j])
                j++;
                else
                {
                    mp[s[j]].push_back(stt[j]);
                    arr[s[j]-'a']=1;
                    arr[stt[j]-'a']=1;
                    break;
                }
            }
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]>0)
            {
                c='a'+i;
                arr[c-'a']=0;
                anss(st,mp,c,arr);
            }
        }
        s="";
        while(!st.empty())
        {
            s.push_back(st.top());
            st.pop();
        }
        return s;
    }


};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends