#include <iostream>
using namespace std;
class Node
{
	private:
		int data;
		Node *next;
	public:
		Node(int data,Node *next=NULL)
		{
			setData(data);
			setNext(next);
		}
		void setData(int data)
		{
			this->data=data;
		}
		void setNext(Node *next)
		{
			this->next=next;
		}
		int getData()
		{
			return this->data;
		}
		Node* getNext()
		{
			return this->next;
		}
};
class LinkedList
{
    Node* head;
    Node* last;
public:
    void setHead(Node* head)
    {
        this->head = head;
    }
    void setLast(Node* last)
    {
        this->last = last;
    }
    Node* getHead()
    {
        return head;
    }
    Node* getLast()
    {
        return last;
    }
    LinkedList(Node* head = NULL, Node* last = NULL)
    {
        setHead(head);
        setLast(last);
    }
    bool isEmpty()
    {
        if (head == NULL && last == NULL)
            return true;
        else
            return false;
    }
    int getLength()
    {
        int length = 0;
        Node* temp = head;
        while (temp != NULL)
        {
            temp = temp->getNext();
            length++;
        }
        return length;
    }
    void insertAtBeginning(int val)
    {
        Node* temp = new Node(val);
        temp->setNext(head);
        head = temp;
        if (last == NULL)
            last = temp;
    }
    void insertAtLast(int val)
    {
        Node* temp = new Node(val);
        if (isEmpty())
        {
            head = temp;
            last = temp;
        }
        else
        {
            last->setNext(temp);
            last = temp;
        }
    }
    bool removeFromBeginning()
    {
        if (isEmpty())
            return false;
        else
        {
            int length = getLength();
            Node* temp = head->getNext();
            if (length != 1)
            {
                delete head;
                head = temp;
                return true;
            }
            else
            {
                delete head;
                head = temp;
                last = head;
                return true;
            }
        }
    }
    bool removeFromLast()
    {
        if (isEmpty())
        {
            return false;
		}
        int length = getLength();
        if (length == 1)
        {
            delete head;
            head = NULL;
            last = NULL;
            return true;
        }

        delete last;
        Node* temp = head;
        for (int i = 1; i < length - 1; i++)
            temp = temp->getNext();
        temp->setNext(NULL);
        last = temp;
        return true;
    }
    int getFirstElement()
    {
        if (isEmpty())
            return 0;
        else
            return head->getData();
    }
    int getLastElement()
    {
        if (isEmpty())
            return 0;
        else
            return last->getData();
    }
    void print()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->getData() << endl;
            temp = temp->getNext();
        }
	}
};

class Queue
{
    LinkedList l1;
    int size;
public:
    int getSize()
    {
        return size;
    }
    void setSize(int size)
    {
        this->size = size;
    }
    Queue(int size = 15)
    {
        setSize(size);
    }
    bool isEmpty()
    {
        return (l1.isEmpty()) ? true : false;
    }
    bool  isFull()
    {
        int length = l1.getLength();
        return (length == size) ? true : false;
    }
    bool enqueue(int val)
    {
        if (!(isFull()))
        {
            l1.insertAtBeginning(val);
            return true;
        }
        else
        {
            return false;
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            int data = l1.getLastElement();
            l1.removeFromLast();
            return data;
        }
    }
    int getPeek()
    {
        if (isEmpty())
        {
            return 0;
        }
        return l1.getLastElement();
    }
    void printQueue()
    {
        l1.print();
    }
};

int main()
{
	Queue q1(9);
	q1.setSize(50);
	q1.enqueue(5);
	q1.getSize();
	cout<<q1.getPeek();
	q1.isEmpty();
	q1.isFull();
	q1.dequeue();
	return 0;
}


