// Now we move to a harder problem.
/*After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.*/
/*Now the arrangment is a circle rather than a vector. So we can discuss in two different situation:
1. choose the first element (start from nums[0], so nums[n-1] will not be chosen.)
2. Do not choose the first element (start from nums[1], so nums[n-1] could be chosen.)
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int find(vector<int>& nums, int start, int end);
int rob(vector<int>& nums){
    int n = (int)nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];
    if(n == 2) return max(nums[0], nums[1]);
    
    int max1 = find(nums, 0, n - 2);
    int max2 = find(nums, 1, n - 1);
    
    return max(max1, max2);
}
int find(vector<int>& nums, int start, int end){
    vector<int> dp(end - start + 1,0);
    dp[0] = nums[start], dp[1] = max(nums[start], nums[start + 1]);
    for(int i = 2; i < (int)dp.size(); ++i){
        dp[i] = max(dp[i-1], dp[i-2] + nums[start + i]);
    }
    return dp[end - start];
}
int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3,5,3,2,9,4,0,3,2,4,6,8,9,3,1,2,3,3,6,2,9,3,2,3,1,0,9,0,8,5};
    cout<< rob(nums) <<endl;
    return 0;
}
