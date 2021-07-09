class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> v1(n, 1);
        vector<int> v2(n, 1);
        vector<int> res(n, 1);
        for (int k = 1; k <= n - 1; ++k) v1[k] = v1[k - 1] * nums[k - 1];
        for (int k = n - 2; k >= 0; --k) v2[k] = v2[k + 1] * nums[k + 1];
        for (int k = 0; k <= n - 1; ++k) res[k] = v1[k] * v2[k];
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
    你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
*/