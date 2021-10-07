#pragma once
#include "Random.hpp"
#include "TextView.hpp"

namespace mch {
	class RandomTextView : public TextView {
		Random<char> r;

		void _randomize();

	public:
		void randomize();
		RandomTextView(const std::string& label, const size_t len);
	};
}
