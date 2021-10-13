#include <unistd.h>
#include <stdint.h>

#include "platform.h"

uint64_t get_available_physram()
{
    return get_avphys_pages() * sysconf(_SC_PAGESIZE);
}