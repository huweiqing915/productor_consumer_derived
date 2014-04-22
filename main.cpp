/*************************************************************************
	> File Name: main.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 20时45分33秒
 ************************************************************************/

#include "Factory.h"

int main(int argc, char *argv[])
{
	Factory factory(3, 2, 7);
	factory.start();

	return 0;
}
