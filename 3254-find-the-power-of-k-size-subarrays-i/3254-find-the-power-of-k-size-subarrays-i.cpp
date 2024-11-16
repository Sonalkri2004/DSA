## solution 1

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> vec(n - k + 1, -1);

        for(int i = 0; i <= n - k; i++){
            int v = nums[i];
            bool isValid = true;

            for(int j = i; j < i + k - 1; j++){
                if(nums[j] + 1 != nums[j + 1]){
                    isValid = false;
                    break;
                }
                v = max(v, nums[j + 1]);
            }

            if(isValid){
                vec[i] = v;
            }
        }

        return vec;
    }
};

## solution 2


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        
        int n = nums.size();
        vector<int> result;
        deque<int> window;
        
        for (int i = 0; i < n; i++) {
            // Remove elements outside window
            while (!window.empty() && i - window.front() >= k) {
                window.pop_front();
            }
            
            // Check consecutive sequence
            if (window.empty() || nums[i] - nums[i-1] == 1) {
                window.push_back(i);
            } else {
                window.clear();
                window.push_back(i);
            }
            
            // Add result when window size is k
            if (i >= k-1) {
                result.push_back(window.size() == k ? nums[i] : -1);
            }
        }
        
        return result;
    }
};
