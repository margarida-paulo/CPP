#include <iostream>

class Fixed {
	private:
		int _value;
		static const int bits = 8;

		public:
			Fixed();
			Fixed(Fixed const &number);
			Fixed &operator=(Fixed const &otherNumber);
			~Fixed();
			int getRawBits(void) const;
			void setRawBits(int const raw);
};
