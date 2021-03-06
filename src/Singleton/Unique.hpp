#pragma once

namespace mch {
	class Unique {
	protected:
		Unique() = default;

	public:
		Unique& operator=(const Unique&) = delete;
		Unique& operator=(Unique&&) = delete;
		Unique(const Unique&) = delete;
		Unique(Unique&&) = delete;
	};
}
