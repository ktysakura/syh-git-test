/*Mutex.cpp: create automatically by makeclass at 2013-07-12*/
#include "Mutex.h"

BEGIN_NAMESPACE

CMutex::CMutex()
{
	::InitializeCriticalSectionAndSpinCount(&m_critical, 4000);
}

CMutex::~CMutex()
{
	::DeleteCriticalSection(&m_critical);
}

int CMutex::lock()
{
	::EnterCriticalSection(&m_critical);
	return 0;
}

int CMutex::unlock()
{
	::LeaveCriticalSection(&m_critical);
	return 0;
}
	
END_NAMESPACE