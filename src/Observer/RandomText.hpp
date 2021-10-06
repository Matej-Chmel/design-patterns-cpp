#pragma once
#include <string>
#include "Subject.hpp"

namespace mch {
	class RandomText : public Subject {
		std::string _content;

		void _randomize();
		void print();

	public:
		std::string content();
		void notify() override;
		void randomize();
		RandomText(const size_t len);
		void setContent(const std::string& c);
	};
}
