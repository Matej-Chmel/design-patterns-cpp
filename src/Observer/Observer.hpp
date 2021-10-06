#pragma once

namespace mch {
	class Observer {
	public:
		virtual void reset() = 0;
		virtual void update() = 0;
	};
}
