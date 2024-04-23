#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include "MojVektor.hpp"
#include "Rational.hpp"

class Polinom
{
private:
	MojVektor<Rational> koef_;
	friend std::ostream& operator<<(std::ostream&, const Polinom&);
	friend std::istream& operator>>(std::istream&, Polinom&);
public:
	Polinom() = default;
	Polinom(const Polinom&);
	Polinom(Polinom&&);
	Polinom(const std::initializer_list<Rational>&);
	Polinom(const MojVektor<Rational>&);
	Polinom(MojVektor<Rational>&&);
	Polinom(const std::vector<Rational>&);

	Polinom& operator=(const Polinom&);
	Polinom& operator=(Polinom&&);

	Polinom& push_back(const Rational&);
	Polinom& push_back(Rational&&);

	Polinom operator+(const Polinom&) const;
	Polinom operator-(const Polinom&) const;
	Polinom operator*(const Polinom&) const;

	Rational operator()(const Rational&) const;
	
	Polinom izvod() const;


	size_t size() const {
		return koef_.size();
	}

	void resize(size_t);

	MojVektor<Rational> getKoef() const { return koef_; };
};


