/* LibMemcached
 * Copyright (C) 2010 Brian Aker, Trond Norbye
 * All rights reserved.
 *
 * Use and distribution licensed under the BSD license.  See
 * the COPYING file in the parent directory for full text.
 *
 * Summary: "Implementation" of the function we don't have on windows
 *          to avoid a bunch of ifdefs in the rest of the code
 *
 */
#ifndef WIN32_WRAPPERS_H
#define WIN32_WRAPPERS_H 1

#include <inttypes.h>

/*
 * One of the Windows headers define interface as a macro, but that
 * is causing problems with the member named "interface" in some of the
 * structs.
 */
#undef interface

#undef malloc
#undef realloc

#define snprintf _snprintf
#define PRIu64 "I64u"

#define poll(a,b,c) WSAPoll(a,b,c)

#define gettimeofday(a, b) win_gettimeofday(a)
extern int win_gettimeofday(struct timeval *t);
#define strdup(a) _strdup(a)
#define strtoull(a, b, c) _strtoui64(a, b, c) 
#define strtoll(a, b, c) _strtoi64(a, b, c) 

#define getsockopt(a, b, c, d, e) win_getsockopt(a, b, c, d, e)
extern int win_getsockopt(SOCKET s, int level, int optname, void *value, socklen_t *option_len);

#define setsockopt(a, b, c, d, e) win_setsockopt(a, b, c, d, e)
extern int win_setsockopt(SOCKET s, int level, int optname, const void *value, socklen_t option_len);

#if 0
/*
 * WinSock use a separate range for error codes. Let's just map to the
 * WinSock ones.
 */
#define EADDRINUSE WSAEADDRINUSE
#define EWOULDBLOCK WSAEWOULDBLOCK
#define EINPROGRESS WSAEINPROGRESS
#define EALREADY WSAEALREADY
#define EISCONN WSAEISCONN
#define ENOTCONN WSAENOTCONN
#define ENOBUFS WSAENOBUFS
#define SHUT_RDWR SD_BOTH
#endif

/* EAI_SYSTEM isn't defined anywhere... just set it to... 11? */
#define EAI_SYSTEM 11

/* Best effort mapping of functions to alternative functions */
#define index(a,b) strchr(a,b)
#define rindex(a,b) strrchr(a,b)
#define random() rand()
#define kill(a, b) while (false) {}
#define fork() (-1)
#define waitpid(a,b,c) (-1)
#define fnmatch(a,b,c) (-1)
#define sleep(a) Sleep(a*1000)

#endif /* WIN32_WRAPPERS_H */
