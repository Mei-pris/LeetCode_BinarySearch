#include<iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return numpow(x, N);
    }

    double numpow(double xx, long long nn) {
        if (nn == 0)
            return 1.0;
        double half = numpow(xx, nn / 2);
        if (nn % 2 == 0)
            return half * half;
        else return half * half * xx;
    }
};


int main() {
    Solution mysolution;
    double b = mysolution.myPow(1.5,7);
    cout << b << endl;
   

}