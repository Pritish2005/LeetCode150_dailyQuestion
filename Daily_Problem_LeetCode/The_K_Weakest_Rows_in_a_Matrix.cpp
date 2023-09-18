// Question Link -> https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

// class Solution {
// public:
//     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//         vector<pair<int,int>>ones;
//         vector<int>ans;
//         for(int i=0;i<mat.size();i++){
//             int count=0;
//             for(int j=0;j<mat[0].size();j++){
//                 if(mat[i][j]==1){
//                     count++;
//                 }
//             }
//             ones.push_back({count,i});
//         }
//         sort(ones.begin(),ones.end());
//         for(int i=0;i<k;i++){
//             ans.push_back(ones[i].second);
//         }
//         return ans;
//     }
// };