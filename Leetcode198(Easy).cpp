/*[Leetcode No.198]You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.*/

/*
For each date i (i >= 2), we have two choices:
1.Rob. Then we could not rob at date i - 1, our profit is nums[i] + dp[i-2];
2.Not rob, then we could rob at date i - 1, our profit is now dp[i-1],

So we have: dp[i] = max(nums[i] + dp[i-2], dp[i-1])
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int rob(vector<int>& nums){
    int n = (int)nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];
    if(n == 2) return max(nums[0], nums[1]);
    vector<int> dp(n, 0);
    dp[1] = nums[0], dp[2] = max(nums[0], nums[1]);
    for(int i = 2; i < n; ++i){
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[n-1];
}


int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3,5,3,2,9,4,0,3,2,4,6,8,9,3,1,2,3,3,6,2,9,3,2,3,1,0,9,0,8,5};
    cout<< rob(nums) <<endl;
    return 0;
}
