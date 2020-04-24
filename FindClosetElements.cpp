#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + k + left); 
        }
       
};

int main() {
    vector<int>a{0,0,1,2,3,3,4,7,7,8};
    Solution mysolution;
    vector<int> b = mysolution.findClosestElements(a,3,5);
    for (int i = 0; i < b.size(); ++i) {
        cout << b[i] << " " ;
    }
   
}
