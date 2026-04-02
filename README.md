# My-Stack-Project-3-level5
---

# C++ Stack Implementation Using Doubly Linked List

## Overview

This project demonstrates a **Stack data structure** implemented in C++ using a **doubly linked list**. The stack supports all standard operations along with additional features such as reversing, updating, and inserting elements at specific positions.

The `clsMyStack` class is implemented by extending a generic `clsMyQueue` class, which itself uses a `clsDblLinkedList` as the underlying data structure.

---

## Features

* **Basic Stack Operations**

  * `push(T item)` – Add an item to the top of the stack.
  * `pop()` – Remove the top item of the stack.
  * `Top()` – Access the top item without removing it.
  * `Bottom()` – Access the bottom item.
  * `Size()` – Returns the number of elements in the stack.
  * `IsEmpty()` – Checks if the stack is empty.
  * `Clear()` – Removes all elements from the stack.

* **Extended Operations**

  * `GetItem(int index)` – Retrieve the item at a specific position.
  * `UpdateItem(int index, T value)` – Update the value of a specific item.
  * `InsertAfter(int index, T value)` – Insert a new item after a specific position.
  * `InsertAtFront(T value)` – Insert a new item at the top of the stack.
  * `InsertAtBack(T value)` – Insert a new item at the bottom of the stack.
  * `Reverse()` – Reverse the order of the stack.

* **Printing Functions**

  * `Print()` – Print all items in the stack.

---

## Classes

### `clsDblLinkedList<T>`

A generic **doubly linked list** that supports:

* Insertions at the beginning, end, and after a given node.
* Deletions of the first node, last node, or any specific node.
* Reversing the list.
* Updating and retrieving node values.
* Printing the list and node details.

### `clsMyQueue<T>`

A generic **queue class** built on top of `clsDblLinkedList<T>`:

* Implements standard queue operations (`push`, `pop`, `front`, `back`, `Size`, `IsEmpty`).
* Supports extended operations like reversing, updating, and inserting elements at specific positions.

### `clsMyStack<T>`

A generic **stack class** derived from `clsMyQueue<T>`:

* Implements stack-specific behavior:

  * `push()` adds elements to the top.
  * `Top()` returns the top element.
  * `Bottom()` returns the bottom element.
* Inherits all extended operations from `clsMyQueue`.

---

## Usage

1. Include the header files:

```cpp
#include "clsMyStack.h"
```

2. Create a stack object:

```cpp
clsMyStack<int> MyStack;
```

3. Use stack functions:

```cpp
MyStack.push(10);
MyStack.push(20);
MyStack.Print();      // Output: 20 10
MyStack.pop();
MyStack.Print();      // Output: 10
```

4. Extended operations:

```cpp
MyStack.InsertAtFront(5);
MyStack.InsertAtBack(30);
MyStack.Reverse();
MyStack.UpdateItem(1, 100);
MyStack.Print();
```

---

## Sample Output

```text
Stack is :
60 50 40 30 20 10

Stack Size : 6
Stack Top : 60
Stack Back : 10

Stack after pop :
50 40 30 20 10

Item(2) : 30

Stack after reverse() :
10 20 30 40 50

Stack after updating Item(2) to 600 :
10 20 600 40 50

Stack after Inserting 800 after Item(2) :
10 20 600 800 40 50

Stack after Inserting 1000 at front :
1000 10 20 600 800 40 50

Stack after Inserting 2000 at back :
1000 10 20 600 800 40 50 2000

Stack after Clear() :
Stack Is Empty!
```

---

## Requirements

* C++11 or higher.
* Compatible with Windows, Linux, and macOS.
* Any C++ compiler (GCC, MSVC, Clang, etc.).

---

## Notes

* The stack uses a **doubly linked list** internally, ensuring efficient `push()` and `pop()` operations at the top (`O(1)` complexity).
* Extended operations like `InsertAfter` and `UpdateItem` traverse the list and have `O(n)` complexity in the worst case.
* Memory management is handled manually with `new` and `delete`.

---

## Author

Ahmed Mohamed 
