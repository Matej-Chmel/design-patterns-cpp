#include <iostream>
#include "TextView.hpp"

namespace mch {
	void TextView::print() {
		std::cout << this->label << ": " << this->content() << '\n';
	}

	TextView::iterator TextView::begin() {
		return this->_content.begin();
	}

	TextView::iterator TextView::end() {
		return this->_content.end();
	}

	const std::string& TextView::content() {
		return this->_content;
	}

	void TextView::notify() {
		Subject::notify();
		this->print();
	}

	void TextView::setContent(const std::string& content) {
		this->_content = content;
		this->notify();
	}

	TextView::TextView(const std::string& label, const std::string& content) : _content(content), label(label) {}
	TextView::TextView(const std::string& label, const size_t len, const char c) : _content(len, c), label(label) {}
}
