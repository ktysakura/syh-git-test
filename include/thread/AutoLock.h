#if !defined (AUTO_LOCK_H__20180820)
#define AUTO_LOCK_H__20180820

#include "MutexLock.h"


class CAutoLock
{
public:
	inline CAutoLock(CMutexLock* mutex)
	{
		if (mutex) {
			mutex->lock();
			val = (reinterpret_cast<unsigned int>(mutex) | 1u);
		}
		else {
			val = 0;
		}
	}

	virtual ~CAutoLock()
	{
		unlock();
	}

	inline void relock() {
		if (val) {
			if ((val & 1u) == 0u) {
				mutex()->lock();
				val |= 1u;
			}
		}
	}

	inline void unlock() {
		if ((val & 1u) == 1u) {
			val &= ~1u;
			mutex()->unlock();
		}
	}

	inline CMutexLock *mutex() const
	{
		return reinterpret_cast<CMutexLock *>(val & ~1u);
	}

private:
	unsigned int val;
};
	

#endif //AUTO_LOCK_H__20180820
