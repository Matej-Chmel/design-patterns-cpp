#pragma once

namespace mch {
	template<class S>
	class Observer {
	protected:
		S* subject;

		Observer(S* const s);

	public:
		virtual void update() = 0;
	};

	template<class S>
	Observer<S>::Observer(S* const s) : subject(s) {}
}
