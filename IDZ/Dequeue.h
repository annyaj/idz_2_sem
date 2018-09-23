#pragma once
#include <string>

using namespace std;
class Dequeue
{
	struct elem
	{
		char value;
		elem* next = nullptr;
		elem() {}
		elem(char value, elem* next) {
			this->value = value;
			this->next = next;
		}
	};
	elem* root = nullptr;
	const elem* tail = new elem(4,nullptr);
public:
	class iterator
	{
		elem* cur = nullptr;

	public:
		iterator() {}
		iterator(elem* cur)
		{
			this->cur = cur;
		}
		bool operator==(iterator& it) {
			return cur == it.cur;
		}
		bool operator!= (iterator& it)
		{
			return cur != it.cur;
		}
		iterator& operator++()
		{
			cur = cur->next;
			return *this;
		}
		iterator(iterator& it)
		{
			cur = it.cur;
		}
		iterator& operator=(iterator& it)
		{
			cur = it.cur;
			return *this;
		}
		char operator*()
		{
			return 	cur->value;
		}

	};
	Dequeue() {
	
	}
	Dequeue(const Dequeue& old)
	{
		if (old.isEmpty())
		{
			root = nullptr;
			return;
		}

		root = new elem(old.root->value, nullptr);
		elem* prev = root;
		elem* current=nullptr;
		for (elem* el = old.root->next; el != old.tail; el = el->next)
		{
			 current= new elem(el->value,nullptr);
			prev->next = current;
			prev = current;
		}
		if(current!=nullptr)current->next = const_cast<elem*>(tail);
		
	}
	void push_back(const char value);
	void push_front(const char value);
	bool pop_back(char& value);
	bool pop_front(char& value);
	bool isEmpty()const;
	iterator& begin();
	iterator& end();
	string toString();
	void doEmpty();
	~Dequeue();
};
