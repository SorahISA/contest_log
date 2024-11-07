struct DSU {
    
    vector<int> p;
    int maxn;
    
    void init(int N) {
        maxn = N + 1;
        p.resize(maxn), iota(ALL(p), 0);
    }
    
    int R(int x) { return x ^ p[x] ? p[x] = R(p[x]) : x; }
    int U(int x, int y) { return (x = R(x)) ^ (y = R(y)) ? p[x] = y, 1 : 0; }
    
};
