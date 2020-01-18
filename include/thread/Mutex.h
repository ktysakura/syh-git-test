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
	int lock();
    int unlock();
	
	CMutex();
	virtual ~CMutex();

private:
	CRITICAL_SECTION m_critical;
};
	
END_NAMESPACE

#endif //MUTEX_LOCK_H__20180820
