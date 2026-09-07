#include <bits/stdc++.h> // T.c O(M+N)
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

// Merge two BSTs
Node* merge2BST(Node* root1, Node* root2) {

    vector<int> arr1, arr2;

    // Get sorted arrays
    inorder(root1, arr1);
    inorder(root2, arr2);

    // Merge sorted arrays
    vector<int> merged;

    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j])
            merged.push_back(arr1[i++]);
        else
            merged.push_back(arr2[j++]);
    }

    while (i < arr1.size())
        merged.push_back(arr1[i++]);

    while (j < arr2.size())
        merged.push_back(arr2[j++]);

    // Build balanced BST
    return buildTree(merged, 0, merged.size() - 1);
}

int main() {

    vector<int> arr1 = {8, 2, 1, 10};
    vector<int> arr2 = {5, 3, 0};

    Node* root1 = buildBST(arr1);
    Node* root2 = buildBST(arr2);  // root2, not root1

    Node* root = merge2BST(root1, root2);

    vector<int> seq;
    inorder(root, seq);

    for (int v : seq)
        cout << v << " ";

    cout << endl;

    return 0;
}