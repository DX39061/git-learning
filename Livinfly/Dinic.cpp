#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e4+10, M = 2e5+10, INF = 0x3f3f3f3f;

int idx, h[N], ne[M], ver[M], e[M];
int n, m, S, T;
int d[N], cur[N];

void add(int a, int b, int c) {
    ver[idx] = b, e[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    ver[idx] = a, e[idx] = 0, ne[idx] = h[b], h[b] = idx ++;
}
bool bfs() {
    queue<int> q;
    memset(d, -1, sizeof d);
    q.push(S);
    d[S] = 0, cur[S] = h[S];
    while(q.size()) {
        int t = q.front(); q.pop();
        for(int i = h[t]; ~i; i = ne[i]) {
            int v = ver[i];
            if(d[v] == -1 && e[i]) {
                d[v] = d[t]+1;
                cur[v] = h[v];
                if(v == T) return true;
                q.push(v);
            }
        }
    }
    return false;
}
int update(int u, int limit) {
    if(u == T) return limit;
    int flow = 0;
    for(int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        cur[u] = i;
        int v = ver[i];
        if(d[v] == d[u]+1 && e[i]) {
            int t = update(v, min(e[i], limit-flow));
            if(!t) d[v] = -1;
            /*
                若h[v] = -1，则完全关了v点，但
                1(S) -> 2, 2 -> 3, 1 -> 3, 3 -> 4(T)，因为分层图，bfs生成的分层图可能v其实还有价值。
            */
            flow += t;
            e[i] -= t;
            e[i^1] += t;
        }
    }
    return flow;
}
int dinic() {
    int res = 0, flow;
    while(bfs()) 
        while(flow = update(S, INF))
            res += flow;
    /*
        ???
        INF是总流量的最大值，往往不好设置，还是用while稳妥（（
    */
    return res;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d%d%d", &n, &m, &S, &T);
    while(m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    printf("%d\n", dinic());
    return 0;
}
