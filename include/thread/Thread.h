#ifndef _THREAD_20200103_
#define _THREAD_20200103_
class CThreadImpl;
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
	//static int currentThreadId();
	//void setPriority(Priority priority);
	//Priority priority() const;

	bool isFinished() const;
	bool isRunning() const;
	void exit(int retcode = 0);
	bool wait(unsigned long time = -1);
	void start(Priority = InheritPriority);
protected:
	virtual void started() {}
	virtual void run() = 0;
	virtual void finished() {}
private:
	CThreadImpl *p;
};


#endif
