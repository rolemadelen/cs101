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
class Queue {
    private:
        Node<T> *front;
        Node<T> *back;

    public:
        Queue<T>() : front(nullptr), back(nullptr) {}
        ~Queue() = default;

        void enqueue(T data) {
            Node<T> *newNode = new Node<T>(data);
            
            if(front == nullptr) {
                front = newNode;
                back = newNode;
            } else {
                back->next = newNode;
                back = newNode;
            }
        }

        T dequeue() {
            if (!front) throw std::runtime_error("dequeue() -> Queue is empty");
            T data;

            Node<T> *temp = front;
            front = front->next;
            data = temp->data;
            delete temp;

            return data;
        }

        T getFront() {
            if (!front) throw std::runtime_error("front() -> Queue is empty");
            return front->data;
        }

        bool isEmpty() {
            return front == nullptr;
        }
};

int main() {
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.isEmpty() << endl;

    return 0;
}