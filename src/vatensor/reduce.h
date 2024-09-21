#ifndef REDUCE_H
#define REDUCE_H

#include "auto_defines.h"
#include "varray.h"

namespace va {
    void sum(VArrayTarget target, const VArray& array, const Axes& axes);
    void prod(VArrayTarget target, const VArray& array, const Axes& axes);
    void mean(VArrayTarget target, const VArray& array, const Axes& axes);
    void var(VArrayTarget target, const VArray& array, const Axes& axes);
    void std(VArrayTarget target, const VArray& array, const Axes& axes);
    void max(VArrayTarget target, const VArray& array, const Axes& axes);
    void min(VArrayTarget target, const VArray& array, const Axes& axes);

    void norm_l0(VArrayTarget target, const VArray& array, const Axes& axes);
    void norm_l1(VArrayTarget target, const VArray& array, const Axes& axes);
    void norm_l2(VArrayTarget target, const VArray& array, const Axes& axes);
    void norm_linf(VArrayTarget target, const VArray& array, const Axes& axes);

    void all(VArrayTarget target, const VArray& array, const Axes& axes);
    void any(VArrayTarget target, const VArray& array, const Axes& axes);
}

#endif //REDUCE_H
