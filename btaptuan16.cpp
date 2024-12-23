#include <iostream>
using namespace std;

// Node cua cay AVL
struct Node {
    int key; //gia tri cua node 
    Node* left; //con trai 
    Node* right; //con phai 
    int height; //chieu cao cua node 

    Node(int value) : key(value), left(NULL), right(NULL), height(1) {}
};

// lay chieu cao cua node 
int height(Node* node) {
    return node ? node->height : 0;
}

// cap nhat chieu cao node 
void update(Node* node) {
    if (node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }
}

// lay he so can bang 
int balance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Xoay phai 
Node* rotateRight(Node* y) {
    Node* x = y->left; //con trai tro thanh goc moi
    Node* T = x->right; //cay con phai cua x (neu co) tro thanh cay con trai cua y

    x->right = y;
    y->left = T;

    update(y);
    update(x);

    return x; //tra ve goc moi
}

// Xoay trai 
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    update(x);
    update(y);

    return y;
}

// can bang cay 
Node* rebalance(Node* node) {
    int bf = balance(node);

    if (bf > 1) {  // lech trai 
        if (balance(node->left) < 0) {
            node->left = rotateLeft(node->left);  // Xoay trai con trai 
        }
        return rotateRight(node);  // Xoay phai
    }

    if (bf < -1) {  // lech phai 
        if (balance(node->right) > 0) {
            node->right = rotateRight(node->right);  // Xoay phai con phai 
        }
        return rotateLeft(node);  // Xoay trai 
    }

    return node;  // da can bang 
}

// them node 
Node* add(Node* root, int key) {
    if (!root) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = add(root->left, key);
    } else if (key > root->key) {
        root->right = add(root->right, key);
    } else {
        return root;  // khong cho trung 
    }

    update(root);
    return rebalance(root);
}

// in cay theo thu tu giua (In-order)
void printInOrder(Node* root) {
    if (root) {
        printInOrder(root->left);
        cout << root->key << " ";
        printInOrder(root->right);
    }
}

// Hàm chính
int main() {
    Node* root = NULL;

    // day so cho san 
    int arr[] = {17, 23, 201, 98, 67, 83, 13, 23, 10, 191, 84, 58};
    int n = sizeof(arr) / sizeof(arr[0]);

    // them tung phan tu vao cay AVL va in trang thai
    for (int i = 0; i < n; i++) {
        root = add(root, arr[i]);
        cout << "buoc " << i + 1 << ", them " << arr[i] << ": ";
        printInOrder(root);
        cout << endl;
    }
    return 0;
}
