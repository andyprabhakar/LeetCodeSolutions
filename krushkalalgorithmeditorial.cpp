bool compare(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

int getClass(int group[], int x) {
    if(group[x] == x) return x;
    group[x] = getClass(group, group[x]);
    return group[x];
}

int Solution::solve(int A, vector<vector<int> > &B) {
    // author ninja
    // O(nlog(n)*(log*(n)))
    int res = 0;
    int grp;
    int group[A+1];
    int c1, c2;
    
    for(int i=1;i<=A;i++)
        group[i] = i;
    group[0] = -1;
    
    sort(B.begin(), B.end(), compare);
    
    for(int i=0;i<B.size();i++) {
        c1 = getClass(group, B[i][0]);
        c2 = getClass(group, B[i][1]);
        
        if(c1 == c2) continue;
        grp = min(c1, c2);
        group[c1] = grp;
        group[c2] = grp;
        res += B[i][2];
    }
    return res;
}