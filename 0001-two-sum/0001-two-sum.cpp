// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         // Create a copy of the array with indices
//         vector<pair<int, int>> numbersWithIndices;
//         for (int i = 0; i < numbers.size(); i++) {
//             numbersWithIndices.push_back({numbers[i], i});
//         }
        
//         // Sort the array based on values
//         sort(numbersWithIndices.begin(), numbersWithIndices.end());
        
//         int left = 0;
//         int right = numbers.size() - 1;
        
//         while (left < right) {
//             int sum = numbersWithIndices[left].first + numbersWithIndices[right].first;
//             if (sum == target) {
//                 return {numbersWithIndices[left].second, numbersWithIndices[right].second};
//             } else if (sum < target) {
//                 left++;
//             } else {
//                 right--;
//             }
//         }
        
//         return {}; // Return empty vector if no solution found
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int i=0,j=i+1;
        for(i=0;i<nums.size()-1;i++){
            for(j=i+1;j<nums.size();j++){
                if( nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
        
    }
};