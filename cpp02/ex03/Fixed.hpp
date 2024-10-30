#ifndef FIXED
# define FIXED

#include <iostream>
#include<cmath>

/* Fixed point numbers present some advantages in comparison with
floats.

Fixed point numbers -> More controllable precision, since we decide
the number of fractional bits (precision in floats is almost unpredictable)

Devices without FPU (Floating-point unit) -> Fixed point operations are
much faster and efficient.

Game engines -> Sometimes used fixed point numbers for efficiency, since
efficiency is much more important than precision.
*/
class Fixed {
	private:
		int _value;
		static const int _fracBits = 8;

	public:
		Fixed();
		Fixed(Fixed const &number);
		Fixed(int const intValue);
		Fixed(float const floatValue);
		Fixed &operator=(Fixed const &otherNumber);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void)const;
		int toInt(void) const;
		//friend da acesso aos atributos privados da classe.
		//Neste caso, operator<< nao pode fazer parte da classe,
		//por causa da sua signature, mas tem de ser friend
		//para conseguir ter acessoaos atributos privados.
		friend std::ostream& operator<<(std::ostream& osb, const Fixed& number);

		bool operator>(Fixed const otherNumber) const;
		bool operator<(Fixed const otherNumber)const;
		bool operator>=(Fixed const otherNumber)const;
		bool operator<=(Fixed const otherNumber)const;
		bool operator==(Fixed const otherNumber)const;
		bool operator!=(Fixed const otherNumber)const;

		Fixed operator+(Fixed const otherNumber) const;
		Fixed operator-(Fixed const otherNumber) const;
		Fixed operator*(Fixed const otherNumber) const;
		Fixed operator/(Fixed const otherNumber) const;

		//pre-incremento
		Fixed& operator++(void);

		//pos-incremento
		Fixed operator++(int);

		//pre-incremento
		Fixed& operator--(void);

		//pos-decremento
		Fixed operator--(int);


		static Fixed &min(Fixed &number1, Fixed &number2);
		static Fixed &min(Fixed const &number1, Fixed const &number2);
		static Fixed &max(Fixed &number1, Fixed &number2);
		static Fixed &max(Fixed const &number1, Fixed const &number2);

		static Fixed &absFixed(Fixed &number);
};

# endif
