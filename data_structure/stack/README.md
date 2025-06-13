# Stack

- LIFO (Last-In, First-Out)의 구조를 가진 자료구조

## Basic Operations

### Push
```cpp
void push(T data) {
    Node<T> *newNode = new Node<T>(data);
    newNode->next = top;
    top = newNode;
}
```

### Pop
```cpp
const T pop() {
    if (!top) throw std::runtime_error("pop() -> Stack is empty");

    Node<T> *delNode = top;
    top = top->next;

    T temp = delNode->data;
    delete delNode;
    return temp;
}
```

## Time Complexity

- `push(T data)` -> `O(1)`
- `pop()` -> `O(1)`

## Practice Problems
- Baekjoon: `Silver 4` - [9012. 괄호](https://www.acmicpc.net/problem/9012)
- Baekjoon: `Silver 4` - [10828. 스택](https://www.acmicpc.net/problem/10828)
- LeetCode: `easy` - [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses)