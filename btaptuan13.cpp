#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 10; 

// Dinh nghia ctruc mot san pham 
struct Product {
    int price;                  
    const char* productName;   
    bool paid;                  
    Product* next;              
};

// Dinh nghia ctruc hang doi 
struct CheckoutQueue {
    Product* front;             
    Product* rear;              
    int count;                  
};

//ham khoi tao hang doi 
void setupQueue(CheckoutQueue& q) {
    q.front = q.rear = NULL;
    q.count = 0;
}

// ktra hang doi trong 
bool isQueueEmpty(CheckoutQueue& q) {
    return q.front == NULL;
}

// ktra hang doi day 
bool isQueueFull(CheckoutQueue& q) {
    return q.count >= MAX_SIZE;
}

// tao sp moi 
Product* createProduct(int price, const char* name) {
    Product* newProduct = new Product;
    newProduct->price = price;
    newProduct->productName = name;
    newProduct->paid = false;
    newProduct->next = NULL;
    return newProduct;
}

// them sp vao hang doi 
void addToQueue(CheckoutQueue& q, int price, const char* name) {
    if (isQueueFull(q)) {
        cout << "hang doi da day khong the them san pham " << endl;
        return;
    }
    Product* newProduct = createProduct(price, name);
    if (isQueueEmpty(q)) {
        q.front = q.rear = newProduct;
    } else {
        q.rear->next = newProduct;
        q.rear = newProduct;
    }
    q.count++;
}

// danh dau sp da thanh toan 
void markAsPaid(Product* product) {
    if (product) product->paid = true;
}

// xu ly thanh toan cho n sp dau 
void processPayments(CheckoutQueue& q, int n) {
    Product* temp = q.front;
    for (int i = 0; i < n && temp; i++) {
        markAsPaid(temp);
        temp = temp->next;
    }
}

// xoa sp da thanh toan khoi hang doi 
void removePaid(CheckoutQueue& q) {
    if (isQueueEmpty(q)) {
        cout << "hang doi trong khong co san pham de xoa" << endl;
        return;
    }
    Product* toRemove = q.front;
    if (toRemove->paid) {
        q.front = q.front->next;
        delete toRemove;
        q.count--;
    } else {
        cout << "san pham dau tien chua duoc thanh toan" << endl;
    }
}

// tinh tong so tien thu duoc 
int calculateTotal(CheckoutQueue& q) {
    int total = 0;
    Product* temp = q.front;
    while (temp) {
        total += temp->price;
        temp = temp->next;
    }
    return total;
}

// so sanh ten sp 
bool compareProductName(const char* name1, const char* name2) {
    return strcmp(name1, name2) == 0; 
}

// dem so luong san pham cung ten 
int countProduct(CheckoutQueue& q, const char* name) {
    int count = 0;
    Product* temp = q.front;
    while (temp) {
        if (compareProductName(temp->productName, name)) count++;
        temp = temp->next;
    }
    return count;
}

// in danh sach san pham trong hang doi 
void displayQueue(CheckoutQueue& q) {
    Product* temp = q.front;
    while (temp) {
        cout << temp->productName << " - " << temp->price << " - " << (temp->paid ? "da thanh toan" : "chua thanh toan") << endl;
        temp = temp->next;
    }
}

int main() {
    CheckoutQueue queue;
    setupQueue(queue);

    // them sp vao hang doi 
    addToQueue(queue, 5000, "nuoc");
    addToQueue(queue, 8000, "milo");
    addToQueue(queue, 2000, "rau");
    addToQueue(queue, 100000, "ao");

    cout << "danh sach san pham cho thanh toan:" << endl;
    displayQueue(queue);

    // tong so tien thu duoc 
    cout << "tong tien: " << calculateTotal(queue) << endl;

    // dem so luong sp  cung ten 
    cout << "nhap ten san pham de ktra: ";
    char name[50];
    cin.ignore();
    cin.getline(name, 50);
    cout << "so luong \"" << name << "\" da ban: " << countProduct(queue, name) << endl;

    // xu ly thanh toan va xoa khoi hang doi 
    int numPaid;
    cout << "nhap so luong khach hang da thanh toan: ";
    cin >> numPaid;
    processPayments(queue, numPaid);

    cout << "cac san pham con lai trong hang doi:" << endl;
    for (int i = 0; i < numPaid; i++) {
        removePaid(queue);
    }
    displayQueue(queue);

    return 0;
}

