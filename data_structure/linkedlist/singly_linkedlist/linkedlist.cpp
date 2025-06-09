#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node<T> *next;
        Node<T>(T data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
    private:
        Node<T> *head;
        Node<T> *tail;
        int size;

    public:
        LinkedList() : head(nullptr), tail(nullptr), size(0) {}

        ~LinkedList() {
            while(head) {
                pop_front();
            }
            head = tail = nullptr;
            size = 0;
        }

        void push_front(T data) {
            Node<T> *newNode = new Node<T>(data);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }

            size += 1;
        }

        void push_back(T data) {
            Node<T> *newNode = new Node<T>(data);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            size += 1;
        }

        void pop_front() {
            if (head == nullptr) {
                cout << "Error: List is empty" << endl;
                return;
            }

            Node<T> *temp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete temp;
            size -= 1;
        }

        void pop_back() {
            if (head == nullptr) {
                cout << "Error: List is empty" << endl;
                return;
            }

            if (head == tail) {

                delete head;
                head = tail = nullptr;
                size -= 1;
                return;
            }

            Node<T> *temp = head;

            while(temp->next != tail) {
                temp = temp->next;
            }

            delete temp->next;
            temp->next = nullptr;
            tail = temp;
            size -= 1;
        }

        bool deleteNode(T data) {
            if (head == nullptr) {
                cout << "Error: List is empty" << endl;
                return false;
            }

            if (!search(data)) {
                cout << "Error: data not found" << endl;
                return false;
            }

            if (head->data == data) {
                pop_front();
            } else if (tail->data == data) {
                pop_back();
            } else {
                Node<T> *temp = head;
                while(temp->next->data != data) {
                    temp = temp->next;
                }

                Node<T> *deleted_node = temp->next;
                temp->next = temp->next->next;

                delete deleted_node;
                size -= 1;
            }

            return true;
        }

        void insert(T data, int pos) {
            if (pos < 0 || pos > size) {
                cout << "Error: Invalid position." << endl;
                return;
            }

            if (pos == 0) {
                push_front(data);
            } else if (pos == size ) {
                push_back(data);
            } else {
                Node<T> *temp = head;
                while (pos > 1) {
                    temp = temp->next;
                    --pos;
                }

                Node<T> *newNode = new Node<T>(data);
                newNode->next = temp->next;
                temp->next = newNode;
                size += 1;
            }
        }

        bool search(T data) {
            Node<T> *temp = head;

            while(temp) {
                if (temp->data == data) {
                    return true;
                }
                temp = temp->next;
            }

            return false;
        }

        bool isEmpty() const { return head == nullptr; }
        int getSize() const { return size; }

        const T& front() const {
            if (!head) throw std::runtime_error("List is empty.");
            return head->data;
        }

        const T& back() const {
            if (!tail) throw std::runtime_error("List is empty.");
            return tail->data;
        }

        void print() const {
            Node<T> *curr = head;
            while (curr != nullptr) {
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << " (" << size << ")\n";
        }
};

int main() {
    #if 0 // push_front
    cout << "------- push_front" << endl;

    LinkedList<int> list1;

    list1.push_front(1);
    list1.push_front(2);
    list1.push_front(3);
    list1.push_front(4);
    list1.push_front(5);

    list1.print();
    #endif

    #if 0 // push_back
    cout << "------- push_back" << endl;
    
    LinkedList<int> list2;

    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);
    list2.push_back(4);
    list2.push_back(5);

    list2.print();
    #endif

    #if 0 // pop_front
    cout << "------- pop_front" << endl;

    LinkedList<int> list3;

    list3.push_back(1);
    list3.push_back(2);
    list3.push_back(3);
    list3.push_back(4);
    list3.push_back(5);
    list3.print();

    list3.pop_front();
    list3.print();

    list3.pop_front();
    list3.print();

    list3.pop_front();
    list3.pop_front();
    list3.pop_front();
    list3.pop_front();

    list3.push_front(0);
    list3.push_front(1);
    list3.push_back(-1);
    list3.push_back(-2);
    list3.print();

    #endif

    #if 0 // pop_back
    cout << "------- pop_back" << endl;

    LinkedList<int> list4;

    list4.push_back(1);
    list4.push_back(2);
    list4.push_back(3);
    list4.push_back(4);
    list4.push_back(5);
    list4.print();

    list4.pop_back();
    list4.print();
    
    list4.pop_back();
    list4.print();

    list4.pop_back();
    list4.pop_back();
    list4.pop_back();
    list4.pop_back();

    list4.push_front(1);
    list4.push_back(2);
    list4.print();
    #endif

    #if 0 // front and back
    cout << "------- front and back" << endl;

    LinkedList<float> list5;

    list5.push_back(3.14);
    list5.push_back(1.56);

    if (!list5.isEmpty()) {
        float front = list5.front();
        float back = list5.back();
        cout << "front: " << front << "     back: " << back << endl;
    }

    list5.push_back(9.12);
    if (!list5.isEmpty()) {
        float front = list5.front();
        float back = list5.back();
        cout << "front: " << front << "     back: " << back << endl;
    }
    #endif

    #if 0 // insert
    cout << "------- insert" << endl;

    LinkedList<int> list6;
    list6.insert(1, 0);
    list6.insert(3, 1);
    list6.insert(2, 1);
    list6.insert(4, 3);
    list6.insert(6, 4);
    list6.insert(5, 4);

    list6.print();

    #endif

    #if 0 // search
    cout << "------- Search" << endl;

    LinkedList<int> list7;
    list7.push_back(1);
    list7.push_back(3);
    list7.push_back(5);
    list7.push_back(7);
    list7.push_back(9);

    list7.print();

    for(int i=0; i<10; ++i) {
        cout << i << " exists? " << list7.search(i) << endl;
    }
    #endif

    #if 1 // delete
    cout << "------- Delete" << endl;

    LinkedList<int> list8;
    list8.push_back(1);
    list8.push_back(3);
    list8.push_back(5);
    list8.push_back(7);
    list8.push_back(9);

    list8.print();

    list8.deleteNode(1);
    list8.print();

    list8.deleteNode(5);
    list8.print();

    list8.deleteNode(5);
    list8.deleteNode(7);
    list8.deleteNode(3);
    list8.print();
    list8.deleteNode(9);
    list8.print();
    #endif

    return 0;
}