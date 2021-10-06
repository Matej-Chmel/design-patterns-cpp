#include <algorithm>
#include <iostream>
#include "LowerCaseStyler.hpp"

namespace mch {
	void LowerCaseStyler::print() {
		std::cout << "LowerCase: " << this->content << '\n';
	}

	LowerCaseStyler::~LowerCaseStyler() {
		this->text->detach(this);
	}

	void LowerCaseStyler::eraseChar() {
		if(this->content.empty())
			return;
		this->text->setContent(this->content.substr(0, this->content.size() - 1));
	}

	LowerCaseStyler::LowerCaseStyler(RandomText* t) {
		this->setText(t);
	}

	void LowerCaseStyler::reset() {
		this->text = nullptr;
	}

	void LowerCaseStyler::setText(RandomText* t) {
		this->text = t;
		this->text->attach(this);
		this->update();
	}

	void LowerCaseStyler::update() {
		this->content = this->text->content();
		std::transform(this->content.begin(), this->content.end(), this->content.begin(), [](char c) {
			return tolower(c);
		});
		this->print();
	}
}
