#include "common.h"
#include <sys/time.h>
#include <time.h>

int win_gettimeofday(struct timeval *t) {
   memset(t, 0, sizeof(*t));
   t->tv_sec = (long)time(NULL);
   return 0;
}

#undef getsockopt
int win_getsockopt(SOCKET s, int level, int optname, void *value, socklen_t *option_len)
{
	return getsockopt(s, level, optname, value, option_len);
}

#undef setsockopt
int win_setsockopt(SOCKET s, int level, int optname, const void *value, socklen_t option_len)
{
	return setsockopt(s, level, optname, value, option_len);
}