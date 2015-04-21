// Programming Assignment 2
// Queue Simulation for XYZ Airlines
// Jacob Kapusta
// 2/25/2013

/*
#include <cfixcc.h>
#include "Queue.h"
class QueueTest : public cfixcc::TestFixture
{
private:

public:
	void TestUCenqueue()
	{
		int queueTest = 1;
		DynIntQueue test;
		test.UCenqueue(queueTest);
		CFIXCC_ASSERT_EQUALS(1, test.UCPeek());
	}
	void TestUCdequeue()
	{
		int queueTest = 1;
		DynIntQueue test;
		test.UCenqueue(queueTest);
		test.UCdequeue(queueTest);
		CFIXCC_ASSERT_EQUALS(true, test.UCisEmpty());
	}
	void TestUCisEmpty()
	{
		DynIntQueue test;
		CFIXCC_ASSERT_EQUALS(true, test.UCisEmpty());
	}
	void TestUCclear()
	{
		int queueTest = 1;
		DynIntQueue test;
		test.UCenqueue(queueTest);
		test.UCclear();
		CFIXCC_ASSERT_EQUALS(true, test.UCisEmpty());
	}
	void TestUCPeek()
	{
		int queueTest = 1;
		DynIntQueue test;
		test.UCenqueue(queueTest);
		CFIXCC_ASSERT_EQUALS(1, test.UCPeek());
	}
};

CFIXCC_BEGIN_CLASS(QueueTest)
	CFIXCC_METHOD(TestUCenqueue)
	CFIXCC_METHOD(TestUCdequeue)
	CFIXCC_METHOD(TestUCisEmpty)
	CFIXCC_METHOD(TestUCclear)
	CFIXCC_METHOD(TestUCPeek)
CFIXCC_END_CLASS()
*/
