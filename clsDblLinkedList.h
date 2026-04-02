#pragma once
#include<iostream>
using namespace std;

template<class T>

class clsDblLinkedList
{
private:
    int _Size = 0;

public:

    class Node
    {
    public:
        T Value;
        Node* Next;
        Node* Prev;
    };

    Node* head = NULL;


     void InsertAtBeginning( T Value)
    {
        /*1 - Create a new node with the desired value.
        2-Set the next pointer of the new node to the current head of the list.
        3-Set the previous pointer of the current head to the new node.
        4-Set the new node as the new head of the list.*/

        Node* newNode = new Node();

        newNode->Value= Value;
        newNode->Next = head;
        newNode->Prev = NULL;

        if (head != NULL)
        {
            head->Prev = newNode;
        }

        head = newNode;
        _Size++;
    }

     Node* Find( T Value)
    {
         Node* Current = head;

        while (Current != NULL)
        {
            if (Current->Value == Value)
                return Current;

            Current = Current->Next;
        }
        return NULL;
    }

     void InsertAtEnd( T Value)
    {
         _Size++;

        Node* new_node = new Node();

        new_node->Value = Value;
        new_node->Next = NULL;


        if (head == NULL)
        {
            new_node->Prev = NULL;
            head = new_node;
            return;
        }
        else
        {
            Node* Current = head;

            while (Current->Next != NULL)
            {
                Current = Current->Next;
            }
            new_node->Prev = Current;
            Current->Next = new_node;
        }

    }

    void InsertAfter(Node* Current,T Value)
    {

        if (head == NULL)
        {
            cout << "the given previous node cannot be NULL";
            return;
        }

        Node* new_node = new Node();
        new_node->Value = Value;
        new_node->Next = Current->Next;
        new_node->Prev = Current;

        if (Current->Next != NULL)
        {
            Current->Next->Prev = new_node;
        }

        Current->Next = new_node;
        _Size++;
    }

    void DeleteLastNode()
    {
        if (head == NULL)
        {
            return;
        }

        if (head->Next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* Current = head;

        //we need to find the node before last node
        while (Current->Next->Next != NULL)
        {
            Current = Current->Next;
        }

        Node* temp = Current->Next;
        Current->Next = NULL;
        delete temp;
        _Size--;
    }

    void DeleteNode( Node*& NodeToDelete)
    {
        if (head == NULL || NodeToDelete == NULL)
        {
            return;
        }

        if (head == NodeToDelete)
        {
            head = NodeToDelete->Next;
        }

        if (NodeToDelete->Prev != NULL)
        {
            NodeToDelete->Prev->Next = NodeToDelete->Next;
        }

        if (NodeToDelete->Next != NULL)
        {
            NodeToDelete->Next->Prev = NodeToDelete->Prev;
        }
        delete NodeToDelete;
        _Size--;
    }

    void DeleteFirstNode()
    {
        if (head == NULL)
        {
            return;
        }

        Node* temp = head;
        head = head->Next;

        if (head != NULL)
        {
            head->Prev = NULL;
        }
        delete temp;
        _Size--;
    }

    void PrintNodeDetails(Node* head)
    {
        if (head->Prev != NULL)
            cout << head->Prev->Value;
        else
            cout << "NULL";

        cout << " <--> " << head->Value << " <--> ";

        if (head->Next != NULL)
            cout << head->Next->Value << "\n";
        else
            cout << "NULL";
        
    }

    void PrintListDetails()
    {
        Node* temp = head;

        cout << "\n\n";
        while (temp != NULL)
        {
            PrintNodeDetails(temp);
            temp = temp->Next;
        }

    }

    void PrintList()
    {
        Node* temp = head;

        cout << "\nNULL <--> ";
        //print the linked list value
        while (temp != NULL)
        {
            cout << temp->Value << " <--> ";
            temp = temp->Next;
        }
        cout << "NULL";
    }

    void PrintList1()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->Value << " ";
            temp = temp->Next;
        }
   
    }

    int Size()
    {
      /*  Node* N = head;

        if (N == NULL)
            return 0;

        int Counter = 0;

        while (N != NULL)
        {
            Counter++;
            N = N->Next;
        }

        return Counter;*///big o (n)


        return _Size;//big o(1)

    }

    bool IsEmpty()
    {
       /* Node* N = head;

        if (head == NULL)
            return true;

        if (N->Next != NULL)
            return false;

        if (N->Prev != NULL)
            return false;

        return true;*/

        return (_Size == 0) ? true : false;

    }

    void Clear()
    {
        while (_Size > 0)
            DeleteFirstNode();

    }

    void Reverse()
    {
        Node* Current = head;
        Node* temp = nullptr;

        while (Current!=nullptr)
        {
            temp = Current->Prev;
            Current->Prev = Current->Next;
            Current->Next = temp;
            Current = Current->Prev;

        }

        if (temp != nullptr)
            head = temp->Prev;

    }

    Node* GetNode(int Index)
    {
        if (Index > _Size - 1 || Index < 0)
            return NULL;

        int Counter = 0;
        Node* Current = head;
        while (Current!=NULL&&(Current->Next!=NULL))
        {
            if (Counter == Index)
                break;
            
          
            Current = Current->Next;
            Counter++;
        }

        return Current;

    }

    T GetItem(int Index)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL)
            return NULL;
        else
        return ItemNode->Value;
    } 

    bool UpdateItem(int Index, T NewValue)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
            ItemNode->Value = NewValue;
            return true;
        }
        else
            return false;

    }

    bool InsertAfter(int Index, T value)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode, value);
            return true;
        }
        else
            return false;

    }

};

