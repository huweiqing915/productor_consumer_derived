/*************************************************************************
	> File Name: ConsumerThread.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 18时53分46秒
 ************************************************************************/

#ifndef CONSUMER_THREAD_H_
#define CONSUMER_THREAD_H_

#include "Thread.h"
#include "WorkingQueue.h"

class ConsumerThread : public Thread {
public:
	ConsumerThread(WorkingQueue *p_queue);
	void run();
private:
	WorkingQueue *_p_queue;
};

#endif
