// #1 Greedy Two Pointers
//   Complexity - Time O(n) & Space O(1)

// class Solution {
// public:
//     bool canMakeSubsequence(string source, string target) {
//         int targetIdx = 0;
//         int targetLen = target.length();
//         for (char currChar : source) {
//             if (targetIdx < targetLen && (target[targetIdx] - currChar + 26) % 26 <= 1) {
//                 targetIdx++;
//             }
//         }
//         return targetIdx == targetLen;
//     }
// };



class Solution {
public:
    bool canMakeSubsequence(string source, string target) {
        int srcLen = source.size();
        int tgtLen = target.size();
        int srcIdx = 0;
        int tgtIdx = 0;
        
        while(srcIdx < srcLen && tgtIdx < tgtLen) {
            if((source[srcIdx] == target[tgtIdx]) || 
               (source[srcIdx] == 'z' && target[tgtIdx] == 'a') || 
               (source[srcIdx] + 1 == target[tgtIdx])) {
                srcIdx++;
                tgtIdx++;
            } else {
                srcIdx++;
            }
        }
        return tgtIdx == tgtLen;
    }
};

// Complexity - Time O(n) & Space O(1)
