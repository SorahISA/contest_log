template <typename T>
struct IntervalContainer {
    
    map<pii, T> itv;
    
    void cut(int p) { /// cut [p-1, p]
        auto it = itv.lower_bound({p, p});
        if (it == begin(itv)) return;
        if (it != end(itv) and it->first.first == p) return;
        it = prev(it);
        if (it->first.second < p) return;
        auto [lr, v] = *it; auto [l, r] = lr;
        it = itv.erase(it);
        it = itv.emplace_hint(it, pii(l, p-1), v);
        it = itv.emplace_hint(it, pii(p, r), v);
    }
    
    void modify(int l, int r, T v) {
        cut(l), cut(r+1);
        auto it_L = itv.lower_bound({l, l});
        auto it_R = itv.lower_bound({r+1, r+1});
        auto it = itv.erase(it_L, it_R);
        itv.emplace_hint(it, pii(l, r), v);
    }
    
    vector<pair<pii, T>> get(int l, int r) {
        cut(l), cut(r+1);
        auto it_L = itv.lower_bound({l, l});
        auto it_R = itv.lower_bound({r+1, r+1});
        vector<pair<pii, T>> ret;
        while (it_L != it_R) ret.eb(*it_L), it_L = next(it_L);
        return ret;
    }
    
    vector<pair<pii, T>> remove(int l, int r) {
        cut(l), cut(r+1);
        auto it_L = itv.lower_bound({l, l});
        auto it_R = itv.lower_bound({r+1, r+1});
        vector<pair<pii, T>> ret;
        while (it_L != it_R) ret.eb(*it_L), it_L = itv.erase(it_L);
        return ret;
    }
    
};
