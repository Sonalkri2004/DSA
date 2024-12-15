// ⏱️ Complexity Analysis \U0001f680
// Time Complexity:

// Building the max-heap takes O(n log n).
// Each student distribution involves extracting the max and reinserting into the heap, which takes O(log n).
// For extraStudents, the total complexity is O(extraStudents * log n).
// Space Complexity:

// The space complexity is O(n) for the heap.



class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](double pass, double total) {
            return (pass + 1) / (total + 1) - pass / total;
        };

        priority_queue<pair<double, pair<int, int>>> maxHeap;

        double sum = 0.0;

        for (const auto& cls : classes) {
            int pass = cls[0], total = cls[1];
            sum += (double)pass / total;  
            maxHeap.push({gain(pass, total), {pass, total}});
        }

        for (int i = 0; i < extraStudents; ++i) {
            auto [currentGain, data] = maxHeap.top(); maxHeap.pop();
            int pass = data.first, total = data.second;

            sum -= (double)pass / total;
            pass += 1;
            total += 1;
            sum += (double)pass / total;

            maxHeap.push({gain(pass, total), {pass, total}});
        }

        return sum / classes.size();
    }
};