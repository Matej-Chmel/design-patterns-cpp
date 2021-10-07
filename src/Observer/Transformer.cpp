#include <algorithm>
#include "Transformer.hpp"

namespace mch {
	Transformer::~Transformer() {
		this->subject->detach(this);
	}

	void Transformer::addRndChar() {
		this->subject->setContent(this->content() + this->f(this->r.next()));
	}

	void Transformer::eraseRndChar() {
		auto& ref = this->content();

		if(ref.empty())
			return;

		std::string copy(ref);
		copy.erase(Random<size_t>(0, copy.size()).next(), 1);
		this->subject->setContent(copy);
	}

	Transformer::Transformer(const std::string& label, TextView* const s, TransformerFun f) :
		Observer(s), TextView(label, s->content()), f(f), r('a', 'z') {

		this->subject->attach(this);
	}

	void Transformer::update() {
		std::string copy(this->subject->content());
		std::transform(copy.begin(), copy.end(), copy.begin(), this->f);
		this->setContent(copy);
	}
}
