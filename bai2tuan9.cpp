#include <iostream>
using namespace std;

//1 Khai bao cau truc danh sach lien ket 
struct WordNode{
    string tu;
    WordNode *next;
};
struct WordList{
    WordNode *head,*tail;
};

void listinit(WordList *l){
    l->head = NULL;
    l->tail = NULL;
}

//2 Xac dinh tu xuat hien nhieu nhat trong cau
string findword(WordList *l){
    WordNode *p = l->head;
    WordNode *most = l->head;
    int maxcount = 0;

    while(p){
        int count = 1;
        WordNode *q = p->next;
        while(q){
            if(p->tu == q->tu){
                count++;
            }
            q = q->next;
        }
        if(count > maxcount){
            maxcount = count;
            most = p;
        }

        p = p->next;
    }
    return most ? most->tu : " ";
}

//3 Neu xuat hien tu lay thuc hien loai bo mot tu
void loaibolay(WordList *l){
    WordNode *p = l->head;
    WordNode *q = NULL;

    // Duyet qua danh sach
    while(p && p->next){
        q = p;
        while(q->next){
            if(p->tu == q->next->tu){
                // Loai bo tu trùng
                WordNode *del = q->next;
                q->next = q->next->next;
                delete del;
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }
}

//4 Dem so tu vung xuat hien trong cau
int countWord(WordList *l){
    int count = 0;
    WordNode *p = l->head;
    while(p){
        count++;
        p = p->next;
    }
    return count;
}

int main() {
    WordList list;
    listinit(&list);

    // them tu vao danh sach 
    WordNode* word1 = new WordNode{"hello", NULL};
    WordNode* word2 = new WordNode{"world", NULL};
    WordNode* word3 = new WordNode{"hello", NULL};

    // xay dung danh sach 
    list.head = word1;
    word1->next = word2;
    word2->next = word3;
    list.tail = word3;

    cout << "Danh sach tu: ";
    WordNode *p = list.head;
    while(p) {
        cout << p->tu << " ";
        p = p->next;
    }
    cout << endl;

    string tu = findword(&list);
    cout << "Tu xuat hien nhieu nhat: " << tu << endl;

    loaibolay(&list);

    // In danh sách sau khi lo?i b? t? trùng l?p
    cout << "Danh sach tu sau khi bo tu: ";
    p = list.head;
    while(p) {
        cout << p->tu << " ";
        p = p->next;
    }
    cout << endl;

    int wordCount = countWord(&list);
    cout << "So tu trong danh sach: " << wordCount << endl;

    return 0;
}

