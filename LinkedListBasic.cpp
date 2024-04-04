#include <iostream>
using namespace std;

class Node{
    public:
        char id;
        Node *next;

        Node(){
            next = NULL;
        }
};

class Linkedlist{
    public:
        Node *head;
        Node *tail;

        Linkedlist(){
            head = tail = NULL;
        }

        //bisa dianggap newNode at Tail
        void newNodeAtTail(char data){
            Node *newNode = new Node();
            newNode->id = data;
            
            //jika headnya NULL artinya tidak ada data
            if (head == NULL){
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        //menambahkan data di head
        void newNodeAtHead(char data){
            Node *newNode = new Node();
            newNode->id = data;
            newNode->next = head;
            head = newNode;
            if (tail == NULL){
                tail = newNode;
            }
        }

        //menambahkan data di tengah
        void newNodeAtMiddle(char data, char afterId){
            if(head == NULL){
                cout << "Tidak ada Node didalam Linked List!" << endl;
            }


            Node *newNode = new Node();
            newNode->id = data;

            Node *temp = head;
            while(temp != NULL && temp->id != afterId){
                temp = temp->next;
            }

            if(temp == NULL){
                cout << "Node dengan id " << afterId << " tidak ditemukan" << endl;
                return;
            }

            newNode->next = temp->next;
            temp->next = newNode;

            if(temp == tail){
                tail = newNode;
            }
        }

        void deleteFromHead(){
            if(head == NULL){
                cout << "Tidak ada Node didalam Linked List!" << endl;
                return;
            }

            else if (head == tail){
                delete head;
                head = tail = NULL;
            }
            else {
                Node *temp = head;
                head = head->next;
                temp->next = NULL;
                delete temp;
            }
        }

        void deleteFromTail(){
            if (head == NULL){
                cout << "Tidak ada Node didalam Linked List!" << endl;
                return;
            }
            else if(head == tail){
                deleteFromHead();
                return;
            }
            else {
                Node *temp = head;
                while(temp != NULL && temp->next != tail){
                    temp = temp->next;
                }
                delete tail;
                tail = temp;
                temp->next = NULL;
            }
        }

        void deleteAfterId(char AfterId){
            if(head == NULL){
                cout << "Tidak ada Node didalam Linked List!" << endl;
                return;
            }
            
            if (head == tail){
                deleteFromHead();
                return;
            }

            else{
                Node *tmp = head;
                while(tmp != NULL && tmp->id != AfterId){
                    tmp = tmp->next;
                }

                if (tmp == NULL || tmp->next == NULL){
                    cout << "Node dengan after id '" << AfterId << "' Tidak Ditemukan!" << endl;
                    return;
                }
                
                Node *tmp2 = tmp;
                tmp = tmp->next;
                if(tmp->next == tail){
                    delete tail;
                    tail = tmp2;
                }
                else{
                    tmp2->next = tmp->next;
                    tmp->next = NULL;
                    delete tmp;
                }
            }
        }

        void printList(){
            Node *temp = head;
            while(temp != NULL){
                cout << temp->id << ", ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    Linkedlist mylist;

    mylist.newNodeAtTail('A');
    mylist.newNodeAtTail('B');
    mylist.newNodeAtTail('C');
    mylist.newNodeAtTail('D');
    mylist.newNodeAtHead('Z');
    mylist.newNodeAtHead('Y');
    mylist.newNodeAtMiddle('M', 'D');
    mylist.printList();

    mylist.deleteAfterId('B');
    mylist.printList();
    mylist.deleteFromTail();
    mylist.deleteFromHead();

    mylist.printList();

    mylist.deleteAfterId('D');

    mylist.printList();

    mylist.newNodeAtMiddle('H', 'A');

    mylist.printList();

    mylist.deleteAfterId('B');

    mylist.printList();

    mylist.deleteAfterId('H');

    mylist.printList();

    return 0;
}


/*
        void newNode(char data){
            Node *newNode = new Node();
            newNode->id = data;
            if (head == NULL){
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
*/