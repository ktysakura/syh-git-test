#if !defined(_MUTEX_POOL_H_20200118_)
#define _MUTEX_POOL_H_20200118_
#include "Mutex.h"
#include "global/base.h"


BEGIN_NAMESPACE

class  CMutexPool
{
public:
	explicit CMutexPool(CMutex::RecursionMode mode = CMutex::NonRecursive, int size = 131);
	~CMutexPool();
	
	inline CMutex *get(const void *address) {
		int index = uintptr_t(address) % mutexes.size();
		CMutex *m = mutexes[index];
		if (m)
			return m;
		else
			return createMutex(index);
	}
	static CMutexPool *instance();
	static CMutex *globalInstanceGet(const void *address);

private:
	CMutex *createMutex(int index);
	vector<CMutex*> mutexes;
	CMutex::RecursionMode recursionMode;
};
extern CMutexPool *global_mutexpool;
END_NAMESPACE

#endif

