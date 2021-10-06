#include <iostream>
#include <random>
#include "RandomText.hpp"

namespace mch {
	void RandomText::_randomize() {
		static std::default_random_engine gen(std::random_device{}());
		static std::uniform_int_distribution<int> dist(65, 122);

		for(auto& c : this->_content)
			c = dist(gen);
	}

	void RandomText::print() {
		std::cout << this->_content << '\n';
	}

	std::string RandomText::content() {
		return this->_content;
	}

	void RandomText::notify() {
		Subject::notify();
		this->print();
	}

	void RandomText::randomize() {
		this->_randomize();
		this->notify();
	}

	RandomText::RandomText(const size_t len) : _content(len, ' ') {
		this->_randomize();
	}

	void RandomText::setContent(const std::string& c) {
		this->_content = c;
		this->notify();
	}
}
