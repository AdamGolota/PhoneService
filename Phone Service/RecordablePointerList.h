#pragma once
#include "Recordable.h"


struct node {
	Recordable *p;
	node *next;
};

class RecordablePointerList
{
public:
	int push(Recordable*);
	Recordable* pop();

	RecordablePointerList();
	~RecordablePointerList();
private:
	node * start;
};

