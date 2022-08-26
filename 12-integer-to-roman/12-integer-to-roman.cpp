class Solution {
public:
    string intToRoman(int num) {
        map<int,string> mp;
        mp[1000] = "M"; mp[500] = "D"; mp[100] = "C"; mp[50] = "L";
        mp[10] = "X"; mp[5] = "V"; mp[1] = "I";
        mp[4] = "IV"; mp[9] = "IX"; mp[40] = "XL"; mp[90] = "XC";
        mp[400] = "CD"; mp[900] = "CM";
        string res = "";
        for(auto it = mp.rbegin(); it != mp.rend(); it++){
            auto [val,str] = *it;
            while(num>=val){
                num -= val;
                res += str;
            }
        }
        return res;
    }
};
