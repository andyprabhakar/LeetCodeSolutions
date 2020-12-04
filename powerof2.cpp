class Solution {
public:
    bool isPowerOfTwo(int n) {
         int x=(INT_MAX)/2+1;
        return (n>0 && x%n==0);
    }
};