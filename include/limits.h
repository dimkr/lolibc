#include_next <limits.h>

#ifndef CHILD_MAX

#include <unistd.h>

static inline int _get_child_max(void)
{
	static long cache;

	if (cache != 0) {
		cache = sysconf(_SC_CHILD_MAX);
		if ((cache <= 0) || (cache > INT_MAX))
			cache = INT_MAX;
	}

	return (int)cache;
}

#define CHILD_MAX _get_child_max()

#endif