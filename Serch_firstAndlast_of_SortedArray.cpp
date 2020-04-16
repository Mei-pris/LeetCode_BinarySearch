#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{ -1,-1 };
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <=right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                res[0] = searchmin(nums, target, left, mid);
                res[1] = searchmax(nums, target, mid, right);
                return res;
            }
            else if (nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return res;

    }

    int searchmin(vector<int>& nums, int target, int leftt, int rightt) {
        while (leftt + 1 < rightt) {
            int mid1 = leftt + (rightt - leftt) / 2;
            if (nums[mid1] < target) leftt = mid1;
            else rightt = mid1;
        }
        if (nums[leftt] == target) return leftt;
        return rightt;
    }


    int searchmax(vector<int>& nums, int target, int leftt, int rightt) {
        while (leftt + 1 < rightt) {
            int mid2 = leftt + (rightt - leftt) / 2;
            if (nums[mid2] > target) rightt = mid2;
            else leftt = mid2;
        }
        if (nums[rightt] == target) return rightt;
        else return leftt;
    }
};

int main() {
    vector<int>a{5,5,8,8,8,10}; 
    Solution mysolution;
    vector<int> b = mysolution.searchRange(a, 5);
    cout << b[0]<<" "<<b[1]<< endl;
}