template <typename Info>
struct LCA {
    
    vector<vector<pair<int, Info>>> adj;
    vector<vector<pair<int, Info>>> anc;
    vector<int> dep, dfn_i, dfn_o;
    int lgmx, maxn;
    
    void init(int N) {
        maxn = N + 1;
        lgmx = __lg(maxn) + 2;
        adj.resize(maxn);
        anc.assign(lgmx, vector(maxn, make_pair(int(0), Info())));
        dep.assign(maxn, 0);
        dfn_i.assign(maxn, -1);
        dfn_o.assign(maxn, -1);
    }
    
    void add_edge(int u, int v, const Info &info) {
        adj[u].eb(v, info), adj[v].eb(u, info);
    }
    
    void build() {
        function<void(int, int)> dfs = [&](int now, int lst) {
            for (auto [x, info] : adj[now]) {
                if (x == lst) continue;
                dep[x] = dep[now] + 1, dfs(x, now);
                anc[0][x] = {now, info};
            }
        };
        for (int i = 0; i < maxn; ++i) { if (dfn_i[i] == -1) dfs(i, i); }
        
        for (int lay = 1; lay < lgmx; ++lay) {
            for (int i = 0; i < maxn; ++i) {
                int p = anc[lay-1][i].first;
                anc[lay][i].first = anc[lay-1][p].first;
                anc[lay][i].second = anc[lay-1][i].second + anc[lay-1][p].second;
            }
        }
        
        // debug(dep);
    }
    
    pair<int, Info> lca_jump(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        Info ans;
        for (int lay = lgmx-1, dif = dep[u] - dep[v]; lay >= 0; --lay) {
            if (dif >> lay & 1) ans += anc[lay][u].second, u = anc[lay][u].first;
        }
        if (u == v) return {u, ans};
        for (int lay = lgmx-1; lay >= 0; --lay) {
            if (anc[lay][u].first != anc[lay][v].first) {
                ans += anc[lay][u].second, u = anc[lay][u].first;
                ans += anc[lay][v].second, v = anc[lay][v].first;
            }
        }
        ans += anc[0][u].second, u = anc[0][u].first;
        ans += anc[0][v].second, v = anc[0][v].first;
        return {u, ans};
    }
    
    Info get_info(int u, int v) {
        return lca_jump(u, v).second;
    }
    
    int jump(int u, int k) {
        for (int lay = lgmx-1; lay >= 0; --lay) {
            if (k >> lay & 1) u = anc[lay][u].first;
        }
        return u;
    }
    
    int dist(int u, int v) {
        auto [c, info] = lca_jump(u, v);
        return dep[u] + dep[v] - 2 * dep[c];
    }
    
};

struct Info {
    
    int val;
    
    Info() : val(INT_MAX) {}
    Info(int _val) : val(_val) {}
    
    Info& operator += (const Info &rhs) {
        val = min(val, rhs.val);
        return *this;
    }
    
    friend Info operator + (Info lhs, const Info &rhs) {
        lhs.val = min(lhs.val, rhs.val);
        return lhs;
    }
    
};
