#pragma once
#include <functional>
#include "Observer.hpp"
#include "Random.hpp"
#include "TextView.hpp"

namespace mch {
	typedef const std::function<char(const char)> TransformerFun;

	class Transformer : public Observer<TextView>, public TextView {
		TransformerFun f;
		Random<char> r;

	public:
		~Transformer();
		void addRndChar();
		void eraseRndChar();
		Transformer(const std::string& label, TextView* const s, TransformerFun f);
		void update() override;
	};
}
