#include "RecordablePointerList.h"



int RecordablePointerList::push(Recordable *p)
{
	node *n = new node;
	if (!n)
		return 0;
	n->p = p;
	n->next = this->start;
	this->start = n;
	return 1;
}

Recordable * RecordablePointerList::pop()
{
	Recordable* p;
	node* n;
	if (!this->start)
		return NULL;
	p = this->start->p;
	n = this->start;
	this->start = n->next;
	delete n;
	return p;
}

RecordablePointerList::RecordablePointerList()
{
	this->start = NULL;
}


RecordablePointerList::~RecordablePointerList()
{
	while (this->start)
		pop();
}
