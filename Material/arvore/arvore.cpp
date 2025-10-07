#include <bits/stdc++.h>
using namespace std;

//arvire binaria

// Estrutura da árvore usando ponteiros
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) { val = v; left = right = nullptr; }
};

// Inserção em BST
Node* insert(Node* root, int val) {
    if(!root) return new Node(val);
    if(val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// In-ordem (Left, Root, Right)
void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Pré-ordem (Root, Left, Right)
void preorder(Node* root) {
    if(!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Pós-ordem (Left, Right, Root)
void postorder(Node* root) {
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// BFS (Level Order)
void bfs(Node* root) {
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->val << " ";
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
}

//arvoer de segmentos

// Segment Tree para soma (pode adaptar para min/max)
const int MAXN = 1e5+5;
int seg[4*MAXN];
int a[MAXN];
int n;

// Build segment tree
void build(int node, int l, int r) {
    if(l == r) seg[node] = a[l];
    else {
        int mid = (l + r)/2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        seg[node] = seg[2*node] + seg[2*node+1]; // Soma do intervalo
    }
}

// Query [ql, qr] (soma)
int query(int node, int l, int r, int ql, int qr) {
    if(r < ql || l > qr) return 0; // fora do intervalo
    if(ql <= l && r <= qr) return seg[node]; // totalmente dentro
    int mid = (l + r)/2;
    return query(2*node, l, mid, ql, qr) + query(2*node+1, mid+1, r, ql, qr);
}

// Update índice idx para val
void update(int node, int l, int r, int idx, int val) {
    if(l == r) seg[node] = val;
    else {
        int mid = (l + r)/2;
        if(idx <= mid) update(2*node, l, mid, idx, val);
        else update(2*node+1, mid+1, r, idx, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

// exemplo

int main() {
    // ====== Árvore Binária ======
    Node* root = nullptr;
    vector<int> vals = {5,3,7,2,4,6,8};
    for(int x : vals) root = insert(root, x);

    cout << "In-order: "; inorder(root); cout << "\n";
    cout << "Pre-order: "; preorder(root); cout << "\n";
    cout << "Post-order: "; postorder(root); cout << "\n";
    cout << "BFS: "; bfs(root); cout << "\n\n";

    // ====== Segment Tree ======
    n = 5;
    a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4; a[4] = 5;
    build(1, 0, n-1);

    cout << "Query 1-3: " << query(1,0,n-1,1,3) << "\n"; // 2+3+4=9
    update(1,0,n-1,2,10); // a[2] = 10
    cout << "Query 1-3 after update: " << query(1,0,n-1,1,3) << "\n"; // 2+10+4=16

    return 0;
}
