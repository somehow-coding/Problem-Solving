class Solution {
public:
    //all sliding window problems can be simplified as
    //at a time we have some subarray and we are required to check constraints 
    //and conditions and if that is not the case than we go for sliding.
    
    //so similarly above lines will work for this question.
    //we have to find the longest substring which have the same character.
    //so for any substring we have and if we want to make all characters same.
    //doing so in minimum operations: count all other characters other than max
    //frequency character so that count is the no of operations we requires.
    //if(opertions<=k) can perform.
    //else slide.
    
    int maxFrequency(map<char,int>& mp){
        int maxf = 0;
        for(auto [character, frequency] : mp){
            maxf = max(maxf, frequency);
        }
        return maxf;
    }
    
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        int i = 0, j = 0, maxl = 0, totalf = 0;
        while(i<size(s)){
            mp[s[i]]++;
            totalf++;
            while(totalf-maxFrequency(mp)>k){
                mp[s[j++]]--;
                totalf--;
            }
            maxl = max(maxl,i-j+1);
            i++;
        }
        return maxl;
    }
};