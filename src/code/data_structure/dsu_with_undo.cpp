struct DSU {
    
    vector<int> p, sz;
    vector<tuple<int, int, int, int>> ops;
    int maxn;
    
    void init(int N) {
        maxn = N + 1;
        p.resize(maxn), iota(ALL(p), 0);
        sz.assign(maxn, 1);
    }
    
    int R(int x) { return p[x] ^ x ? R(p[x]) : x; }
    
    int U(int x, int y) {
        x = R(x), y = R(y);
        if (x == y) return 0;
        if (sz[x] > sz[y]) swap(x, y);
        ops.eb(x, y, p[x], sz[y]);
        return sz[y] += sz[x], p[x] = y, 1;
    }
    
    void undo() {
        auto [x, y, p_x, sz_y] = ops.back(); ops.pb();
        p[x] = p_x, sz[y] = sz_y;
    }
    
};
