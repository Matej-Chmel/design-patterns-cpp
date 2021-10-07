#pragma once
#include <unordered_set>
#include "Observer.hpp"

namespace mch {
	template<class D>
	class Subject {
		std::unordered_set<Observer<D>*> observers;

	protected:
		Subject() = default;

	public:
		void attach(Observer<D>* o);
		void detach(Observer<D>* o);
		virtual void notify();
	};

	template<class D>
	void Subject<D>::attach(Observer<D>* o) {
		this->observers.insert(o);
	}

	template<class D>
	void Subject<D>::detach(Observer<D>* o) {
		this->observers.erase(o);
	}

	template<class D>
	void Subject<D>::notify() {
		for(const auto& o : this->observers)
			o->update();
	}
}
