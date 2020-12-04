int gcd(int A, int B){
    if(A==0) return B;
    if(B==0) return A;
    if(A<B) swap(A, B);
    return gcd(A%B, B);
}
int Solution::cpFact(int A, int B) {
    for(int g=gcd(A, B); g>1; g=gcd(A, g)) A/=g;
    return A;
}