struct DSU {
    
    vector<int> p, sz;
    vector<tuple<int, int, int, int>> ops;
    vector<int> disc;
    int maxn;
    
    void init(const vector<int> _disc) {
        disc = _disc, maxn = SZ(disc);
        p.resize(maxn), iota(ALL(p), 0);
        sz.assign(maxn, 1);
    }
    
    int _R(int x) { return p[x] ^ x ? _R(p[x]) : x; }
    int R(int x) {
        int id_x = lower_bound(ALL(disc), x) - begin(disc);
        return _R(id_x);
    }
    
    int _U(int x, int y) {
        x = _R(x), y = _R(y);
        if (x == y) return 0;
        if (sz[x] > sz[y]) swap(x, y);
        ops.eb(x, y, p[x], sz[y]);
        return sz[y] += sz[x], p[x] = y, 1;
    }
    int U(int x, int y) {
        int id_x = lower_bound(ALL(disc), x) - begin(disc);
        int id_y = lower_bound(ALL(disc), y) - begin(disc);
        return _U(id_x, id_y);
    }
    
    void undo() {
        auto [x, y, p_x, sz_y] = ops.back(); ops.pb();
        p[x] = p_x, sz[y] = sz_y;
    }
    
};
