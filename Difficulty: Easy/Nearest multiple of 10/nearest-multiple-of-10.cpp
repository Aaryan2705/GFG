//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        
        //Getting the length of the string str
        int n = str.length();
        
        //Getting the last digit
        int lastDigit = str[n-1] - '0';
        
        //If the last digit is less than or equal to 5, then we will take the previous multiple of 10
        //Here actually we are decreasing the value of the number to make it multiple of 10
        if(lastDigit <= 5)
        {
            str[n-1] = '0';
        }
        //If the last digit is greater than 5, then we will take the next multiple of 10
        //Here actually we are increasing the value of the number to make it multiple of 10
        else
        {
            str[n-1] = '0';
            int carry = 1;
            for(int i = n-2; i >= 0; i--)
            {
                int num = str[i] - '0';
                int sum = num + carry;
                
                //Here we are adding '0' to make it a character
                str[i] = '0' + sum % 10;
                carry = sum / 10;
                if(carry == 0)
                {
                    break;
                }
            }
            if(carry == 1)
            {
                return "1" + str;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends