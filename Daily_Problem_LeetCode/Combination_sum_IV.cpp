// Question ->  https://leetcode.com/problems/combination-sum-iv/

// class Solution {
// public:
// int Combination(vector<int>&nums,int target,vector<int>&dp){
//     if(target==0){
//         return 1;
//     }
//     if(target<0){
//         return 0;
//     }
//     // Why target as index -> to store value changing value of target
//     if(dp[target]!=-1){
//         return dp[target];
//     }

//     int ans=0;
//     for(int i=0;i<nums.size();i++){
//         ans+=Combination(nums,target-nums[i],dp);
//         dp[target]=ans;
//     }
//     return dp[target];
// }

//     int combinationSum4(vector<int>& nums, int target) {
//         vector<int>dp(target+1,-1);
//         return Combination(nums,target,dp);
//     }
// };