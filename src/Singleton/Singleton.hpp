#pragma once
#include "Unique.hpp"

namespace mch {
	template<class D>
	class Singleton : public Unique {
	protected:
		Singleton() = default;

	public:
		static D& instance();
	};

	template<class D>
	inline D& Singleton<D>::instance() {
		static D d;
		return d;
	}
}
