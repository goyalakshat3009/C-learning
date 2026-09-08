#include <bits/stdc++.h> // T.c O(N)
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Build BST
Node* buildBST(vector<int> A) {
    Node* root = NULL;

    for (int val : A)
        root = insert(root, val);

    return root;
}

// Inorder traversal
void inorder(Node* root, vector<int>& arr) {
    if (root == NULL)
        return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Build balanced BST from sorted array
Node* buildTree(vector<int>& arr, int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    Node* root = new Node(arr[mid]);

    root->left = buildTree(arr, start, mid - 1);
    root->right = buildTree(arr, mid + 1, end);

    return root;
}

// find size of largest BST in BT
// Information class for every subtree
class Info {
public:
    int size;
    int min;
    int max;
    bool isBST;

    Info(int s, int mn, int mx, bool bst) {
        size = s;
        min = mn;
        max = mx;
        isBST = bst;
    }
};

// Find size of largest BST in Binary Tree
Info solve(Node* root, int& ans) {

    // Base case: empty tree is BST
    if (root == NULL) {
        return Info(0, INT_MAX, INT_MIN, true);
    }

    Info left = solve(root->left, ans);
    Info right = solve(root->right, ans);

    int currSize = left.size + right.size + 1;

    int currMin = min(root->data, left.min);
    currMin = min(currMin, right.min);

    int currMax = max(root->data, left.max);
    currMax = max(currMax, right.max);

    // Check whether current subtree is BST
    if (left.isBST && right.isBST &&
        root->data > left.max &&
        root->data < right.min) {

        ans = max(ans, currSize);

        return Info(currSize, currMin, currMax, true);
    }

    return Info(currSize, currMin, currMax, false);
}

// Function to find largest BST size
int largestBST(Node* root) {
    int ans = 0;

    solve(root, ans);

    return ans;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

     cout << "Size of Largest BST: "
         << largestBST(root);
}