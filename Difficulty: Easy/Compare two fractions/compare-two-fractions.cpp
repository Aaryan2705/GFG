//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
       string compareFrac(string str) {
    size_t c = str.find(", ");
    string frac1 = str.substr(0, c);
    string frac2 = str.substr(c + 2);
    int a = atoi(frac1.substr(0, frac1.find('/')).c_str());
    int b = atoi(frac1.substr(frac1.find('/') + 1).c_str());
    int c1 = atoi(frac2.substr(0, frac2.find('/')).c_str());
    int d = atoi(frac2.substr(frac2.find('/') + 1).c_str());
    if (a * d > c1 * b)
        return to_string(a) + "/" + to_string(b);
    else if (a * d < c1 * b)
        return to_string(c1) + "/" + to_string(d);
    else
        return "equal";
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends