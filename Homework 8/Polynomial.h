#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

namespace Polynomials {
	struct Node;

	class Polynomial {
		friend std::ostream& operator<<(std::ostream& os, const Polynomial& expression);
		friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);

	public:
		Polynomial();

		Polynomial(const std::vector<int>& values);

		Polynomial(const Polynomial& rhs);

		virtual ~Polynomial();

		Polynomial& operator=(const Polynomial& rhs);

		Polynomial& operator+=(const Polynomial& rhs);

		int evaluate(int x) const;

	private:
		Node* coefficient;
		int degree;
	};

	Polynomial operator+(const Polynomial& first, const Polynomial& second);

	bool operator!=(const Polynomial& lhs, const Polynomial& rhs);

}
#endif