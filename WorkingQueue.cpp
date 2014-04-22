/*************************************************************************
	> File Name: WorkingQueue.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 19时01分03秒
 ************************************************************************/

#include "WorkingQueue.h"
#include <iostream>

WorkingQueue::WorkingQueue(__queue_size queue_size):
	_queue(), _lock(), _full(&_lock), _empty(&_lock), _queue_size(queue_size)  {  }

WorkingQueue::~WorkingQueue() { }

int WorkingQueue::consume()
{
	_lock.lock();
	while(_queue.empty())
	{
		std::cout << "------------------" << std::endl;
		std::cout << "Buffer is empty, waiting for product...."<< std::endl;
		_full.wait();
	}
	int num = _queue.front();
	_queue.pop();
	_empty.notify();
	_lock.unlock();
	return num;
}

void WorkingQueue::product(int num)
{
	_lock.lock();
	while(_queue.size() == _queue_size)
	{
		std::cout << "------------------" << std::endl;
		std::cout << "Buffer is full, waiting for consume...." << std::endl;
		_empty.wait();
	}
	_queue.push(num);
	_full.notify();
	_lock.unlock();
}

