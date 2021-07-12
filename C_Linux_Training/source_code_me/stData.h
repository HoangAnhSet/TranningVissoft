#ifndef _STDATA_H_
#define _STDATA_H_

#define MAX_SIZE 500

struct stData
{
    int wrote; // if =1 wrote and =0 not wrote
    char content[MAX_SIZE];
};
#endif