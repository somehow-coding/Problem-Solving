/*
let say this is the question that is asked to me in the interview:

interviewer will tell me the question let say I sum up the question to this
after confirming from him/her:

*we have fruit trees(represented in form of integer array) in a row(left to right).
*fruits[i] -> fruit type ith tree produces.
*there is two baskets and can hold a single type of fruit of any amount.
*how to pick the fruit is imp.
it is like you *must* pick *exactly one fruit* from every tree(from the start tree of your choice) and also fruits must fit in one of the baskets.

my first impression for the problem is like you we can choose any two type of fruit
and then for that like we can check for that pair and the thing it should be

so let say we take a window where we only have same type of fruit and if its not the
case we change the window or can say slide.
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxf = 0;
        map<int,int> basket;
        int left = 0, right = 0;
        while(right<size(fruits)){
            basket[fruits[right]]++;
            while(basket.size()>2){
                basket[fruits[left]]--;
                if(basket[fruits[left]]==0){
                    basket.erase(fruits[left]);
                }
                left++;
            }
            int total = 0;
            for(auto [type,num]: basket){
                total += num;
            }
            maxf = max(maxf, total);
            right++;
        }
        return maxf;
    }
};