#include <iostream>
using namespace std;

struct Node {
    float heso;  
    int somu;   
    Node* link;  
};

struct ListDT {
    Node* fist;  
    Node* last; 
};
//khoi tao danh sach rong 
void initDT(ListDT* lDT) {
    lDT->fist = lDT->last = NULL;
}

Node* taoNode(float hs, int sm) {
    if (hs == 0) return NULL;  

    Node* p = new Node;
    p->heso = hs;
    p->somu = sm;
    p->link = NULL;
    return p;
}
// them node vao cuoi ds neu node khong null  
void addNode(ListDT* lDT, Node* p) {
    if (p == NULL) return; 

    if (lDT->fist == NULL) {  
        lDT->fist = lDT->last = p;
    } else {
        lDT->last->link = p;
        lDT->last = p;
    }
}

void taoDT(ListDT* lDT) {
    float hs;  
    int sm;    
    while (true) {
        cout << "he so: ";
        cin >> hs;
        if (hs == 0) break; 

        cout << "so mu: ";
        cin >> sm;

        Node* pDT = taoNode(hs, sm);  
        addNode(lDT, pDT);               
    }
}

void inDT(const ListDT* lDT) {
    Node* p = lDT->fist;
    if (p == NULL) {
        cout << "Da thuc rong." << endl;
        return;
    }

    cout << "Da thuc : ";
    while (p != NULL) {
        cout << p->heso << "x^" << p->somu;
        p = p->link;
        if (p != NULL) cout << " + ";
    }
    cout << endl;
}
//giai phong bo nho cho DSLK 
void freeDT(ListDT* lDT) {
    Node* p = lDT->fist;
    while (p != NULL) {
        Node* temp = p;
        p = p->link;
        delete temp;
    }
    lDT->fist = lDT->last = NULL;
}

int main() {
    ListDT dathuc;
    initDT(&dathuc);

    taoDT(&dathuc); 
    inDT(&dathuc);  

    freeDT(&dathuc);  
    return 0;
}

