#include "allocate.hpp"

#include <utility>                      // for move
#include <variant>                      // for visit
#include "varray.hpp"            // for VArray, shape_type, DType
#include "xtensor/xbuilder.hpp"         // for empty
#include "xtensor/xlayout.hpp"          // for layout_type
#include "xtensor/xoperation.hpp"       // for cast

using namespace va;

std::shared_ptr<VArray> empty(VScalar type, shape_type shape) {
#ifdef NUMDOT_DISABLE_ALLOCATION_FUNCTIONS
    throw std::runtime_error("function explicitly disabled; recompile without NUMDOT_DISABLE_ALLOCATION_FUNCTIONS to enable it.");
#else
	return std::visit(
		[shape](auto t) {
			using T = decltype(t);
			return from_store(make_store<T>(xt::empty<T>(shape)));
		}, type
	);
#endif
}

std::shared_ptr<VArray> va::full(const VScalar fill_value, shape_type shape) {
#ifdef NUMDOT_DISABLE_ALLOCATION_FUNCTIONS
    throw std::runtime_error("function explicitly disabled; recompile without NUMDOT_DISABLE_ALLOCATION_FUNCTIONS to enable it.");
#else
	// This is duplicate code, but by filling the store directly instead of the VArray we avoid a few checks, speeding it up a ton.
	return std::visit(
		[shape](auto fill_value) {
			using T = decltype(fill_value);
			auto store = make_store<T>(xt::empty<T>(shape));
			store->fill(fill_value);
			return from_store(store);
		}, fill_value
	);
#endif
}

std::shared_ptr<VArray> va::empty(DType dtype, shape_type shape) {
	return ::empty(dtype_to_variant(dtype), std::move(shape));
}

std::shared_ptr<VArray> va::eye(DType dtype, shape_type shape, int k) {
#ifdef NUMDOT_DISABLE_ALLOCATION_FUNCTIONS
    throw std::runtime_error("function explicitly disabled; recompile without NUMDOT_DISABLE_ALLOCATION_FUNCTIONS to enable it.");
#else
	// For some reason, xt::eye wants this specific type
	auto shape_eye = std::vector<std::size_t>(shape.size());
	std::copy(shape.begin(), shape.end(), shape_eye.begin());
	return std::visit(
		[&shape_eye, k](auto t) -> std::shared_ptr<VArray> {
			using T = decltype(t);
			return from_store(make_store(xt::eye<T>(shape_eye, k)));
		}, dtype_to_variant(dtype)
	);
#endif
}

std::shared_ptr<VArray> va::copy_as_dtype(const VArray& other, DType dtype) {
#ifdef NUMDOT_DISABLE_ALLOCATION_FUNCTIONS
    throw std::runtime_error("function explicitly disabled; recompile without NUMDOT_DISABLE_ALLOCATION_FUNCTIONS to enable it.");
#else
	if (dtype == DTypeMax) dtype = other.dtype();

	return std::visit(
		[](auto t, auto carray) -> std::shared_ptr<VArray> {
			using TWeWanted = decltype(t);
			using TWeGot = typename decltype(carray)::value_type;

			if constexpr (std::is_same_v<TWeWanted, TWeGot>) {
				return from_store(make_store<TWeWanted>(carray));
			}

			// Cast first to reduce number of combinations down the line.
			return from_store(make_store<TWeWanted>(xt::cast<TWeWanted>(carray)));
		}, dtype_to_variant(dtype), other.read
	);
#endif
}
