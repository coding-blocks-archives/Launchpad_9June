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

bool isBst(TreeNode* root, int minVal, int maxVal) {
    if (root == NULL) return true;

    bool curAns = root->data > minVal && root->data <= maxVal;
    bool leftAns = isBst(root->left, minVal, root->data);
    bool rightAns = isBst(root->right, root->data, maxVal);
    return leftAns && curAns && rightAns;

    /* return root->data > minVal && root->data <= maxVal &&
            isBst(root->left, minVal, root->data) &&
            isBst(root->right, root->data, maxVal);
     */
}


bool isBst(TreeNode* root) {
    const int inf = 1e6;
    return isBst(root, -inf, inf);
}

/*--------------BST STARTS-------------------------------*/

TreeNode* insertIntoBst(TreeNode* root, int x) {
    if (root == NULL) {
        TreeNode* newNode = new TreeNode(x);
        return newNode;
    }

    if (x < root->data) {
        TreeNode* leftUpdatedTree = insertIntoBst(root->left, x);
        root->left = leftUpdatedTree;
    }
    else {
        // x must be inserted into right
        root->right = insertIntoBst(root->right, x);
    }
    return root;
}

TreeNode* createBst() {
    int x;
    TreeNode* root = NULL;

    while (true) {
        cin >> x;
        if (x == -1) break;
        root = insertIntoBst(root, x);
    }
    return root;
}

//-------------
TreeNode* findKthSmallest(TreeNode* root, int k, int& nodesSoFar) {
    if (root == NULL) {
        return NULL;
    }

    TreeNode* ansFromLeft = findKthSmallest(root->left, k, nodesSoFar);
    if (ansFromLeft != NULL) {
        // I have found the kth node in left
        return ansFromLeft;
    }

    ++nodesSoFar;       // root's count
    if (nodesSoFar == k) return root;

    return findKthSmallest(root->right, k, nodesSoFar);
}
//------------
bool findInBst(TreeNode* root, int key) {
    if (root == NULL) {
        return false;
    }

    if (root->data == key) {
        return true;
    }

    if (key < root->data) return findInBst(root->left, key);
    return findInBst(root->right, key);
}

TreeNode* lcaBst(TreeNode* root, int x, int y) {
    if (root == NULL) {
        return root;
    }

    if (x < root->data && y < root->data) {
        TreeNode* lcaFrmLeft = lcaBst(root->left, x, y);
        return lcaFrmLeft;
    }

    if (x >= root->data && y >= root->data) {
        return lcaBst(root->right, x, y);
    }

    // Now its confirmed that either x or y lies in left or right
    bool xPresent = findInBst(root, x);
    bool yPresent = findInBst(root, y);
    if (xPresent && yPresent) return root;
    return NULL;
}
//---------
TreeNode* arrToBst(int arr[], int beginIdx, int endIdx) {
    if (beginIdx > endIdx) {
        // no elements in the array
        return NULL;
    }

    int mid = (beginIdx + endIdx) / 2;
    int curElement = arr[mid];
    TreeNode* root = new TreeNode(curElement);
    root->left = arrToBst(arr, beginIdx, mid - 1);
    root->right = arrToBst(arr, mid + 1, endIdx);
    return root;
}
//------------------DIAMETER
int height(TreeNode* root) {
    if (root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int curHeight = 1 + max(leftHeight, rightHeight);   // a
    return curHeight;
}

int max(int x, int y, int z) { return max(x, max(y, z)); }

int diameter(TreeNode* root) {
    if (root == NULL) return 0;

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    int currentDiameter = height(root->left) + height(root->right) + 1;
    return max(leftDiameter, rightDiameter, currentDiameter);

}


//------------------
void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

int main(int argc, char const *argv[]) {
    // TreeNode* root = createTree();
    // levelPrint(root);
    // bool ans = isBst(root);
    // cout << ans;

    // TreeNode* root = createBst();
    // levelPrint(root);

    // int k; cin >> k;
    // int nodesSoFar = 0;
    // TreeNode* ans = findKthSmallest(root, k, nodesSoFar);
    // cout << ans << " " << (ans ? ans->data : -1) << endl;

    // int x, y; cin >> x >> y;
    // TreeNode* ans = lcaBst(root, x, y);
    // cout << ans << " " << (ans ? ans->data : -1) << endl;

    // int arr[100];
    // int n; cin >> n;
    // inputArr(arr, n);
    // TreeNode* root = arrToBst(arr, 0, n - 1);
    // levelPrint(root);

    TreeNode* root = createTree();
    int ans = diameter(root);
    cout << ans;

    return 0;
}