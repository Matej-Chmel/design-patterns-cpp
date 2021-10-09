#pragma once
#include <atomic>
#include <string>
#include <thread>
#include <vector>
#include <Windows.h>
#include "SyncSingleton.hpp"

namespace mch {
	class Console : public SyncSingleton<Console> {
		friend Singleton;

		std::atomic<bool> _running;
		WORD color;
		std::thread inputThread;

		Console();
		void waitForEnter();

	public:
		void print(const std::string& label, const std::string& s);
		const std::atomic<bool>& running();
		void runUntilEnter(std::vector<std::thread>& workers);
		void setColor(const WORD color);
	};
}
