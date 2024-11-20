// class Solution {
// public:
//     int takeCharacters(string s, int k) {
//         // Total counts
//         vector<int> count(3, 0);
//         for (char c : s) {
//             count[c - 'a']++;
//         }
        
//         if (*min_element(count.begin(), count.end()) < k) {
//             return -1;
//         }
        
//         // Sliding Window
//         int res = INT_MAX;
//         int l = 0;
//         for (int r = 0; r < s.length(); r++) {
//             count[s[r] - 'a']--;
            
//             while (*min_element(count.begin(), count.end()) < k) {
//                 count[s[l] - 'a']++;
//                 l++;
//             }
//             res = min(res, static_cast<int>(s.length()) - (r - l + 1));
//         }
//         return res;
//     }
// };


class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> d(3), h(3);
        for (char c : s) d[c-'a']++;
        for (int i = 0; i < 3; i++) if ((d[i] -= k) < 0) return -1;
        
        int m = 0, l = 0;
        for (int r = 0; r < s.length(); r++) {
            h[s[r]-'a']++;
            while (l <= r && h[s[r]-'a'] > d[s[r]-'a']) h[s[l++]-'a']--;
            m = max(m, r - l + 1);
        }
        return s.length() - m;
    }
};