class Strings{
  public:
    int N;
    vector<string> str;
    vector<vector<string>> res;
};

class Solution {
public:
    bool palindrome(string s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    
    void fun(string &s, Strings &S, int i){
        if(i==S.N){
            S.res.push_back(S.str);
            return;
        }
        for(int j=i; j<S.N; j++){
            if(palindrome(s,i,j)){
                S.str.push_back(s.substr(i,j-i+1));
                fun(s, S, j+1);
                S.str.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        Strings S;
        S.N = size(s);
        fun(s, S, 0);
        return S.res;
    }
};