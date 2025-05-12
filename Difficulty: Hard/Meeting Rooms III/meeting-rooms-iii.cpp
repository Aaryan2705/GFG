//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
        // ofcouse we will first do meetings which has early start time
        sort(meetings.begin(),meetings.end());
        
        priority_queue<int,vector<int>,greater<>>freerooms;
        // minheap which will contain smallest free room available
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>busyrooms;
        // minheap which has end_time,room_idx
        // to know which room becomes free earliest by endtime
        vector<int>freq(n,0);
        
        // intially all are free
        for(int i=0;i<n;i++){
            freerooms.push(i);
        }
        
        // then lets start one by one from meetings
        for(auto it:meetings){
            int st=it[0];
            int et=it[1];
            // free all those rooms whose endtime is lesser than startime of
            // current meeting
            while(!busyrooms.empty() && busyrooms.top().first <= st){
                freerooms.push(busyrooms.top().second);
                busyrooms.pop();
            }

            // search first for a free room 
            if(!freerooms.empty()){
                int room=freerooms.top();
                freerooms.pop();
                freq[room]++;
                busyrooms.push({et,room});
            }
            else{
                // if no room is free then we delay our job and assign it to 
                // lowest endtime in busyroom
                int t=busyrooms.top().first;
                int room_idx=busyrooms.top().second;
                t+=(et-st);
                busyrooms.pop();
                busyrooms.push({t,room_idx});
                freq[room_idx]++;
            }
        }
        
        int max_room_used=0;
        for(int i=1;i<n;i++){
            if(freq[i]>freq[max_room_used]){
                max_room_used=i;
            }
        }
        return max_room_used;
    }
};

//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends