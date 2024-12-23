#include <iostream>
using namespace std;
//bieu thuc: a*5-b*c^6/d+(h-f)*e^(1/2) 
//cai dat thuoc tinh cho mot nut tren cay 

struct BieuThuc {
    char value[10];   // mang ky tu luu gia tri cua nut 
    BieuThuc* left;
    BieuThuc* right;

    BieuThuc(const char* val) {
        int i = 0;
        while (val[i] != '\0') { 
            value[i] = val[i];
            i++;
        }
        value[i] = '\0';
        left = NULL;
        right = NULL;
    }
};

//tao nut 
BieuThuc* createNode(const char* value) {
    return new BieuThuc(value);
}

// cai dat ham khoi tao cay(khong dc bo qua ham ktra rong) 
BieuThuc* createTree() {
    // tao nut goc 
    BieuThuc* root = createNode("+");
    root->left = createNode("-");
    root->left->left = createNode("*");
    root->left->left->left = createNode("a");
    root->left->left->right = createNode("5");
    root->left->right = createNode("/");
    root->left->right->left = createNode("*");
    root->left->right->left->left = createNode("b");
    root->left->right->left->right = createNode("^");
    root->left->right->left->right->left = createNode("c");
    root->left->right->left->right->right = createNode("6");
    root->left->right->right = createNode("d");
    
    root->right = createNode("*");
    root->right->left = createNode("-");
    root->right->left->left = createNode("h");
    root->right->left->right = createNode("f");
    root->right->right = createNode("^");
    root->right->right->left = createNode("e");
    root->right->right->right = createNode("1/2");

    return root;
}
// ktra rong 
int isEmpty(BieuThuc* T) {
    return T == NULL;
}

// ham duyet cay theo cach bd trung to 
void inorder(BieuThuc* T) {
    if (T) {
        inorder(T->left);
        cout << T->value << " ";
        inorder(T->right);
    }
}

// ham duyet cay theo cach bd tien to 
void preorder(BieuThuc* T) {
    if (T) {
        cout << T->value << " ";
        preorder(T->left);
        preorder(T->right);
    }
}

// ham duyet cay theo cach bd hau to 
void postorder(BieuThuc* T) {
    if (T) {
        postorder(T->left);
        postorder(T->right);
        cout << T->value << " ";
    }
}

int main() {
    // tao cay 
    BieuThuc* tree = createTree();

    // ktra cay rong 
    if (isEmpty(tree)) {
        cout << "Cay rong" << endl;
    } else {
        cout << "Cay khong rong" << endl;

        cout << "Trung to: ";
        inorder(tree);
        cout << endl;

        cout << "Tien to: ";
        preorder(tree);
        cout << endl;

        cout << "Hau to: ";
        postorder(tree);
        cout << endl;
    }

    return 0;
}

