#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <list>
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

typedef  map<int, list<TreeNode*> > mapIntList;
void fillHorizontalDistance(TreeNode* root, int hd, mapIntList& m) {
    if (root == NULL) return;

    m[hd].push_back(root);
    fillHorizontalDistance(root->left, hd - 1, m);
    fillHorizontalDistance(root->right, hd + 1, m);
}


void printVertical(TreeNode* root) {
    map<int, list<TreeNode*> >horizontalLevels;

    fillHorizontalDistance(root, 0, horizontalLevels);

    // print Map

    for (map<int, list<TreeNode*> >::iterator it = horizontalLevels.begin(); it != horizontalLevels.end(); ++it) {
        const pair<int, list<TreeNode*> >& curElementInMap = *it;
        int hd = curElementInMap.first;
        const list<TreeNode*>& curList = curElementInMap.second;

        cout << hd << ": ";
        for (list<TreeNode*>::const_iterator listIterator = curList.begin(); listIterator != curList.end(); ++listIterator) {
            cout << (*listIterator)->data << " ";
            // cout << listIterator->data << " ";
        }
        cout << endl;
    }
}


int main() {
    TreeNode* root = createTree();
    printVertical(root);
}