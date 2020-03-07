#include <iostream>
#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"

using namespace assignment3;
using namespace std;
int main()
{
	QueueStack<int> qs(3);
	qs.Enqueue(1); // [ [ 1 ] ]
	qs.Enqueue(2); // [ [ 1, 2 ] ]
	qs.Enqueue(3); // [ [ 1, 2, 3 ] ]
	qs.Enqueue(4); // [ [ 1, 2, 3 ], [ 4 ] ]
	qs.Enqueue(5); // [ [ 1, 2, 3 ], [ 4, 5 ] ]

	int dequeued = qs.Dequeue(); // dequeued�� ���� 3. qs�� ���: [ [ 1, 2 ], [ 4, 5 ] ]
	dequeued = qs.Dequeue(); // 2
	dequeued = qs.Dequeue(); // 1
	dequeued = qs.Dequeue(); // 5
	dequeued = qs.Dequeue(); // 4
	cout << dequeued << endl;
	return 0;
}