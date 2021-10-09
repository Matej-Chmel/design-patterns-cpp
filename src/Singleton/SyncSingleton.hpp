#pragma once
#include <functional>
#include <mutex>
#include "Singleton.hpp"

namespace mch {
	template<class D>
	class SyncSingleton : public Singleton<D> {
		static inline std::mutex mutex;

	protected:
		SyncSingleton() = default;

	public:
		static D& instance();

		void transaction(const std::function<void(D&)> f);
	};

	template<class D>
	inline D& SyncSingleton<D>::instance() {
		std::unique_lock _(mutex);
		return Singleton<D>::instance();
	}

	template<class D>
	inline void SyncSingleton<D>::transaction(const std::function<void(D&)> f) {
		std::unique_lock _(mutex);
		f(static_cast<D&>(*this));
	}
}
