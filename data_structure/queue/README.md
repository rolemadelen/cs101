# Queue

- FIFO (First-In, First-Out) 구조를 가진 자료구조

## Basic Operations

### Enqueue

```cpp
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
```

### Dequeue
```cpp
T dequeue() {
    if (!front) throw std::runtime_error("dequeue() -> Queue is empty");
    T data;

    Node<T> *temp = front;
    front = front->next;
    data = temp->data;
    delete temp;

    return data;
}
```

### front (= peek)

```cpp
T getFront() {
    if (!front) throw std::runtime_error("front() -> Queue is empty");
    return front->data;
}
```

## Time Complexity
- `enqueue(T data)` - `O(1)`
- `dequeue()` - `O(1)`
- `front()` - `O(1)`
