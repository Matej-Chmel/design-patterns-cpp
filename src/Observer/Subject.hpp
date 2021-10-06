#pragma once
#include <unordered_set>
#include "Observer.hpp"

namespace mch {
	class Subject {
		std::unordered_set<Observer*> observers;

	protected:
		Subject() = default;

	public:
		~Subject();
		void attach(Observer* o);
		void detach(Observer* o);
		virtual void notify();
	};
}
