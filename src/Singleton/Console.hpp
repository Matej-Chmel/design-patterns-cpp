#pragma once
#include <atomic>
#include <functional>
#include <mutex>
#include <string>
#include <thread>
#include <Windows.h>
#include "Singleton.hpp"

namespace mch {
	class Console : public Singleton<Console> {
		static inline std::mutex mutex;

		std::atomic<bool> _running;
		WORD color;
		std::thread inputThread;

		void _waitForEnter();

	public:
		static Console& instance();

		Console();
		void print(const std::string& label, const std::string& s);
		void reset();
		const std::atomic<bool>& running();
		void setColor(const WORD color);
		void transaction(const std::function<void(Console&)> f);
		void waitForEnter();
	};
}
