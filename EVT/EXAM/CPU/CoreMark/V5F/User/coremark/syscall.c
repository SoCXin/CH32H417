/*******************************************************************************
 * (c) Copyright 2016-2018 Microsemi SoC Products Group.  All rights reserved.
 *
 * @file syscall.c
 * @author Microsemi SoC Products Group
 * @brief Stubs for system calls.
 *
 * SVN $Revision: 9661 $
 * SVN $Date: 2018-01-15 16:13:33 +0530 (Mon, 15 Jan 2018) $
 */
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <stdio.h>
#include <string.h>
#include"debug.h"


#undef errno
int errno;

char *__env[1] = { 0 };
char **environ = __env;

void write_hex(int fd, uint32_t hex)
{
    uint8_t ii;
    uint8_t jj;
    char towrite;
    uint8_t digit;

    write( fd , "0x", 2 );

    for (ii = 8 ; ii > 0; ii--)
    {
        jj = ii-1;
        digit = ((hex & (0xF << (jj*4))) >> (jj*4));
        towrite = digit < 0xA ? ('0' + digit) : ('A' +  (digit - 0xA));
        write( fd, &towrite, 1);
    }
}

               
void _exit(int code)
{


    while (1);
}

// void *_sbrk(ptrdiff_t incr)
// {
//     extern char _end[];
//     extern char _heap_end[];
//     static char *curbrk = _end;

//     if ((curbrk + incr < _end) || (curbrk + incr > _heap_end))
//     {
//         return ((char *) - 1);
//     }

//     curbrk += incr;
//     return curbrk - incr;
// }

int _isatty(int fd)
{
    if (fd == STDOUT_FILENO || fd == STDERR_FILENO)
    {
        return 1;
    }

    errno = EBADF;
    return 0;
}

static int stub(int err)
{
    errno = err;
    return -1;
}

int _open(const char* name, int flags, int mode)
{
    return stub(ENOENT);
}

int _openat(int dirfd, const char* name, int flags, int mode)
{
    return stub(ENOENT);
}

int _close(int fd)
{
    return stub(EBADF);
}

int _execve(const char* name, char* const argv[], char* const env[])
{
    return stub(ENOMEM);
}

int _fork()
{
    return stub(EAGAIN);
}

int _fstat(int fd, struct stat *st)
{
    if (isatty(fd))
    {
        st->st_mode = S_IFCHR;
        return 0;
    }

    return stub(EBADF);
}

int _getpid()
{
    return 1;
}

int _kill(int pid, int sig)
{
    return stub(EINVAL);
}

int _link(const char *old_name, const char *new_name)
{
    return stub(EMLINK);
}

off_t _lseek(int fd, off_t ptr, int dir)
{
    if (_isatty(fd))
    {
        return 0;
    }

    return stub(EBADF);
}

ssize_t _read(int fd, void* ptr, size_t len)
{

    return stub(EBADF);
}

int _stat(const char* file, struct stat* st)
{
    return stub(EACCES);
}

clock_t _times(struct tms* buf)
{
    return stub(EACCES);
}

int _unlink(const char* name)
{
    return stub(ENOENT);
}

int _wait(int* status)
{
    return stub(ECHILD);
}



#ifdef __cplusplus
}
#endif
