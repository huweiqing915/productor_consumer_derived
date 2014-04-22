/*************************************************************************
	> File Name: Factory.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 20时27分06秒
 ************************************************************************/

#ifndef FACTORY_H_
#define FACTORY_H_

#include "WorkingQueue.h"
#include "ProductThread.h"
#include "ConsumerThread.h"
#include <vector>

class Factory {
public:
	Factory(std::size_t, std::size_t, WorkingQueue::__queue_size);
	~Factory();

	void start();
private:
	WorkingQueue::__queue_size _size;
	WorkingQueue _queue;
	std::size_t _num_producer;
	std::size_t _num_consumer;
	std::vector<ProductThread> _producers;
	std::vector<ConsumerThread> _consumers;
};

#endif
