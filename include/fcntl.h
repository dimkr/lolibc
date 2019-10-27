#include_next <fcntl.h>

#ifndef O_EXLOCK
#define O_EXLOCK 0
#endif

#include <sys/types.h>

/* for flock() */
#include <sys/file.h>
