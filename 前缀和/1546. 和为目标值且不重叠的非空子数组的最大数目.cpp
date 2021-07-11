using pii = pair<int, int>;
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = (int)nums.size();
        vector<int> s(n + 1, 0);
        partial_sum(nums.begin(), nums.end(), s.begin() + 1);
        unordered_map<int, int> hash;
        vector<pii> v;
        for (int r = 0; r <= n; ++r) {
            int x = s[r] - target;
            if (hash.count(x)) v.push_back({hash[x] + 1, r});
            hash[s[r]] = r;
        }
        return (v.size()) ? solve(v) : 0;
    }

    int solve(vector<pii>& v)
    {
        int res = 1;
        int st = v[0].first, ed = v[0].second;
        for (int k = 1; k < (int)v.size(); ++k) {
            if (ed < v[k].first) {
                ++res; ed = v[k].second;
            }
        }
        return res;
    }
};
// type: partial-sum + hash + greedy 

/* tips */
/*
    s[r] - s[l - 1] = target
    最大不相交区间数量
*/

/* editorial */
/*
*/

/* question */
/*
*/