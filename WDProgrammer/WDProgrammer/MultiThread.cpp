#include"MultiThread.h"
mutex g_lock;
void printSth(string str, int a)
{
	cout << this_thread::get_id() << "is waiting for unlock" << endl;
	g_lock.lock();
	this_thread::sleep_for(chrono::seconds(a));
	cout <<this_thread::get_id()<< str << endl;
	g_lock.unlock();
}

