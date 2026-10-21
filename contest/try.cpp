#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        if(size==1) return nums[0];
        if(size==2) return max(nums[0],nums[1]);
        if(size==3) return max((nums[0]+nums[2]),nums[1] );

        vector<int> sub2(nums.begin() + 2, nums.end());
        vector<int> sub3(nums.begin() + 3, nums.end());
        
        return max((nums[0] + rob(sub2)), (nums[1] + rob(sub3)));
    }  
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    vector<int>nums={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20,21,23,25,27,29,31,33,35,37,39,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,99,97,95,93,91,89,87,85,83,81,79,77,75,73,71,69,67,65,63,61,59,57,55,53,51,49,47,45,43,41,39,37,35,33,31,29,27,25,23};
    Solution sol;
    cout<<sol.rob(nums);

    return 0;
}