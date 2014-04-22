/*************************************************************************
	> File Name: ProductThread.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 19时53分09秒
 ************************************************************************/

#ifndef PRODUCT_THREAD_H_
#define PRODUCT_THREAD_H_

#include "WorkingQueue.h"
#include "Thread.h"

class ProductThread : public Thread {
public:
	ProductThread(WorkingQueue *p_queue);
	void run();
private:
	WorkingQueue *_p_queue;
};

#endif

