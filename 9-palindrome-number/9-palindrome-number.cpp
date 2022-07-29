class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long y = 0, n = x;
        while(n){
            y = y * 10 + (n%10);
            n /= 10;
        }
        return (x==y);
    }
};