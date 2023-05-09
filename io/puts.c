#include <../include/internal/io.h>
#include <../include/string.h>



int puts(const char *str) {
    
    int ret = write(1, str, strlen(str) + 1); //+1 accounts for null-terminator

    if (ret < 0) {
        return -1; //EOF but the macro wasn't there lmao
    }

    ret = write(1, "\n", 1);

    if (ret < 0) {
        return -1;
    }

    return ret;


    

}
