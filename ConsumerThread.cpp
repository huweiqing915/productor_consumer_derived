/*************************************************************************
	> File Name: ConsumerThread.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 18时53分55秒
 ************************************************************************/

#include "ConsumerThread.h"
#include <iostream>

ConsumerThread::ConsumerThread(WorkingQueue *p_queue):_p_queue(p_queue)  { }

void ConsumerThread::run()
{
	while(true)
	{
		int num = _p_queue->consume();
		std::cout << "get a number:" << num << std::endl;
		sleep(3);
	}
}


