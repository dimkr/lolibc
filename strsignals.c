#include <signal.h>
#include <string.h>

char **strsignals(void)
{
	static char *strs[NSIG], bufs[NSIG][32];
	int sig;
	for (sig = 0; sig < NSIG; ++sig) {
		if (!strs[sig]) {
			strlcpy(bufs[sig], strsignal(sig), 32);
			strs[sig] = bufs[sig];
		}
	}
	return strs;
}
