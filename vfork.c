#include <sys/types.h>
#include <unistd.h>


void main() {
    chmod("./flag", 0777);
    vfork();
}
