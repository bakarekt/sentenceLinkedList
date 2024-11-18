#include <iostream>
#include <string>
using namespace std;

struct Tu{
    string chu;
    Tu* next;
};

struct Cau{
    Tu* firstNode;
};

void listInit(Cau* cau){
    cau->firstNode = 0;
}

void mostFrequent(Cau* cau){
    if (!cau->firstNode) return;

    Tu* tu1 = cau->firstNode;
    Tu* mostFrequent;
    int maxCount = 0;
    while(tu1){
        Tu* tu2 = cau->firstNode;
        int count = 0;
        while(tu2){
            if(tu1->chu == tu2->chu){
                count++;
            }
            tu2 = tu2->next;
        }
        if(count > maxCount){
            maxCount = count;
            mostFrequent = tu1;
        }
        tu1 = tu1->next;

    }
    cout << "Tu xuat hien nhieu nhat la: " << mostFrequent->chu << endl;
}

void removeDup(Cau* cau) {
    if (!cau->firstNode) return;

    Tu* tu1 = cau->firstNode;
    while (tu1) {
        Tu* tu2 = tu1;
        while (tu2->next) {
            if (tu1->chu == tu2->next->chu) {
                Tu* duplicate = tu2->next;
                tu2->next = tu2->next->next;
                delete duplicate;
            } else {
                tu2 = tu2->next;
            }
        }
        tu1 = tu1->next;
    }
}

void soTu(Cau* cau){
    if (!cau->firstNode) return;

    Tu* tu1 = cau->firstNode;
    int count = 0;
    while(tu1){
        count++;
        tu1 = tu1->next;
    }
    cout << "So tu trong cau la: " << count << endl;
}