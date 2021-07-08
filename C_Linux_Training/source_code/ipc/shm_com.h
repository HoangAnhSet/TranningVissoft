#ifndef _SHM_H
#define _SHM_H
#define TEXT_SZ 2048
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct shared_use_st
{
    int writen_by_you;
    char some_text[TEXT_SZ];
};
#endif