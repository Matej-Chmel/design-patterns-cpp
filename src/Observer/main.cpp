#include "RandomTextView.hpp"
#include "refresh.hpp"
#include "Transformer.hpp"
using namespace std::chrono_literals;

constexpr size_t ADDED_LEN = 50;
constexpr size_t MIN_LEN = 30;
constexpr auto REFRESH_RATE = 25ms;

int main() {
	mch::RandomTextView src("SourceStr", MIN_LEN);
	mch::Transformer lowerTr("LowerCase", &src, tolower), upperTr("UpperCase", &src, toupper);

	mch::refresh([&]() {
		static size_t i = 0;
		static auto nowUpper = true;

		if(i >= ADDED_LEN) {
			i = 0;
			nowUpper = !nowUpper;
			src.randomize();
			return;
		}
		i++;

		if(nowUpper)
			upperTr.addRndChar();
		else
			lowerTr.eraseRndChar();
	}, REFRESH_RATE);

	return 0;
}
