// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }

    friend ostream& operator<<(ostream& outStreamObject, TreeNode* node) {
        outStreamObject << (node ?  node->data : -1);
    }
};

TreeNode* createTree() {
    int x;
    cin >> x;
    if (x == -1) return NULL;
    TreeNode* root = new TreeNode(x);
    // cout << "Enter left child of " << x << " ";
    TreeNode* leftSubTree = createTree();
    // cout << "Enter right child of " << x << " ";
    TreeNode* rightSubTree = createTree();

    root->left = leftSubTree;
    root->right = rightSubTree;
    return root;
}

void printTreeInOrder(TreeNode* root) {
    if (root == NULL) return;
    printTreeInOrder(root->left);
    cout << root->data << " ";
    printTreeInOrder(root->right);
}

int height(TreeNode* root) {
    if (root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int curHeight = 1 + max(leftHeight, rightHeight);   // a
    return curHeight;
}

bool pathToNode(TreeNode* root, int nodeData, vector<TreeNode*>& path) {
    if (root == NULL) { return false; }

    path.push_back(root);
    if (root->data == nodeData) return true;

    bool leftPresence = pathToNode(root->left, nodeData, path);
    if (leftPresence) return true;

    bool rightPresence = pathToNode(root->right, nodeData, path);
    if (rightPresence) return true;

    path.pop_back();
    return false;
}

vector<TreeNode*> pathToNode(TreeNode* root, int nodeData) {
    vector<TreeNode*> path;
    pathToNode(root, nodeData, path);
    return path;
}

void levelPrint2(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    while (q.empty() == false) {
        TreeNode* curNode = q.front(); q.pop();
        cout << curNode->data << " ";
        if (curNode->left) q.push(curNode->left);
        if (curNode->right) q.push(curNode->right);
    }
}

void levelPrint(TreeNode* root) {
    queue<TreeNode*> q;
    TreeNode* const MARKER = NULL;
    q.push(root);
    q.push(MARKER);

    while (q.empty() == false) {
        TreeNode* curNode = q.front(); q.pop();
        if (curNode == MARKER) {
            cout << endl;
            if (q.empty() == false) q.push(MARKER);
            continue;
        }
        cout << curNode->data << " ";
        if (curNode->left) q.push(curNode->left);
        if (curNode->right) q.push(curNode->right);
    }
}

void leftView(TreeNode* root) {
    queue<TreeNode*> q;
    TreeNode* const MARKER = NULL;
    q.push(MARKER);
    q.push(root);

    while (q.empty() == false) {
        TreeNode* curNode = q.front(); q.pop();
        if (curNode == MARKER) {
            if (q.empty() == false) {
                cout << q.front()->data << " ";
                q.push(MARKER);
            }
            continue;
        }
        if (curNode->left) q.push(curNode->left);
        if (curNode->right) q.push(curNode->right);
    }
}

int searchRootIdx(int arr[], int be, int en, int key){
    while(be <= en){
        if (arr[be] == key) return be;
        ++be;
    }
    return -1;
}

TreeNode* arrToTree(int inorder[], int postorder[], int inBegin,
                    int inEnd, int& postEnd) {
    if (inBegin > inEnd) {
        return NULL;    // there are no elements in the tree
    }

    int rootElement = postorder[postEnd];
    --postEnd;
    TreeNode* root = new TreeNode(rootElement);
    int idxRootInOrder = searchRootIdx(inorder, inBegin, inEnd, rootElement);
    root->right = arrToTree(inorder, postorder, idxRootInOrder + 1, inEnd, postEnd);
    root->left = arrToTree(inorder, postorder, inBegin, idxRootInOrder - 1, postEnd);
    return root;
}

TreeNode* arrToTree(int inorder[], int postOrder[], int n){
    // WRAPPER FUNCTION
    int postEndIdx = n - 1;
    TreeNode* root =  arrToTree(inorder, postOrder, 0, n - 1, postEndIdx);
    return root;
}


void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

int main() {
    // TreeNode* root =  createTree();
    // printTreeInOrder(root); cout << endl;

    // int ans = height(root);
    // cout << ans;

    // int nodeData; cin >> nodeData;
    // vector<TreeNode*> ans = pathToNode(root, nodeData);
    // for (int i = 0; i < ans.size(); ++i) {
    //     if (ans[i]) {   // ans[i] has TreeNode* data type
    //         cout << ans[i]->data << " ";
    //     }
    //     else {
    //         cout << " <NULL> ";
    //     }
    // }

    // levelPrint(root);
    // leftView(root);

    int inorderInput[100] = {};
    int postOrderInput[100] = {};
    int n; cin >> n;
    inputArr(inorderInput, n);
    inputArr(postOrderInput, n);
    TreeNode* root = arrToTree(inorderInput, postOrderInput, n);
    levelPrint(root);
}