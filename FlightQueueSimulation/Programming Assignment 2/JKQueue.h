#ifndef DYNINTQUEUE_H
#define DYNINTQUEUE_H
#include<iostream>
class DynIntQueue
{
private:
	class QueueNode
	{
		friend class DynIntQueue;
		int value;
		QueueNode *next;
		
		QueueNode(int value1, QueueNode *next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	QueueNode *front;
	QueueNode *rear;
	int size;
public:
	DynIntQueue();
	~DynIntQueue();

	void UCenqueue(int);
	void UCdequeue(int &);
	bool UCisEmpty();
	void UCclear();
	int UCPeek();
};
#endif