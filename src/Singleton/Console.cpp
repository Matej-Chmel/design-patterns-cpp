#include <iostream>
#include "Console.hpp"

namespace mch {
	void Console::_waitForEnter() {
		std::cin.get();
		this->_running = false;
	}

	Console& Console::instance() {
		std::unique_lock _(mutex);
		return Singleton::instance();
	}

	Console::Console() : _running(true) {
		this->setColor(7);
	}

	void Console::print(const std::string& label, const std::string& s) {
		std::cout << label << ": " << s << '\n';
	}

	void Console::reset() {
		this->_running = true;
	}

	const std::atomic<bool>& Console::running() {
		return this->_running;
	}

	void Console::setColor(const WORD color) {
		this->color = color;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}

	void Console::transaction(const std::function<void(Console&)> f) {
		std::unique_lock _(mutex);
		f(*this);
	}

	void Console::waitForEnter() {
		this->inputThread = std::thread(&Console::_waitForEnter, this);
		this->inputThread.join();
	}
}
