//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        map<int,vector<int>>mp;
        vector<int>v;
        v.push_back(0);
        for(int i=0;i<n;i++){
            mp[arr[i].dead].push_back(arr[i].profit);
        }
        for(auto it:mp) v.push_back(it.first);
        priority_queue<int>pq;
        sort(v.begin(),v.end());
        int time=v.back();
        v.pop_back();
        int cnt=0,sum=0;
        while(time!=0){
            int ntime=v.back();
            int have=time-ntime;
            for(auto it:mp[time]){
                pq.push(it);
            }
            while(pq.size()>0 and have>0){
                 sum+=pq.top();
                 pq.pop();
                 have--,cnt++;
            }
            time=ntime;
            v.pop_back();
        }
        return {cnt,sum};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends