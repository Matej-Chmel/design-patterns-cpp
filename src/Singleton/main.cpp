#include <chrono>
#include <iostream>
#include <vector>
#include "Console.hpp"
namespace chrono = std::chrono;
using namespace std::chrono_literals;

struct WorkerAttrs {
	const WORD color;
	const chrono::milliseconds refreshRate;
};

const std::vector<WorkerAttrs> ATTRS{
	{9, 1000ms},
	{10, 1002ms},
	{12, 1004ms},
	{14, 1006ms}};

static void worker(const size_t i, const WorkerAttrs& attrs) {
	auto& console = mch::Console::instance();
	const auto label = "Thread " + std::to_string(i);
	const auto start = chrono::system_clock::now();

	while(console.running()) {
		const auto elapsed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count();
		console.transaction([&](mch::Console& c) {
			c.setColor(attrs.color);
			c.print(label, std::to_string(elapsed) + " ms");
		});
		std::this_thread::sleep_for(attrs.refreshRate);
	}
}

int main() {
	const auto len = ATTRS.size();
	std::vector<std::thread> workers;
	workers.reserve(len);

	for(size_t i = 0; i < len; i++)
		workers.emplace_back(worker, i, ATTRS[i]);

	mch::Console::instance().waitForEnter();

	for(auto& w : workers)
		w.join();

	return 0;
}
