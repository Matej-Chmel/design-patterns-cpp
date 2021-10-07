#include <algorithm>
#include "Transformer.hpp"

namespace mch {
	Transformer::~Transformer() {
		this->subject->detach(this);
	}

	void Transformer::addRndChar() {
		this->subject->setContent(this->contentRef() + this->f(this->r.next()));
	}

	void Transformer::eraseRndChar() {
		if(this->subject->empty())
			return;

		auto copy = this->subject->contentCopy();
		copy.erase(Random<size_t>(0, copy.size()).next(), 1);
		this->subject->setContent(copy);
	}

	Transformer::Transformer(const std::string& label, TextView* const s, TransformerFun f) :
		Observer(s), TextView(label, s->contentRef()), f(f), r('a', 'z') {

		this->subject->attach(this);
	}

	void Transformer::update() {
		auto copy = this->subject->contentCopy();
		std::transform(copy.begin(), copy.end(), copy.begin(), this->f);
		this->setContent(copy);
	}
}
