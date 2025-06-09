# Doubly Linked List

- 각 노드는 `next` 및 `prev` 포인터를 가진다.
- 양방향 (앞뒤)로 순회가 가능.
- `pop_back`과 `delete`의 구현이 상대적으로 간단해진다.

## Node

templated `class` example:

```cpp
template <typename T>
class Node {
	public:
		T data;
		Node<T> prev;
		Node<T> next;

		Node<T> (T data): data(data), prev(nullptr), next(nullptr) {}
};
```


`struct` example:

```cpp
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

## Basic Operations

### Push

```cpp
void push_front(T data) {
    Node<T> *newNode = new Node<T>(data);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void push_back(T data) {
    Node<T> *newNode = new Node<T>(data);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
```

### Pop

```cpp
void pop_front() {
    if (head == nullptr) {
        cout << "Error: List is empty" << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
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

    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
}
```

### Insert

```cpp
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
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}
```

### Delete

```cpp
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
        while(temp->data != data) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size -= 1;
    }

    return true;
}
```

## Time Complexity
- `push_front(T data)` -> `O(1)`
- `push_back(T data)` -> `O(1)`
- `pop_front()` -> `O(1)`
- `pop_back()` -> `O(1)`
- `insert(T data, int pos)`  -> `O(n)`
- `delete(int pos)` -> `O(n)`
- `isEmpty()` -> `O(1)`
- `getFront()` -> `O(1)`
- `getBack()` -> `O(1)`
- `search(T data)` -> `O(n)`
- `searchReverse(T data)` -> `O(n)`
- `traverse()` -> `O(n)`
- `traverseReverse()` -> `O(n)`