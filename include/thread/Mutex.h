#if !defined (MUTEX_LOCK_H__20180820)
#define MUTEX_LOCK_H__20180820

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <global/base.h>

BEGIN_NAMESPACE


class CMutex
{
public:
	enum RecursionMode { NonRecursive, Recursive };
	int lock();
    int unlock();
	
	CMutex(RecursionMode mode = NonRecursive);
	virtual ~CMutex();

private:
	CRITICAL_SECTION m_critical;
	RecursionMode m_recursionMode;
};
	
END_NAMESPACE

#endif //MUTEX_LOCK_H__20180820
