#include <iostream>
#include <string>
using namespace std;
//клас вузол - значення та посилання на наступний вузол
template <typename Type>
class Node
{
public:
	Type value = NULL;
	Node<Type>* next = NULL;
public:
	Node() :value(NULL), next(NULL) {}
	Node(Type val)
	{
		this->value = val;
		this->next = NULL;
	}
	Node(Node<Type>& n)
	{
		this->value = n.value;
		this->next = n.next;
	}
	Type GetValue()
	{
		return this->value;
	}
	Node<Type>* GetNext()
	{
		return this->next;
	}
	void SetNext(Node<Type>* nxt)
	{
		this->next = NULL;
	}
	friend ostream& operator<<(ostream& os, Node<Type>& n)
	{
		return os << n.GetValue() << " ";
	}
};

//клас однозв'язний список - посилання на "голову" списку
template <typename Type>
class listing : public Node<Type>
{
protected:
	Node<Type>* head = NULL;
public:
	listing() :head(NULL) {}

	listing(Node<Type>* k)
	{
		this->head = k;
	}

	Node<Type>* GetHead()
	{
		return this->head;
	}

	void addToBegin(Type v)
	{
		Node* n = new Node;
		n->value = v;
		n->next = head;
		head = n;
	}

	void addToEnd(Type v)
	{
		Node<Type>* n;
		if (!head)
		{
			head = new Node;
			head->value = v;
			head->next = NULL;
			return;
		}
		else
		{
			n = head;
			while (n->next)
				n = n->next;
			Node* newNode = new Node;
			newNode->value = v;
			newNode->next = NULL;
			n->next = newNode;
			return;
		}
	}

	listing<Type> reverse()
	{
		Node<Type>* n = this->head;
		listing<Type> l1 = new listing<Type>();
		l1.addToBegin(n->GetValue());
		int i = 1;
		while (n->GetNext())
		{
			n = n->GetNext();
			l1.addToBegin(n->GetValue());
			++i;
		}
		Node<Type>* n1 = l1.GetHead();
		for (int j = 0; j < i - 1; j++)
		{
			n1 = n1->GetNext();
		}
		n1->next = NULL;
		return l1;
	}

	listing<Type>& operator=(listing<Type> lis)
	{
		head = lis.head;
		return *this;
	}

	friend ostream& operator<<(ostream& os, listing<Type>& l)
	{
		Node<Type>* n = l.GetHead();
		if (n->GetValue() == NULL) os << "Listing is empty";
		else
		{
			while (n->GetNext() != NULL) {
				os << n->GetValue() << " ";
				n = n->GetNext();
			}
			os << n->GetValue() << " ";
		}
		os << '\n';
		return os;
	}
};
int main()
{
	Node<int> n(2);
	listing<int> l(&n);
	l.addToBegin(1);
	l.addToEnd(3);
	l.addToEnd(4);
	cout << l;
	listing<int> l1 = new listing<int>();
	l1 = l.reverse();
	cout << l1;

	Node<char*> s("loves");
	listing<char*> ls(&s);
	ls.addToBegin("Teddy");
	ls.addToEnd("Phoenix");
	cout << ls;
	cout << ls.reverse();
	system("pause");
	return 0;
}
