#include <../include/time.h>
#include <../include/internal/arch/x86_64/syscall_list.h>
#include <../include/errno.h>
#include <../include/internal/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {

    int ret = syscall(__NR_nanosleep, req, rem);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}