#include <../include/time.h>

unsigned int sleep(unsigned int seconds) {

    struct timespec sec;
    sec.tv_sec = seconds;
    sec.tv_nsec = 0;

    struct timespec rem;

    int ret = nanosleep(&sec, &rem);

    if (ret < 0) {
        return -1;
    }

    return 0;
}