# Linked List

- 노드(Node)들이 서로 연결되어 있는 구조.
- 연결리스트의 각 원소 -> 노드(Node)
- 노드 -> 데이터와 다음 노드를 가리키는 포인터를 가진다
- 메모리상 연속된 블럭으로 나열되어 있는 배열과 다르게, 연결리스트의 노드는 서로 떨어져있다. **포인터 (pointer)** 를 사용하여 다음 노드의 위치를 파악한다.
- 포인터는 메모리 주소를 가리키는(담는) 변수.


## Node 
Templated `class` example:
```cpp
template <typename T>
class Node {
    public:
        T data;
        Node<T> *next;
        Node<T>(T data) : data(data), next(nullptr) {}
};
```

`struct` example:
```cpp
typedef struct Node {
	int data;
	struct Node *next;
} Node;
```

## Basic Operations

### Push

```cpp
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
```

### Pop

```cpp
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
		newNode->next = temp->next;
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
		while(temp->next->data != data) {
			temp = temp->next;
		}

		Node<T> *deleted_node = temp->next;
		temp->next = temp->next->next;

		delete deleted_node;
	}

	return true;
}
```

### Search

```cpp
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

## Practice Problems
- Leetcode: `easy` - [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
- Leetcode: `easy` - [83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

