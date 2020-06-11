#ifndef _LOLIBC_SIGNAL_H
#define _LOLIBC_SIGNAL_H

#include_next <signal.h>

#ifndef HAVE_SYS_SIGNAME
extern char *sys_signame[];
#endif

#ifndef HAVE_SYS_SIGLIST
char **strsignals(void);
#define sys_siglist (strsignals())
#endif

#endif
