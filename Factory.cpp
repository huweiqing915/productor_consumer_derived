/*************************************************************************
	> File Name: Factory.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 20时27分11秒
 ************************************************************************/

#include "Factory.h"

Factory::Factory(std::size_t num_producer, std::size_t num_consumer, WorkingQueue::__queue_size size):
	_size(size), _num_producer(num_producer), _num_consumer(num_consumer), _queue(_size), _producers(_num_producer, ProductThread(&_queue)), _consumers(_num_consumer, ConsumerThread(&_queue))  { }

Factory::~Factory()  {  }

void Factory::start()
{
	for(std::vector<ProductThread>::iterator iter = _producers.begin(); iter != _producers.end(); ++iter)
	{
		iter->start();
	}
	for(std::vector<ConsumerThread>::iterator iter = _consumers.begin(); iter != _consumers.end(); ++iter)
	{
		iter->start();
	}

	for(std::vector<ProductThread>::iterator iter = _producers.begin(); iter != _producers.end(); ++iter)
	{
		iter->join();
	}

	for(std::vector<ConsumerThread>::iterator iter = _consumers.begin(); iter != _consumers.end(); ++iter)
	{
		iter->join();
	}
}

