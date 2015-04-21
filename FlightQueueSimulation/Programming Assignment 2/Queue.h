// Programming Assignment 2
// Queue Simulation for XYZ Airlines
// Jacob Kapusta
// 2/25/2013

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
	int UCgetSize();
	bool UCisEmpty();
	void UCclear();
	int UCPeek();
};
#endif