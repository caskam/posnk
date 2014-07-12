#include <stdint.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/utime.h>
#include <_ansi.h>
#include "posnk_sc.h"


int
_DEFUN (mkdir, (path, mode),
        const char *path  _AND
        mode_t mode)
{
   int a[] = {(uint32_t) path, (uint32_t) mode, 0,0};
   int b[] = {(uint32_t) 1+strlen(path),0,0,0};
   return (int) nk_do_syscall(SYS_MKDIR, a, b); 
}

int
_DEFUN (rmdir, (path),
        const char *path)
{
   int a[] = {(uint32_t) path, 0, 0,0};
   int b[] = {(uint32_t) 1+strlen(path),0,0,0};
   return (int) nk_do_syscall(SYS_RMDIR, a, b); 
}

int
_DEFUN (chown, (path, owner, group),
        const char *path  _AND
        uid_t owner _AND
        gid_t group)
{
   int a[] = {(uint32_t) path, (uint32_t) owner, (uint32_t) group,0};
   int b[] = {(uint32_t) 1+strlen(path),0,0,0};
   return (int) nk_do_syscall(SYS_CHOWN, a, b); 
}

int
_DEFUN (lchown, (path, owner, group),
        const char *path  _AND
        uid_t owner _AND
        gid_t group)
{
   int a[] = {(uint32_t) path, (uint32_t) owner, (uint32_t) group,0};
   int b[] = {(uint32_t) 1+strlen(path),0,0,0};
   return (int) nk_do_syscall(SYS_CHOWN, a, b); 
}

void sync(){};

int
_DEFUN (pipe2, (pipefd, flags),
        int pipefd[2] _AND
        int   flags)
{
   int a[] = {(uint32_t) pipefd, (uint32_t) flags,0,0};
   int b[] = {(uint32_t) 0,0,0,0};
   return (int) nk_do_syscall(SYS_PIPE2, a, b); 
}

int
_DEFUN (pipe, (pipefd),
        int pipefd[2])
{
   int a[] = {(uint32_t) pipefd,0,0,0};
   int b[] = {(uint32_t) 0,0,0,0};
   return (int) nk_do_syscall(SYS_PIPE, a, b); 
}

int
_DEFUN (dup, (old),
        int old)
{
   int a[] = {(uint32_t) old, 0,0,0};
   int b[] = {(uint32_t) 0,0,0,0};
   return (int) nk_do_syscall(SYS_DUP, a, b); 
}

int
_DEFUN (dup2, (old,new),
        int old _AND
	int new)
{
   int a[] = {(uint32_t) old, (uint32_t) new,0,0};
   int b[] = {(uint32_t) 0,0,0,0};
   return (int) nk_do_syscall(SYS_DUP2, a, b); 
}

int
_DEFUN (close, (fildes),
        int fildes)
{
   int a[] = {(uint32_t) fildes, 0,0,0};
   int b[] = {0,0,0,0};
   return (int) nk_do_syscall(SYS_CLOSE, a, b); 
}

int
_DEFUN (fstat, (fildes, st),
        int          fildes _AND
        struct stat *st)
{
   int a[] = {(uint32_t) fildes, (uint32_t) st,0,0};
   int b[] = {0,0,0,0};
   return (int) nk_do_syscall(SYS_FSTAT, a, b); 
}

int
_DEFUN (_isatty, (file),
        int file)
{
  struct stat buf;

  if (fstat (file, &buf) < 0) {
    errno = EBADF;
    return 0;
  }
  if (S_ISCHR (buf.st_mode))
    return 1;
  errno = ENOTTY;
  return 0;
}

int
_DEFUN (link, (existing, new),
        char *existing _AND
        char *new)
{
   int a[] = {(uint32_t) existing, (uint32_t) new, 0,0};
   int b[] = {(uint32_t) 1+strlen(existing), 1+strlen(new),0,0};
   return (int) nk_do_syscall(SYS_LINK, a, b); 
}

int
_DEFUN (lseek, (file, ptr, dir),
        int   file  _AND
        int   ptr   _AND
        int   dir)
{
   int a[] = {(uint32_t) file, (uint32_t) ptr, (uint32_t) dir,0};
   int b[] = {0, 0, 0, 0};
   return (int) nk_do_syscall(SYS_LSEEK, a, b); 
}

int
_DEFUN (ftruncate, (file, length),
        int   file  _AND
        off_t length)
{
   int a[] = {(uint32_t) file, (uint32_t) length, 0,0};
   int b[] = {0, 0, 0, 0};
   return (int) nk_do_syscall(SYS_FTRUNCATE, a, b); 
}

int
_DEFUN (truncate, (file, length),
        const char  *file  _AND
        off_t length)
{
   int a[] = {(uint32_t) file, (uint32_t) length,0,0};
   int b[] = {(uint32_t) 1+strlen(file),0,0,0};
   return (int) nk_do_syscall(SYS_TRUNCATE, a, b); 
}

int
_DEFUN (open, (file, flags, mode),
        char *file  _AND
        int   flags _AND
        int   mode)
{
   uint32_t a[] = {(uint32_t) file, (uint32_t) flags, (uint32_t) mode,0};
   uint32_t b[] = {(uint32_t) 1+strlen(file), 0, 0, 0};
   return (int) nk_do_syscall(SYS_OPEN, a, b); 
}

int utime(const char *filename, const struct utimbuf *times)
{
	return 0;
}

int utimes(const char *filename, const struct timeval times[2])
{
	return 0;
}

int
_DEFUN (read, (file, ptr, len),
        int   file  _AND
        char *ptr   _AND
        int   len)
{
   int a[] = {(uint32_t) file, (uint32_t) ptr, (uint32_t) len,0};
   int b[] = {0, 0, 0, 0};
   return (int) nk_do_syscall(SYS_READ, a, b); 
}

int
_DEFUN (readlink, (path, buf, bufsize),
        const char *path _AND
        char *buf _AND
        size_t bufsize)
{
   int a[] = {(uint32_t) path, (uint32_t) buf, (uint32_t) bufsize,0};
   int b[] = {(uint32_t) 1+strlen(path),0,0,0};
   return (int) nk_do_syscall(SYS_READLINK, a, b); 
}

int
_DEFUN (stat, (file, st),
        const char  *file _AND
        struct stat *st)
{
   int a[] = {(uint32_t) file, (uint32_t) st,0,0};
   int b[] = {(uint32_t) 1+strlen(file),0,0,0};
   return (int) nk_do_syscall(SYS_STAT, a, b); 
}

int fcntl(int fd, int cmd, int arg)
{
   int a[] = {(uint32_t) fd, (uint32_t) cmd, (uint32_t) arg,0};
   int b[] = {0,0,0,0};
   return (int) nk_do_syscall(SYS_FCNTL, a, b);	
}

int ioctl(int fd, int cmd, int arg)
{
   int a[] = {(uint32_t) fd, (uint32_t) cmd, (uint32_t) arg,0};
   int b[] = {0,0,0,0};
   return (int) nk_do_syscall(SYS_IOCTL, a, b);	
}

int chdir(const char *path)
{
   int a[] = {(uint32_t) path, 0,0,0};
   int b[] = {(uint32_t) 1+strlen(path),0,0,0};
   return (int) nk_do_syscall(SYS_CHDIR, a, b);
}

int chmod(const char *path, mode_t mode)
{
   int a[] = {(uint32_t) path, (uint32_t) mode,0,0};
   int b[] = {(uint32_t) 1+strlen(path),0,0,0};
   return (int) nk_do_syscall(SYS_CHMOD, a, b);
}

int mknod(const char *path, mode_t mode, dev_t dev)
{
   int a[] = {(uint32_t) path, (uint32_t) mode, (uint32_t) dev,0};
   int b[] = {(uint32_t) 1+strlen(path),0,0,0};
   return (int) nk_do_syscall(SYS_MKNOD, a, b);
}

int fchdir(int fd)
{
   int a[] = {(uint32_t) fd,0,0,0};
   int b[] = {0,0,0,0};
   return (int) nk_do_syscall(SYS_FCHDIR, a, b);
}

mode_t umask(mode_t mask)
{
   int a[] = {(uint32_t) mask,0,0,0};
   int b[] = {0,0,0,0};
   return (mode_t) nk_do_syscall(SYS_UMASK, a, b);

}
#include <sys/time.h>

int gettimeofday(struct timeval *tv, void *tz)
{
	int a[] = {0,0,0,0};
	int b[] = {0,0,0,0};
	
	tv->tv_sec = (time_t) nk_do_syscall(SYS_TIME, a, b);
	return 0;
}

int access(const char *pathname, int mode){
	return 0;
}
int getdents (int fd, void *dp, int count)
{
   int a[] = {(uint32_t) fd, (uint32_t) dp, (uint32_t) count,0};
   int b[] = {0, 0, 0, 0};
   return (int) nk_do_syscall(SYS_GETDENTS, a, b); 
}

int
_DEFUN (lstat, (file, st),
        const char  *file _AND
        struct stat *st)
{
   int a[] = {(uint32_t) file, (uint32_t) st,0,0};
   int b[] = {(uint32_t) 1+strlen(file),0,0,0};
   return (int) nk_do_syscall(SYS_LSTAT, a, b); 
}

int
_DEFUN (symlink, (path1, path2),
        const char *path1 _AND
        const char *path2)
{
   int a[] = {(uint32_t) path1, (uint32_t) path2, 0,0};
   int b[] = {(uint32_t) 1+strlen(path1), 1+strlen(path2),0,0};
   return (int) nk_do_syscall(SYS_SYMLINK, a, b); 
}

int
_DEFUN (unlink, (name),
        char *name)
{
   int a[] = {(uint32_t) name, 0,0,0};
   int b[] = {(uint32_t) 1+strlen(name),0,0,0};
   return (int) nk_do_syscall(SYS_UNLINK, a, b);
}

int
_DEFUN (write, (file, ptr, len),
        int   file  _AND
        char *ptr   _AND
        int   len)
{
   int a[] = {(uint32_t) file, (uint32_t) ptr, (uint32_t) len,0};
   int b[] = {0, 0, 0, 0};
   return (int) nk_do_syscall(SYS_WRITE, a, b); 
}
