#include <algorithm>
#include <iostream>
#include <random>
#include "UpperCaseStyler.hpp"

namespace mch {
	void UpperCaseStyler::print() {
		std::cout << "UpperCase: " << this->content << '\n';
	}

	UpperCaseStyler::~UpperCaseStyler() {
		this->text->detach(this);
	}

	void UpperCaseStyler::addRndChar() {
		static std::default_random_engine gen(std::random_device{}());
		static std::uniform_int_distribution<int> dist(65, 122);

		this->text->setContent(this->content + char(dist(gen)));
	}

	void UpperCaseStyler::reset() {
		this->text = nullptr;
	}

	void UpperCaseStyler::setText(RandomText* t) {
		this->text = t;
		this->text->attach(this);
		this->update();
	}

	void UpperCaseStyler::update() {
		this->content = this->text->content();
		std::transform(this->content.begin(), this->content.end(), this->content.begin(), [](char c) {
			return toupper(c);
		});
		this->print();
	}

	UpperCaseStyler::UpperCaseStyler(RandomText* t) {
		this->setText(t);
	}
}
