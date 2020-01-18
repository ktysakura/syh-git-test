#if !defined (AUTO_LOCK_H__20180820)
#define AUTO_LOCK_H__20180820

#include <global/base.h>
#include "Mutex.h"

BEGIN_NAMESPACE


class CAutoLock
{
public:
	inline CAutoLock(CMutex* mutex)
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

	inline CMutex *mutex() const
	{
		return reinterpret_cast<CMutex *>(val & ~1u);
	}

private:
	unsigned int val;
};
	
END_NAMESPACE

#endif //AUTO_LOCK_H__20180820
