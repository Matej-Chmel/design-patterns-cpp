#pragma once
#include <string>
#include "Subject.hpp"

namespace mch {
	class TextView : public Subject<TextView> {
		std::string _content;
		std::string label;

		void print();

	protected:
		typedef std::string::iterator iterator;

		iterator begin();
		iterator end();

	public:
		std::string contentCopy();
		const std::string& contentRef();
		bool empty();
		void notify() override;
		void setContent(const std::string& content);
		TextView(const std::string& label, const std::string& content);
		TextView(const std::string& label, const size_t len, const char c);
	};
}
