/*************************************************************************
	> File Name: WorkingQueue.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 19时00分50秒
 ************************************************************************/

#ifndef WORKING_QUEUE_H_
#define WORKING_QUEUE_H_

#include "NonCopyable.h"
#include "MutexLock.h"
#include "Condition.h"
#include <queue>

class WorkingQueue : public NonCopyable {
public:
	typedef std::queue<int>::size_type __queue_size;
	WorkingQueue(__queue_size queue_size);
	~WorkingQueue();

	int consume();
	void product(int);
private:
	std::queue<int> _queue;
	MutexLock _lock;
	Condition _full;
	Condition _empty;
	__queue_size _queue_size;
};

#endif
