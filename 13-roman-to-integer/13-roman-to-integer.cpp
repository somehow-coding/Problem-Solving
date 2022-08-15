class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I'] = 1, mp['V'] = 5, mp['X'] = 10, mp['L'] = 50,
        mp['C'] = 100, mp['D'] = 500, mp['M'] = 1000;
        int num = 0;
        /*
        for(int i=0;i<size(s);i++){
            if(s[i]=='I'){
                if(i+1==s.size()){
                    num += 1;
                    continue;
                }
                if(s[i+1]=='V'){
                    num += 4;
                    i++;
                }
                else if(s[i+1]=='X'){
                    num += 9;
                    i++;
                }
                else{
                    num += 1;
                }
            }
            else if(s[i]=='X'){
                if(i+1==s.size()){
                    num += 10;
                    continue;
                }
                if(s[i+1]=='L'){
                    num += 40;
                    i++;
                }
                else if(s[i+1]=='C'){
                    num += 90;
                    i++;
                }
                else{
                    num += 10;
                }
            }
            else if(s[i]=='C'){
                if(i+1==s.size()){
                    num += 100;
                    continue;
                }
                if(s[i+1]=='D'){
                    num += 400;
                    i++;
                }
                else if(s[i+1]=='M'){
                    num += 900;
                    i++;
                }
                else{
                    num += 100;
                }
            }
            else{
                num += mp[s[i]];
            }
        }*/
        
        for(int i=0;i<s.size();i++){
            if(s.size()==i+1){
                num += mp[s[i]];
                continue;
            }
            if(mp[s[i]]<mp[s[i+1]]){
                num -= mp[s[i]];
            }
            else{
                num += mp[s[i]];
            }
        }
        
        return num;
    }
};