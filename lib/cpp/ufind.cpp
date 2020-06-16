#include <vector>
using namespace std;

struct node {
    int parent;
    int depth;
};

class Ufind {
private:
    vector<struct node> nodes;
public:
    Ufind(int size) : nodes(size) {
        for(int i = 0; i < size; i++) {
            nodes[i].parent = i;
            nodes[i].depth = 0;
        }
    }

    int find_root(int v) {
        struct node *elem = &nodes[v];
        int base = v;
        if(base == elem->parent) {
            return base;
        } else {
            int root = find_root(elem->parent);
            elem->parent = root;
            return root;
        }
    }

    int is_connect(int v1, int v2) {
        return find_root(v1) == find_root(v2);
    }

    void unite(int v1, int v2) {
        int bv1 = find_root(v1);
        int bv2 = find_root(v2);
        struct node *uv1 = &nodes[bv1];
        struct node *uv2 = &nodes[bv2];
        if(uv1->depth >= uv2->depth) {
            if(uv1->depth == uv2->depth) uv1->depth++;
            uv2->depth = uv1->depth;
            uv2->parent = uv1->parent;
        } else {
            uv1->depth = uv2->depth;
            uv1->parent = uv2->parent;
        }
        return;
    }
};
