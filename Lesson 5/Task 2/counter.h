#pragma once

class Counter {
	private:
		int number;
	public:
		Counter();
		Counter(int);
		void increase();
		void decrease();
		int get() const;
};