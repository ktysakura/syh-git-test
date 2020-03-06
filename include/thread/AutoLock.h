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
		val = reinterpret_cast<uint64_t>(mutex);
		ASSERT_X((val & 1u) == 0u, "CAutoLock", "CMutex pointer is misaligned");
		if (LIKELY(mutex)) {
			mutex->lock();
			val = (val | 1u);
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
	uint64_t val;
};
	
END_NAMESPACE

#endif //AUTO_LOCK_H__20180820
