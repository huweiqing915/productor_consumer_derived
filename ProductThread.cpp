/*************************************************************************
	> File Name: ProductThread.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 19时53分28秒
 ************************************************************************/

#include "ProductThread.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

ProductThread::ProductThread(WorkingQueue *p_queue):_p_queue(p_queue)
{
	srand(time(NULL));
}

void ProductThread::run()
{
	while(true)
	{
		int num = rand()%100;
		_p_queue->product(num);
		std::cout << "Product a number: " << num << std::endl;
		sleep(2);
	}
}
