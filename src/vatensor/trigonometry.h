#ifndef TRIGONOMETRY_H
#define TRIGONOMETRY_H

#include "varray.h"

namespace va {
    VArray sin(const VArray& array);
    VArray cos(const VArray& array);
    VArray tan(const VArray& array);

    // Added asin, acos, atan
    VArray asin(const VArray& array);
    VArray acos(const VArray& array);
    VArray atan(const VArray& array);

    // Added sinh, cosh, tanh
    VArray sinh(const VArray& array);
    VArray cosh(const VArray& array);
    VArray tanh(const VArray& array);

    // Added asinh, acosh, a tanh
    VArray asinh(const VArray& array);
    VArray acosh(const VArray& array);
    VArray atanh(const VArray& array);


}

#endif //TRIGONOMETRY_H
