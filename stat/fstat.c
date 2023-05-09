// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>
#include <../include/internal/arch/x86_64/syscall_list.h>
#include <../include/internal/syscall.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
int ret = syscall(__NR_fstat, fd, st);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
