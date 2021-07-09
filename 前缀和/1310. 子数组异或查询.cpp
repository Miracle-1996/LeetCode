class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = (int)arr.size();
        int m = (int)queries.size();
        vector<int> v(n, 0);
        v[0] = arr[0];
        for (int k = 1; k <= n - 1; ++k) v[k] = v[k - 1] ^ arr[k];
        vector<int> res(m);
        for (int k = 0; k <= m - 1; ++k) {
            int l = queries[k][0], r = queries[k][1];
            res[k] = (0 == l) ? (v[r]) : v[r] ^ v[l - 1];
        }
        return res;
    }
};
// type: partial-sum idea

/* tips */
/*
*/

/* editorial */
/*
*/

/* question */
/*
*/