#pragma once

template<class Tag, class HolderType = int>
class Unit
{
public:
	explicit Unit(HolderType value) 
		: m_value(value)
	{}

	HolderType value() const { return m_value; }

	bool operator==(const Unit &rhs) const { return m_value == rhs.m_value; }
	Unit &operator-=(const Unit &rhs) { m_value -= rhs.m_value; return *this; }
	Unit &operator+=(const Unit &rhs) { m_value += rhs.m_value; return *this; }

	bool operator<(const Unit &rhs) const { return m_value < rhs.m_value; }
	bool operator>(const Unit &rhs) const { return m_value > rhs.m_value; }

	template<class IntegerType>
	friend Unit operator*(IntegerType lhs, const Unit &rhs) { return Unit(rhs.m_value * lhs); }
	template<class IntegerType>
	friend Unit operator*(const Unit &lhs, IntegerType rhs) { return Unit(lhs.m_value * rhs); }



private:
	HolderType m_value;
};

