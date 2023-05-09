// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <../include/internal/arch/x86_64/syscall_list.h>
#include <../include/internal/syscall.h>


int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */

	int ret = syscall(__NR_stat, path, buf);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
