class Solution {
  public:
    string addStrings(string num1,string num2) {
        string result="";
        int carry=0,i=num1.length()-1,j=num2.length()-1;
        while(i>=0 || j>=0 || carry) {
            int sum=carry;
            if(i>=0) sum+=num1[i]-'0';
            if(j>=0) sum+=num2[j]-'0';
            carry=sum/10;
            result=to_string(sum%10)+result;
            i--;
            j--;
        }
        return result;
    }
    bool check(int idx, string num1, string num2, string s, int &n){
        // next number is fixed and it should be num1+num2
        string sum=addStrings(num1,num2);
        // now search if from idx till n we find sum
        // if we find then 
        // num1=num2
        // num2=sum
        // now check for next 
        int len=sum.length();
        if(idx+len>n)return false;
        string nextStr=s.substr(idx,len);
        if(nextStr[0]=='0' && len>1)return false;
        if(nextStr==sum){
            if(idx+len==n)return true;
            return check(idx+len,num2,sum,s,n);
        }
        return false;
    }
    bool isSumString(string &s) {
        // code here
        // hard to decide on first 2
        // rest else is just simple
        // for first 2 numbers we have to try all possible combination
        int n=s.length();
        for(int i=0;i<n-2;i++){
            string first=s.substr(0,i+1);
            if(first[0]=='0'&&i+1>1)continue;
            
            for(int j=i+1;j<n-1;j++){
                string second=s.substr(i+1,j-i);
                
                if(second[0]=='0'&&j-i>1)continue;
                if(check(j+1,first,second,s,n))return true;
            }
        }
        return false;
    }
};