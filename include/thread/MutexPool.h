#if !defined(_MUTEX_POOL_H_20200118_)
#define _MUTEX_POOL_H_20200118_
#include 
class  CMutexPool
{
public:
	explicit CMutexPool(int size = 131);
	~CMutexPool();

	inline CMutex *get(const void *address) {
		int index = uint(quintptr(address)) % mutexes.count();
		QMutex *m = mutexes[index];
		if (m)
			return m;
		else
			return createMutex(index);
	}
	static QMutexPool *instance();
	static QMutex *globalInstanceGet(const void *address);

private:
	QMutex *createMutex(int index);
	QVarLengthArray<QAtomicPointer<QMutex>, 131> mutexes;
	QMutex::RecursionMode recursionMode;
};


#endif

