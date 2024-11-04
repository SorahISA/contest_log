struct LCA {
    
    vector<vector<int>> adj;
    // vector<vector<int>> anc;
    vector<vector<int>> sp_table;
    vector<int> dep, dfn_i, dfn_o;
    int lgmx, maxn;
    
    void init(int N) {
        maxn = N + 1;
        lgmx = __lg(maxn) + 2;
        adj.resize(maxn);
        // anc.assign(lgmx, vector<int>(maxn, -1));
        sp_table.assign(lgmx, vector<int>(2*maxn, 0));
        dep.assign(maxn, 0);
        dfn_i.assign(maxn, -1);
        dfn_o.assign(maxn, -1);
    }
    
    void add_edge(int u, int v) {
        adj[u].eb(v), adj[v].eb(u);
    }
    
    void build() {
        int tok_dfn = 0;
        function<void(int, int)> dfs = [&](int now, int lst) {
            // anc[0][now] = lst;
            dfn_i[now] = dfn_o[now] = tok_dfn;
            sp_table[0][tok_dfn++] = now;
            for (int x : adj[now]) {
                if (x == lst) continue;
                dep[x] = dep[now] + 1, dfs(x, now);
                dfn_o[now] = tok_dfn;
                sp_table[0][tok_dfn++] = now;
            }
        };
        for (int i = 0; i < maxn; ++i) { if (dfn_i[i] == -1) dfs(i, i); }
        // for (int lay = 1; lay < lgmx; ++lay) {
        //     for (int i = 0; i < maxn; ++i) anc[lay][i] = anc[lay-1][anc[lay-1][i]];
        // }
        for (int lay = 1; lay < lgmx; ++lay) {
            for (int i = 0, j = 1<<(lay-1); i < 2*maxn; ++i, ++j) {
                if (j >= 2*maxn) { sp_table[lay][i] = sp_table[lay-1][i]; continue; }
                int L = sp_table[lay-1][i], R = sp_table[lay-1][j];
                sp_table[lay][i] = (dfn_i[L] < dfn_i[R] ? L : R);
            }
        }
        
        // debug(dep);
        // debug(dfn_i);
        // debug(dfn_o);
    }
    
    int lca(int u, int v) {
        tie(u, v) = pii(min(dfn_i[u], dfn_i[v]), max(dfn_o[u], dfn_o[v]));
        int lay = __lg(v - u + 1);
        int L = sp_table[lay][u], R = sp_table[lay][v-(1<<lay)+1];
        return (dfn_i[L] < dfn_i[R] ? L : R);
    }
    
    // int lca_jump(int u, int v) {
    //     if (dep[u] < dep[v]) swap(u, v);
    //     for (int lay = lgmx-1, dif = dep[u] - dep[v]; lay >= 0; --lay) {
    //         if (dif >> lay & 1) u = anc[lay][u];
    //     }
    //     if (u == v) return u;
    //     for (int lay = lgmx-1; lay >= 0; --lay) {
    //         if (anc[lay][u] != anc[lay][v]) u = anc[lay][u], v = anc[lay][v];
    //     }
    //     return anc[0][u];
    // }
    
    // int jump(int u, int k) {
    //     for (int lay = lgmx-1; lay >= 0; --lay) {
    //         if (k >> lay & 1) u = anc[lay][u];
    //     }
    //     return u;
    // }
    
    int dist(int u, int v) {
        int c = lca(u, v);
        // assert(c == lca_jump(u, v));
        return dep[u] + dep[v] - 2 * dep[c];
    }
    
};
