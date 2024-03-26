//{ Driver Code Starts
import java.util.*;

public class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            Solution ss = new Solution();
            boolean result = ss.isAdditiveSequence(s);
            System.out.println((result == true ? 1 : 0));
        }
        sc.close();
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
 public boolean isAdditiveSequence(String s) {
        // code here
        int first = 0;
        int n = s.length();
        for(int i = 0 ; i < n - 2 ; i++)
        {
            first = (first*10)+(int)(s.charAt(i) - '0');
            int second = 0;
            for(int j = i + 1 ; j < n - 1 ; j++)
            {
                second = (second*10) + (int)(s.charAt(j) - '0');
                int n1 = first , n2 = second;
                int third = 0 , k = 0;
                for(k = j + 1 ; k < n ; k++)
                {
                    third = (third*10) + (int)(s.charAt(k) - '0');
                    if(third == (n1 + n2))
                    {
                        n1 = n2;
                        n2 = third;
                        third = 0;
                    }
                }
            
            if(k == n && third == 0) return true;
            }
        }
        return false;
    }
}
