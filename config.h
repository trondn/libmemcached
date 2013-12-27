#ifndef CONFIG_H
#define CONFIG_H

/* _SYS_FEATURE_TESTS_H is Solaris, _FEATURES_H is GCC */
#if defined( _SYS_FEATURE_TESTS_H) || defined(_FEATURES_H)
#error "You should include config.h as your first include file"
#endif

#ifdef WIN32
/* Windows specific section */
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

#else

#ifndef __APPLE__
#define HAVE_MSG_NOSIGNAL 1
#define HAVE_MSG_DONTWAIT 1
#define TIME_WITH_SYS_TIME 1
#endif

#define HAVE_SYS_TIME_H 1
#define HAVE_SYS_TYPES_H 1

/* Define to 1 or 0, depending whether the compiler supports simple visibility
   declarations. */
#define HAVE_VISIBILITY 1

#endif


#ifdef __sun
#define HAVE_HTONLL 1
#define MSG_NOSIGNAL 0
#endif

#include <inttypes.h>
#include <stdint.h>

/* To hide the platform differences between MS Windows and Unix, I am
 * going to use the Microsoft way and #define the Microsoft-specific
 * functions to the unix way. Microsoft use a separate subsystem for sockets,
 * but Unix normally just use a filedescriptor on the same functions. It is
 * a lot easier to map back to the unix way with macros than going the other
 * way without side effect ;-)
 */
#ifdef WIN32
#include "win32/wrappers.h"
/* #include "poll/poll.h" */
#define random() rand()
#define srandom(a) srand(a)
#define get_socket_errno() WSAGetLastError()

/* Are these correct? */
# define SHUT_RD SD_RECEIVE
# define SHUT_WR SD_SEND
# define SHUT_RDWR SD_BOTH

#else
#include <poll.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(a) close(a)
#define get_socket_errno() errno

#include <sys/wait.h>

#endif

#ifndef HAVE_MSG_NOSIGNAL
#define MSG_NOSIGNAL 0
#endif

#ifndef HAVE_MSG_DONTWAIT
#define MSG_DONTWAIT 0
#endif

#endif
