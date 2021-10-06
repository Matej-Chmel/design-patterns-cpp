#pragma once
#include "RandomText.hpp"

namespace mch {
	class UpperCaseStyler : public Observer {
		std::string content;
		RandomText* text;

		void print();

	public:
		~UpperCaseStyler();
		void addRndChar();
		void reset() override;
		void setText(RandomText* t);
		void update() override;
		UpperCaseStyler(RandomText* t);
	};
}
