#if !defined(_THREAD_20200103_)
#define _THREAD_20200103_
#include <global/base.h>
#include "AutoLock.h"

BEGIN_NAMESPACE

#define THREAD_EXIT_TIME 3000
//class CThreadImpl;
class CThread {
public:
	enum Priority {
		IdlePriority,
		LowestPriority,
		LowPriority,
		NormalPriority,
		HighPriority,
		HighestPriority,
		TimeCriticalPriority,
		InheritPriority
	};
public:
	CThread();
	virtual ~CThread();
	bool isFinished() const;
	bool isRunning() const;
	bool isWaiting() const;
	Priority priority() const;
	void start(Priority = InheritPriority);
	void terminate();
	bool wakeUp();
	bool join(unsigned long time = THREAD_EXIT_TIME);
	void exit(int retcode = 0);
	int idealThreadCount();
public:
	static int currentThreadId();
	static void sleep(unsigned long secs);
	static void msleep(unsigned long msecs);
	static void usleep(unsigned long usecs);
public:
	void setWait();
protected:
	virtual void run() = 0;
	virtual void started() {}
	virtual void finished() {}
protected:
	bool wait(unsigned long time = -1);
	void setTerminationEnabled(bool enabled);
#ifdef _WIN32
	static unsigned int __stdcall on_thread_proc(void *arg);
	static void on_thread_finish(void *arg, bool lockAnyway = true);
	HANDLE m_hThread;
	HANDLE m_hEvent;
#else

#endif
protected:
	bool m_waitThread;
private:
	mutable CMutex m_mutex;
	bool m_running;
	bool m_finished;
	bool m_terminationEnabled;
	bool m_terminatePending;
	bool m_isInFinish;             //when in QThreadPrivate::finish
	bool m_exited;
	int m_returnCode;
	int m_waiters;
	unsigned int m_id;
	unsigned int m_stackSize;
	Priority m_priority;
	//CThreadImpl *p;
};

END_NAMESPACE

#endif
