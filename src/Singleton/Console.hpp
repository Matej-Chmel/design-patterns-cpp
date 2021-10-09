#pragma once
#include <atomic>
#include <functional>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <Windows.h>
#include "Singleton.hpp"

namespace mch {
	class Console : public Singleton<Console> {
		friend Singleton;

		static inline std::mutex mutex;

		std::atomic<bool> _running;
		WORD color;
		std::thread inputThread;

		Console();
		void waitForEnter();

	public:
		static Console& instance();

		void print(const std::string& label, const std::string& s);
		const std::atomic<bool>& running();
		void runUntilEnter(std::vector<std::thread>& workers);
		void setColor(const WORD color);
		void transaction(const std::function<void(Console&)> f);
	};
}
