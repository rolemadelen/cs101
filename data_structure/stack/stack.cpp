#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node *next;

        Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Stack {
    private:
        Node<T> *top;
        
    public:
        Stack() : top(nullptr) {}
        ~Stack() {
            while(top) {
                Node<T> *temp = top;
                top = top->next;
                delete temp;
            }
        }

        void push(T data) {
            Node<T> *newNode = new Node<T>(data);
            newNode->next = top;
            top = newNode;
        }

        const T& peek() const {
            if (!top) throw std::runtime_error("peek() -> Stack is empty");
            return top->data;
        }

        const T pop() {
            if (!top) throw std::runtime_error("pop() -> Stack is empty");

            Node<T> *delNode = top;
            top = top->next;

            T temp = delNode->data;
            delete delNode;
            return temp;
        }

        const bool isEmpty() const {
            return top != nullptr;
        }
};

int main() {
    Stack<int> stack;
    // stack.peek();

    stack.push(1);
    cout << stack.peek() << endl;
    stack.push(2);
    cout << stack.peek() << endl;
    stack.push(3);
    cout << stack.peek() << endl << endl;;

    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.isEmpty() << endl;

    // cout << stack.pop() << endl;

    return 0;
}