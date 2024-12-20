#include <iostream>
using namespace std;

// Khai bao ctruc cay de bieu dien cuon sach  
struct Node {
    char title[100];  //tieu de 
    int pages;        // so trang 
    int level;        // cap do ( chuong: 0; muc: 1; tieu muc: 2) 
    Node* child;      // con dau tien 
    Node* sibling;    // anh chi e ke tiep 

    // Constructor de khoi tao mot nut 
    Node(const char* t, int p, int l) : pages(p), level(l), child(NULL), sibling(NULL) {
        int i = 0;
        while (t[i] != '\0' && i < 99) {
            title[i] = t[i];  //sao chep tieu de 
            i++;
        }
        title[i] = '\0';  // ket thuc chuoi 
    }
};

// Ham ktra cay rong 
bool isEmpty(Node* root) {
    return root == NULL;
}
// Ham dem so chuong(level:0) 
int countCh(Node* root) {
    if (isEmpty(root)) return 0;
    int cnt = (root->level == 0) ? 1 : 0;  // Neu la chuong (level 0), tang dem 
    cnt += countCh(root->child);           // dem trong cac con 
    cnt += countCh(root->sibling);         // dem trong cac anh chi em 
    return cnt;
}
// ham tim chuong dai nhat 
Node* findLong(Node* root, Node*& res) {
    if (isEmpty(root)) return res;
    if (root->level == 0 && (!res || root->pages > res->pages)) {
        res = root;  // cap nhat chuong dai nhat 
    }
    findLong(root->child, res);   // tim trong cac con 
    findLong(root->sibling, res); // tim trong cac anh/chi em 
    return res;
}

// ham so sanh hai chuoi 
bool cmp(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {  //Duyet ca hai chuoi cho den khi gap ki tu NULL 
        if (s1[i] != s2[i]) return false;    // Neu co ki tu khac tra ve False 
        i++;
    }
    return s1[i] == '\0' && s2[i] == '\0';   // Chuoi khop neu ca hai chuoi ket thuc dong thoi 
}

// Ham tim va xoa muc 
bool removeNode(Node* root, const char* t, Node* parent =NULL) { //t: ten muc can xoa 
    if (isEmpty(root)) return false;
    if (cmp(root->title, t)) {
        if (parent && parent->child == root) {
            parent->child = root->sibling;  //cap nhat lien ket con cua parent 
        } else if (parent) {
            Node* sib = parent->child;
            while (sib && sib->sibling != root) {
                sib = sib->sibling;  // tim anh chi em dung truoc nut can xoa 
            }
            if (sib) sib->sibling = root->sibling;  // bo qua nut can xoa 
        }
        Node* cur = root->child;  //giai phong bo nho cac nut con 
        while (cur) {
            Node* next = cur->sibling;
            delete cur;
            cur = next;
        }
        delete root;  // xoa nut hien tai 
        return true;
    }
    if (removeNode(root->child, t, root)) return true;  // tim trong cac con 
    return removeNode(root->sibling, t, parent);        // tim trong cac anh/chi em 
}

//ham in cay có le 
void print(Node* root, int indent = 0) {
    if (isEmpty(root)) return;
    for (int i = 0; i < indent; ++i) cout << " ";  // in khoang trong
    cout << root->title << " (" << root->pages << " pages)" << endl;
    print(root->child, indent + 4);  // in cac nut con 
    print(root->sibling, indent);   // In anh/chi em 
}

int main() {
    Node* book = NULL;  // ban dau cay rong 

    // khoi tao cau truc sach 
    book = new Node("Book", 0, -1);
    Node* ch1 = new Node("Chapter 1", 50, 0);
    Node* ch2 = new Node("Chapter 2", 70, 0);
    Node* sec1 = new Node("Section 1.1", 20, 1);
    Node* subsec1 = new Node("Subsection 1.1.1", 10, 2);

    ch1->child = sec1;
    sec1->child = subsec1;
    book->child = ch1;
    ch1->sibling = ch2;

    cout << "Original Tree:" << endl;
    print(book);

    // xac dinh so chuong cua sach 
    cout << "\nNumber of chapters: " << countCh(book) << endl;

    // tim chuong dai nhat 
    Node* longest = NULL;
    findLong(book->child, longest);
    if (longest) {
        cout << "Longest chapter: " << longest->title << " (" << longest->pages << " pages)" << endl;
    }

    //xoa mot muc 
    const char* target = "Section 1.1";
    if (removeNode(book, target)) {
        cout << "\nAfter removing \"" << target << "\":" << endl;
        print(book);
    } else {
        cout << "\nTarget \"" << target << "\" not found!" << endl;
    }

    //don dep bo nho 
    removeNode(book, "Book");
    return 0;
}

