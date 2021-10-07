#include <iostream>
#include "TextView.hpp"

namespace mch {
	void TextView::print() {
		std::cout << this->label << ": " << this->contentRef() << '\n';
	}

	TextView::iterator TextView::begin() {
		return this->_content.begin();
	}

	TextView::iterator TextView::end() {
		return this->_content.end();
	}

	std::string TextView::contentCopy() {
		return this->_content;
	}

	const std::string& TextView::contentRef() {
		return this->_content;
	}

	bool TextView::empty() {
		return this->contentRef().empty();
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
