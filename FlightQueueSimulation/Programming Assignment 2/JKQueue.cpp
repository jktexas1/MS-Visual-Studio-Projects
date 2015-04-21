// Programming Assignment 2
// Queue Simulation for XYZ Airlines
// Jacob Kapusta
// 2/25/2013

#include<iostream>
#include "Queue.h"
using namespace std;

DynIntQueue::DynIntQueue()
{
	front = NULL;
	rear = NULL;
	size = 0;
}
DynIntQueue::~DynIntQueue()
{
	UCclear();
}
void DynIntQueue::UCenqueue(int num)
{
	if(UCisEmpty())
	{
		front = new QueueNode(num);
		rear = front;
		size++;
	}
	else
	{
		rear->next = new QueueNode(num);
		rear = rear->next;
		size++;
	}
}
void DynIntQueue::UCdequeue(int &num)
{
	QueueNode *temp;
	if(UCisEmpty())
	{
		cout << "The queue is empty. \n";
		exit(1);
	}
	else
	{
		num = front->value;
		temp = front;
		front = front->next;
		size--;
		delete temp;
	}
}
int DynIntQueue::UCgetSize()
{
	return size;
}
bool DynIntQueue::UCisEmpty()
{
	if(front == NULL)
		return true;
	else
		return false;
}
void DynIntQueue::UCclear()
{
	int value;
	while(!UCisEmpty())
	{
		UCdequeue(value);
	}
}
int DynIntQueue::UCPeek()
{
	return front->value;
}
