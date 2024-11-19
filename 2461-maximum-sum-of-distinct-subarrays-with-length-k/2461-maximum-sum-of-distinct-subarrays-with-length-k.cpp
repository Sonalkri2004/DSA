class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        set<int> s;
        int n = nums.size();
        long long sum = 0;
        long long mx = 0;

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (s.count(nums[i])) {
                sum -= nums[j];
                s.erase(nums[j]);
                j++;
            }

            s.insert(nums[i]);
            sum += nums[i];

            if (s.size() == k) {
                mx = max(mx, sum);
                sum -= nums[j];
                s.erase(nums[j]);
                j++;
            }
        }
        return mx;
    }
};


## Steps to Solve the Problem (Short Explanation)
Use a Sliding Window:

Maintain a sliding window using a set to ensure all elements in the window are unique.
Iterate Through the Array:

If the current element is already in the set, shrink the window by removing elements from the left until the current element can be added.
Add Element to Window:

Add the current element to the set and update the current sum.
Check Window Size:

If the window size equals k, calculate the maximum sum for this window, then remove the leftmost element to prepare for the next iteration.
Return Result:

After processing all elements, return the maximum sum found.
Time Complexity: O(n)
Space Complexity: O(k)
