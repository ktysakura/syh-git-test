#include "global/base.h"

void assert_x(const char *where, const char *what, const char *file, int line)
{
	assert(false && "---------");
	//	QMessageLogger(file, line, nullptr).fatal("ASSERT failure in %s: \"%s\", file %s, line %d", where, what, file, line);
}
