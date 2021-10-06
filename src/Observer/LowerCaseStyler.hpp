#pragma once
#include "RandomText.hpp"

namespace mch {
	class LowerCaseStyler : public Observer {
		std::string content;
		RandomText* text;

		void print();

	public:
		~LowerCaseStyler();
		void eraseChar();
		LowerCaseStyler(RandomText* t);
		void reset() override;
		void setText(RandomText* t);
		void update() override;
	};
}
