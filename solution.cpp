#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int left;
    int right;
};

vector<Node> tree;
vector<int> inorder_result;

void swap_at_depth(int node, int depth, int k) {
    if (node == -1) return;
    
    if (depth % k == 0) {
        // Swap left and right children
        swap(tree[node].left, tree[node].right);
    }
    
    // Recursively process children
    swap_at_depth(tree[node].left, depth + 1, k);
    swap_at_depth(tree[node].right, depth + 1, k);
}

void inorder_traversal(int node) {
    if (node == -1) return;
    
    inorder_traversal(tree[node].left);
    inorder_result.push_back(node);
    inorder_traversal(tree[node].right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // Resize tree to use 1-based indexing
    tree.resize(n + 1);
    
    // Read tree structure
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].left >> tree[i].right;
    }
    
    int t;
    cin >> t;
    
    // Process each query
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;
        
        // Perform swaps at depths that are multiples of k
        swap_at_depth(1, 1, k);
        
        // Generate inorder traversal
        inorder_result.clear();
        inorder_traversal(1);
        
        // Output result
        for (int j = 0; j < inorder_result.size(); j++) {
            if (j > 0) cout << " ";
            cout << inorder_result[j];
        }
        cout << "\n";
    }
    
    return 0;
}