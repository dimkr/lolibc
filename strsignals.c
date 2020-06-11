#include <signal.h>
#include <string.h>

char **strsignals(void)
{
	static char *strs[NSIG];
	int sig;
	for (sig = 0; sig < NSIG; ++sig) {
		if (!strs[sig])
			strs[sig] = strsignal(sig);
	}
	return strs;
}
