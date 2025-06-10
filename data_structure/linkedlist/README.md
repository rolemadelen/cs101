# Linked List

- 노드(Node)들이 서로 연결되어 있는 구조.
- 연결리스트의 각 원소 -> 노드(Node)
- 메모리상 연속된 블럭으로 나열되어 있는 배열과 다르게, 연결리스트의 노드는 서로 떨어져있다. **포인터 (pointer)** 를 사용하여 다음 노드의 위치를 파악한다.
- 포인터는 메모리 주소를 가리키는(담는) 변수.

## Singly Linked List

```cpp
template <typename T>
class Node {
    public:
        T data;
        Node<T> *next;

        Node<T>(T data) : data(data), next(nullptr) {}
};
```

## Doubly Linked List

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

## Circular Linked List

- Can use either Singly or Doubly linked list.
- `tail->next = head`; 마지막 노드가 첫 번째 노드를 가리키며 만들어지는 순환 구조

## Practice Problems
- Leetcode: `easy` - [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
- Leetcode: `easy` - [83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
- Leetcode: `easy` - [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description)
- Leetcode: `easy` - [203. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/description)