#pragma once
#include <random>

namespace mch {
	template<typename T>
	class Random {
		std::default_random_engine gen;
		std::uniform_int_distribution<size_t> dist;

	public:
		T next();
		Random(const T min, const T max);
	};

	template<typename T>
	T Random<T>::next() {
		return T(this->dist(this->gen));
	}

	template<typename T>
	Random<T>::Random(const T min, const T max) : gen(std::random_device{}()), dist(min, max) {}
}
