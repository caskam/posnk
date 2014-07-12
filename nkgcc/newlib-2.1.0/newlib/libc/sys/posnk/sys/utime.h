/* FIXME: From sys/sysvi386/sys */
#ifndef _SYS_UTIME_H
# define _SYS_UTIME_H

#include <time.h>

struct utimbuf {
	time_t	actime;
	time_t	modtime;
};
int utime(const char *filename, const struct utimbuf *times);

#endif	/* _SYS_UTIME_H */
