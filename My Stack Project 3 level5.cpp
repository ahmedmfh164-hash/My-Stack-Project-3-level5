
#include <iostream>
#include"clsMyStack.h"


int main()
{
	clsMyStack<int>MyStack;

    MyStack.push(10);
    MyStack.push(20);
    MyStack.push(30);
    MyStack.push(40);
    MyStack.push(50);
    MyStack.push(60);

    cout << "\nStack is : \n";
    MyStack.Print();

    cout << "\n\nStack Size : " << MyStack.Size() << endl;
    cout << "Stack Top : " << MyStack.Top() << endl;
    cout << "Stack Back : " << MyStack.Bottom() << endl;

    MyStack.pop();
    cout << "\n\nStack after pop : \n";
        MyStack.Print();

        //Extension 1
        cout << "\n\nItem(2) : " << MyStack.GetItem(2);

         //Extension 2
        MyStack.Reverse();
        cout << "\n\nStack after reverse() : \n";
        MyStack.Print();

         //Extension 3
        MyStack.UpdateItem(2, 600);
        cout << "\n\nStack after updating Item(2) to 600 : \n";
        MyStack.Print();

        //Extension 4
        MyStack.InsertAfter(2, 800);
        cout << "\n\nStack after Inserting 800 after Item(2) : \n";
        MyStack.Print();

        //Extension 5
        MyStack.InsertAtFront(1000);
        cout << "\n\nStack after Inserting 1000 at front : \n";
        MyStack.Print();

        //Extension 6
        MyStack.InsertAtBack(2000);
        cout << "\n\nStack after Inserting 2000 at back : \n";
        MyStack.Print();

        //Extension 7
        MyStack.Clear();
        cout << "\n\nStack after Clear() : \n";
        MyStack.Print();

        if (MyStack.IsEmpty())
            cout << "\nStack Is Empty! \n\n";
        else
            cout << "\nStack Is Not Empty! \n\n";




        system("pause>0");
        return 0;

    }






