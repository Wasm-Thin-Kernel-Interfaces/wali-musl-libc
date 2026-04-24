#define _BSD_SOURCE
#include <unistd.h>
#include "syscall.h"
#include <stdarg.h>

#undef syscall

long syscall_vargs(long n, ...)
{
	va_list ap;
	va_start(ap, n);
	long ret = __syscall_ret(__syscall_vargs(n, ap));
	va_end(ap);
	return ret;
}

weak_alias(syscall_vargs, syscall);
