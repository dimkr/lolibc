#include_next <limits.h>

#ifndef CHILD_MAX
#include <unistd.h>
#define CHILD_MAX sysconf(_SC_CHILD_MAX)
#endif
