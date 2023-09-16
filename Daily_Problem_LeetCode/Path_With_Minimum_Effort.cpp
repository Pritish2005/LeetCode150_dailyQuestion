// // Question Link -> https://leetcode.com/problems/path-with-minimum-effort/

// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         // Dijkstra's algo

//         // min priority queue {diff,{row,col}}
//        priority_queue<pair<int,pair<int,int>>,
//        vector<pair<int,pair<int,int>>>,
//        greater<pair<int,pair<int,int>>>>pq;

//         int m=heights.size();
//         int n=heights[0].size();

//         // Another matrix to track min effort
//         vector<vector<int> >dist(m,vector<int>(n,1e9));
//         // First effort as zero
//         dist[0][0]=0;
//         pq.push({0,{0,0}});

//         // To move Thru matrix
//         int dr[]={-1,0,1,0};
//         int dc[]={0,-1,0,1};

//         while(!pq.empty()){
//             // Find top
//             auto it=pq.top();
//             // Removing min diff wala pair
//             pq.pop();

//             int diff=it.first;
//             int row=it.second.first;
//             int col=it.second.second;
//             if(row==m-1&&col==n-1){
//                 return diff;
//             }
//             for(int i=0;i<4;i++){
//                 int newr=row+dr[i];
//                 int newc=col+dc[i];
//                 if(newr>=0 && newc>=0 && newr<m && newc<n){
//                     // CAUTION
//                     // So that if a prev effort was more that next one it doesnt misunderstand the max diff in path
//                     int newEffort=max(abs(heights[newr][newc]-heights[row][col]),diff);
//                     // Only if new effort is lesser that previously stored diff at dist then we update it
//                     if(newEffort<dist[newr][newc]){
//                         dist[newr][newc]=newEffort;
//                         pq.push({newEffort,{newr,newc}});
//                     }
//                 }
//             }
//         }
//       return dist[m][n];
//     }
// };