class Solution {
public:
     int checkPalindromic(string s, int left,int right){//start, len
        while(left >=0 && right < s.size() && (s[left] == s[right]) ){
            left -=1;
            right +=1;
        }
        left +=1 ;
        right -=1;
        return (right-left+1); //return len
    }
   
    string longestPalindrome(string s) {
        string maxStr;
        
        if(s.size()==1)
            return s;
        int maxLen = 0;
        int start_pos;
        for(int i=0;i<s.size();i++){
            
            int odd_str_len = checkPalindromic(s,i,i);//奇數str
            int even_str_len = checkPalindromic(s,i,i+1);//偶數str
            
            int t_max = max(odd_str_len,even_str_len);
            //int start_pos;
            if(maxLen < t_max){ // 
                maxLen = t_max;
                start_pos = i - (maxLen -1)/2; //找到start pos
            }
        }  
            return s.substr(start_pos,maxLen); 
    }
  
};
