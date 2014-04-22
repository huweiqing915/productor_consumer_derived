/*************************************************************************
	> File Name: Thread.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 17时32分34秒
 ************************************************************************/

#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>

class Thread {
public:
	Thread();
	virtual ~Thread();

	void start();
	void join();
	virtual void run();

	pthread_t get_tid() const;
private:
	pthread_t _tid;
	 /*
	  * function must be defined with static,in order to use it in pthread_create(),the third argument.
	  */
	static void* thread_func(void *);
};

#endif
