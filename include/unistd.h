#ifndef _LOLIBC_UNISTD_H_
#define _LOLIBC_UNISTD_H_

#include_next <unistd.h>

void	closefrom(int lowfd);

static inline
int	 pledge(const char *promises, const char *execpromises)
{
	return 0;
}

static inline
int	unveil(const char *path, const char *permissions)
{
	return 0;
}

#if !defined(HAVE_ISSETUGID) && defined(HAVE_SYS_AUXV_H)

#include <sys/auxv.h>

static inline
int	 issetugid(void)
{
	return getauxval(AT_SECURE) != 0;
}

#endif

/* for setgroups() */
#include <grp.h>

/* for R_OK */
#include <fcntl.h>

#endif
