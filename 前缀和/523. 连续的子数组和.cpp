class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> s(n + 1, 0);
        partial_sum(nums.begin(), nums.end(), s.begin() + 1);
        map<int, int> hash;
        for (int i = 0; i <= n; ++i) {
            int x = s[i] % k;
            if (hash.count(x) != 0)  {
                if (i - hash[x] >= 2) return true;
            }
            else hash[x] = i; 
        }
        return false;
    }
};
// type: partial-sum + hash

/* tips */
/*
    边界: [0] 1 -> if (i - hash[x] >= 2) return true;
    hash[0] == 0; -> if (hash[x] != 0) is wrong!
    s[r] - s[l - 1] = n * k
    s[r] ≡ s[l - 1] (mod k)
    1 <= l <= n; 2 <= r <= n; 0 <= l - 1 <= n - 1;
*/

/* editorial */
/*
*/

/* question */
/*
*/