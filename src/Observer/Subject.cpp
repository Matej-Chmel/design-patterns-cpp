#include "Subject.hpp"

namespace mch {
	Subject::~Subject() {
		for(const auto& o : this->observers)
			o->reset();
	}

	void Subject::attach(Observer* o) {
		this->observers.insert(o);
	}

	void Subject::detach(Observer* o) {
		this->observers.erase(o);
	}

	void Subject::notify() {
		for(const auto& o : this->observers)
			o->update();
	}
}
