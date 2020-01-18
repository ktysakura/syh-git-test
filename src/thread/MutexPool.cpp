#include "MutexPool.h"

BEGIN_NAMESPACE
CMutexPool *global_mutexpool = 0;
static CMutexPool *globalMutexPool()
{
	return NULL;

}
CMutexPool::CMutexPool(CMutex::RecursionMode mode, int size)
	:recursionMode(mode), mutexes(size, 0)
{

}

CMutexPool::~CMutexPool()
{
	for (size_t index = 0; index < mutexes.size(); ++index) {
		delete mutexes[index];
		mutexes[index] = 0;
	}

}

CMutexPool *CMutexPool::instance()
{
	return globalMutexPool();
}

CMutex *CMutexPool::createMutex(int index)
{
	// mutex not created, create one
	CMutex *newMutex = new CMutex(recursionMode);
	//if (!mutexes[index].testAndSetOrdered(0, newMutex))
		delete newMutex;
	return mutexes[index];
}

CMutex *CMutexPool::globalInstanceGet(const void *address)
{
	 CMutexPool * const globalInstance = globalMutexPool();
	if (globalInstance == 0)
		return 0;
	return globalInstance->get(address);
}

END_NAMESPACE