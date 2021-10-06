#pragma once
#include <atomic>
#include <functional>
#include <iostream>
#include <thread>

namespace mch {
	template <class R, class P>
	void refresh(std::function<void()> f, std::chrono::duration<R, P> d);

	template <class R, class P>
	void refresh(std::function<void()> f, std::chrono::duration<R, P> d) {
		std::atomic<bool> running = true;
		std::thread terminal([&]() {
			std::cin.get();
			running = false;
		});

		while(running) {
			f();
			std::this_thread::sleep_for(d);
		}
		terminal.join();
	}
}
