#include "container.h"

typedef struct MyContainerClass
{
    Container base;
    int _val;
} MyContainerClass;

static const MyContainerClass _descr = {
    { /* Container struct */
        { /* Class struct */
        .__size__ = sizeof(_descr),
        .__name__ = "MyContainer",
        /* All Class functions here */
        }
    },
/* Members of MyContainer */
    ._val = 0
};