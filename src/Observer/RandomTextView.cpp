#include <random>
#include "RandomTextView.hpp"

namespace mch {
	void RandomTextView::_randomize() {
		for(auto& c : *this)
			c = this->r.next();
	}

	void RandomTextView::randomize() {
		this->_randomize();
		this->notify();
	}

	RandomTextView::RandomTextView(const std::string& label, const size_t len) : TextView(label, len, ' '), r('A', 'z') {
		this->_randomize();
	}
}
