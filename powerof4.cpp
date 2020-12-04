class Solution {
public:
    bool check(double n){
        if(n!=(int)n){
            return false;
        }
        if(n==1){
            return true;
        }
        return check(n/4);
    }
    bool isPowerOfFour(int num) {
        if(num<=0){
            return false;
        }
        double n=num;
        
        return check(n);
    }
};

