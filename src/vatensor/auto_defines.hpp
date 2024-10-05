#ifndef AUTO_DEFINES_H
#define AUTO_DEFINES_H

#ifdef NUMDOT_DISABLE_ALL_OPTIONAL_FUNCTIONS
#define NUMDOT_DISABLE_ALLOCATION_FUNCTIONS
#define NUMDOT_DISABLE_COMPARISON_FUNCTIONS
#define NUMDOT_DISABLE_LOGICAL_FUNCTIONS
#define NUMDOT_DISABLE_REDUCTION_FUNCTIONS
#define NUMDOT_DISABLE_ROUNDING_FUNCTIONS
#define NUMDOT_DISABLE_TRIGONOMETRY_FUNCTIONS
#define NUMDOT_DISABLE_MATH_FUNCTIONS
#define NUMDOT_DISABLE_RANDOM_FUNCTIONS
#define NUMDOT_DISABLE_GODOT_CONVERSION_FUNCTIONS
#define NUMDOT_DISABLE_INDEX_LISTS
#define NUMDOT_DISABLE_INDEX_MASKS
#endif

#ifdef NUMDOT_ENABLE_ALLOCATION_FUNCTIONS
#undef NUMDOT_DISABLE_ALLOCATION_FUNCTIONS
#endif

#ifdef NUMDOT_ENABLE_COMPARISON_FUNCTIONS
#undef NUMDOT_DISABLE_COMPARISON_FUNCTIONS
#endif

#ifdef NUMDOT_ENABLE_LOGICAL_FUNCTIONS
#undef NUMDOT_DISABLE_LOGICAL_FUNCTIONS
#endif

#ifdef NUMDOT_ENABLE_REDUCTION_FUNCTIONS
#undef NUMDOT_DISABLE_REDUCTION_FUNCTIONS
#endif

#ifdef NUMDOT_ENABLE_ROUNDING_FUNCTIONS
#undef NUMDOT_DISABLE_ROUNDING_FUNCTIONS
#endif

#ifdef NUMDOT_ENABLE_TRIGONOMETRY_FUNCTIONS
#undef NUMDOT_DISABLE_TRIGONOMETRY_FUNCTIONS
#endif

#ifdef NUMDOT_ENABLE_MATH_FUNCTIONS
#undef NUMDOT_DISABLE_MATH_FUNCTIONS
#endif

#ifdef NUMDOT_ENABLE_RANDOM_FUNCTIONS
#undef NUMDOT_DISABLE_RANDOM_FUNCTIONS
#endif

#ifdef NUMDOT_ENABLE_GODOT_CONVERSION_FUNCTIONS
#undef NUMDOT_DISABLE_GODOT_CONVERSION_FUNCTIONS
#endif

#ifdef NUMDOT_ENABLE_INDEX_LISTS
#undef NUMDOT_DISABLE_INDEX_LISTS
#endif

#ifdef NUMDOT_ENABLE_INDEX_MASKS
#undef NUMDOT_DISABLE_INDEX_MASKS
#endif

#endif //AUTO_DEFINES_H
