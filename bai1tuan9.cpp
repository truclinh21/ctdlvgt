#include <iostream>
using namespace std;

//1 Khai bao cau truc danh sach lien ket 
struct FileNode{
    int size;                   
    string name;           
    int time;          
    FileNode *link;         
};
struct FileList{
    FileNode *head, *tail;
};
void khoitaodanhsach(FileList *list){
     list->head = NULL;
     list->tail = NULL;
}
//2 copy paste mot file tu muc khac sang thu muc tren sao cho file duoc chen theo time
FileNode* callFile(int size, string name, int time){
    FileNode *p= new FileNode;
    p->size=size;
    p->name=name;
    p->time=time;
    p->link=NULL;
    return p;
}
//chuyen file vao thu muc
void addFile(FileList *list, FileNode *T){
    FileNode *p=list->head;
    if(list->head==NULL||T->time<p->time){
        T->link=list->head;
        list->head=T;
    }else{
        while(p->link){
            if(T->time>=p->time){
                T->link=p->link;
                p->link=T;
                return; 
            }
            p=p->link;
        }
    }
    
}
//3 Tinh toan kich thuoc cac file trong thu muc
int totalSize(FileList *list){
    FileNode *p= list->head;
    int tong=0;
    while(p){
        tong+=p->size;
        p=p->link;
    }
    return tong;
}

//4 Xoa bo file co kich thuoc nho nhat
void xoaFile(FileList *list,long Max=32*1024*1024*1024){
    while(totalSize(list)>Max){
        FileNode *FileMin=list->head;
        FileNode *p=list->head;
        FileNode *prevmin=NULL;      //node truoc FileMin 
        FileNode *prevp=NULL;
        //tim file co kich thuoc nho nhat 
        while(p){
            if(p->size<FileMin->size){
                FileMin=p;
                prevmin=prevp;      
            }
            prevp=p;
            p=p->link;
        }
        if(prevmin){
            prevmin->link=FileMin->link;      
        }else{             
            list->head=list->head->link;      
        }
        delete FileMin;
        cout << "tong kich thuoc sau xoa : " << totalSize(list) << endl;
    }
}
int main() {
	FileList list; 
    khoitaodanhsach(&list);
    FileNode* file1 = callFile(5 * 1024 * 1024 * 1024, "file1.txt", 100);
    FileNode* file2 = callFile(10 * 1024 * 1024 * 1024, "file2.txt", 200);
	addFile(&list, file1);
    addFile(&list, file2);

    cout << "tung kich thuoc file " << totalSize(&list) << endl;
    xoaFile(&list, 32 * 1024 * 1024 * 1024);
    cout << "tung kich thuoc file sau khi xoa " << totalSize(&list) << endl;

    return 0;
}
