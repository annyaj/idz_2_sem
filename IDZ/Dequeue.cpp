#include "Dequeue.h"



void Dequeue::push_back(const char value)
{
	elem* t = new elem(value, const_cast<elem*>(tail));
	if (root == nullptr)
	{
		root = t;
	}
	else
	{
		elem* g = root;
		while (g->next != tail)g = g->next;
		g->next = t;
	}
}

void Dequeue::push_front(const char value)
{
	elem* t = new elem(value, nullptr);
	if (root == nullptr)
	{
		root = t;
	}
	else
		t->next = root;
	root = t;
}

bool Dequeue::pop_back(char& value)
{
	if (root == nullptr) return false;
	if (root->next == tail) {
		value = root->value;
		delete root;
		root = nullptr;
	}
	elem* t = root;
	while (t->next->next != tail)
	{
		t = t->next;
	}
	value = t->next->value;
	delete t->next;
	t->next = const_cast<elem*>(tail);
	return true;
}

bool Dequeue::pop_front(char& value)
{
	if (root == nullptr) return false;
	elem* t = root;
	value = root->value;
	root = root->next;
	t->next = nullptr;
	delete t;
	return true;
}


bool Dequeue::isEmpty()
{
	return root == tail;
}

Dequeue::iterator& Dequeue::begin()
{
	iterator* h = new iterator(root);
	return*h;
}

Dequeue::iterator& Dequeue::end()
{
	iterator* e = new iterator(const_cast<elem*>(tail));
	return*e;
}

string Dequeue::toString()
{
	string s = "";
	elem* n = root;
	for (; n != tail; n = n->next)
	{
		s += to_string(n->value);
		s += " ";
	}
	return s;
}


Dequeue::~Dequeue()
{
}