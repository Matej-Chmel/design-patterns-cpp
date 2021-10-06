#include "LowerCaseStyler.hpp"
#include "RandomText.hpp"
#include "refresh.hpp"
#include "UpperCaseStyler.hpp"
using namespace std::chrono_literals;

constexpr size_t ADDED_CHARS = 50;
constexpr auto DURATION = 25ms;
constexpr size_t TEXT_MIN_LEN = 30;

int main() {
	mch::RandomText text(TEXT_MIN_LEN);
	mch::LowerCaseStyler lowerStyler(&text);
	mch::UpperCaseStyler upperStyler(&text);

	mch::refresh([&]() {
		static size_t i = 0;
		static auto nowUpper = true;

		if(i >= ADDED_CHARS) {
			i = 0;
			nowUpper = !nowUpper;
			text.randomize();
			return;
		}
		i++;

		if(nowUpper)
			upperStyler.addRndChar();
		else
			lowerStyler.eraseChar();
	}, DURATION);

	return 0;
}
