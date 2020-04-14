#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int m = nums.size(), left = 0, right = m - 1, pot = m, mid = 0;
        if (m == 0) return -1;
        int first = nums[0];
        if (m == 1) return first == target ? 0 : -1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= first) {
                if (mid == m - 1) break;
                if (nums[mid + 1] < first) { pot = mid + 1; break; }
                else left = mid + 1;
            }
            else {
                if (mid == 0) break;
                if (nums[mid - 1] > first) { pot = mid; break; }
                else right = mid - 1;
            }
        }

        left = nums[0] <= target ? 0 : pot;
        right = nums[0] <= target ? pot - 1 : m - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;

    }
};

int main() {
    vector<int>a{4,5,6,7,0,1,2};
    Solution mysolution;
    int b = mysolution.search(a,0);
    cout << b << endl;
}