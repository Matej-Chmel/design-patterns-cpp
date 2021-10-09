#include <iostream>
#include "Console.hpp"

namespace mch {
	Console::Console() : _running(true) {
		this->setColor(7);
	}

	void Console::waitForEnter() {
		std::cin.get();
		this->_running = false;
	}

	void Console::print(const std::string& label, const std::string& s) {
		std::cout << label << ": " << s << '\n';
	}

	const std::atomic<bool>& Console::running() {
		return this->_running;
	}

	void Console::runUntilEnter(std::vector<std::thread>& workers) {
		this->inputThread = std::thread(&Console::waitForEnter, this);
		this->inputThread.join();

		for(auto& w : workers)
			w.join();
	}

	void Console::setColor(const WORD color) {
		this->color = color;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
}
