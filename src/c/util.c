

#ifndef UTIL
#define UTIL

#ifdef _WIN32
#include <windows.h>

#else
#define MEMINFO_FILE "/proc/meminfo"

#include <errno.h>
#include <ctype.h>
#include <libgen.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int64_t get_from_meminfo(const char* tag)
{
    int fd;
    char buf[2048];
    ssize_t nread;
    char *line_first_char;

    fd = open(MEMINFO_FILE, O_RDONLY);
    if (fd == -1) {
        printf("Failed to open %s: %s\n", MEMINFO_FILE, strerror(errno));
        return -1;
    }
    nread = read(fd, buf, sizeof(buf)-1);
    if (nread == -1) {
        printf("Failed to read from %s: %s\n", MEMINFO_FILE, strerror(errno));
        close(fd);
        return -1;
    }
    close(fd);
    buf[nread] = '\0';

    line_first_char = buf;
    while (*line_first_char) {
        char *eol = line_first_char + strcspn(line_first_char, "\n");
        if (!*eol) {
            break; // Dont parse incomplete line
        }
        *eol = 0;
        char *value = line_first_char + strcspn(line_first_char, ":");
        if(!*value) {
            break;
        }
        *value++ = 0;
        if (strcmp(line_first_char, tag) == 0) {
            return (int64_t)strtol(value, NULL, 10);
        }

        line_first_char = eol+1; // Move to the next line
    }

    printf("Failed to find %s tag in %s\n", tag, MEMINFO_FILE);
    return -1;
}

#endif


uint64_t portable_available_memory(void)
{
#ifdef _WIN32
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    return memInfo.ullAvailPhys;
#else
    uint64_t result = 0;
    int64_t ret = get_from_meminfo("MemFree");

    if (ret != -1)
        result = (uint64_t)ret*1024;

    return result;
#endif
}


#endif