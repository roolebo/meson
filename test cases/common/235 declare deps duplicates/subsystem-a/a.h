#ifndef __A_H__
#define __A_H__
#include <dep/dep.h>

struct a {
    struct deep_dep dep_field;
    int a_field;
};

int get_a_field(struct a *);
#endif
