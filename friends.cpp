#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Insertion at the end of the list
    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Deletion by value
    void remove(int value)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != value)
        {
            temp = temp->next;
        }
        if (temp->next != nullptr)
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Search
    bool search(int value)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Print the linked list
    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory
    ~LinkedList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    int x = 0;
    LinkedList list[n];
    LinkedList list2[n];
    for (int i = 0; i < n; i++)
    {
        list[i].insert(i + 1);
    }
    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "+")
        {
            int a, b;
            cin >> a >> b;
            for (int i = 0; i < n; i++)
            {
                if (list[i].search(a))
                    list[i].remove(a);
                if (list2[i].search(a))
                    list[i].remove(a);
            }
            for (int i = 0; i < n; i++)
            {
                if (list[i].search(b))
                    list[i].insert(a);
                if (list2[i].search(b))
                    list2[i].insert(a);
            }
        }
        if (op == "-")
        {
            int a;
            cin >> a;
            for (int i = 0; i < n; i++)
            {
                if (list[i].search(a))
                {
                    list[i].remove(a);
                    list2[x].insert(a);
                    x++;
                }
            }
        }
        if (op == "?")
        {   int flag=0;
            int a, b;
            cin >> a >> b;
            for (int i = 0; i < n; i++)
            {
                if (list[i].search(a) && list[i].search(b))
                    flag=1;

                if (list2[i].search(a) && list2[i].search(b))
                   flag=1;
                
            }
            if(flag==1)cout << "YES" << endl;
            if(flag==0)cout << "NO" << endl;
        }
        for (int i = 0; i < n; i++)
    {
        list[i].print();
       
    }for (int i = 0; i < n; i++)
    {
        list2[i].print();
       
    }
       
    }
    /* list.insert(5);
     list.insert(10);
     list.insert(15);
     list.print();

     list.remove(10);
     list.print();

     cout << "Search for 5: " << (list.search(5) ? "Found" : "Not Found") << std::endl;
     cout << "Search for 10: " << (list.search(10) ? "Found" : "Not Found") << std::endl;
 */
    return 0;
}
