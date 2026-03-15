#pragma once

#include <iostream>
#include <string> 
#include <stdexcept>

class bigint
{
	private :
		std::string value;
		std::string AddStrings(const std::string &a, const std::string &b) const
		{
			unsigned long sum = std::strtoul(a.c_str(), NULL, 10) + std::strtoul(b.c_str(), NULL, 10);
			return (std::to_string(sum));
		}
		void RemoveLeadingZeros()
		{
			while (value.size() > 1 && value[0] == '0')
				value.erase(0, 1);
		}
		unsigned long long stringToULL(const std::string &str) const
		{
			char *end = NULL;
			unsigned long long rez = std::strtoull(str.c_str(), &end, 0);
			if (*end != '\0' || str[0] == '-')
				throw std::invalid_argument("Invalid number format");
			return rez;
		}
	public :
		bigint() : value("0") {};
		bigint(unsigned long long val) : value(std::to_string(val)) {};
		bigint(const std::string &str) : value(str) {RemoveLeadingZeros();};
		bigint(const bigint &other) : value(other.value) {};

		bigint &operator=(const bigint &other)
		{
			if (this != &other)
				value = other.value;
			return *this;
		}

		bigint operator<<(int shift) const
		{
			if (shift <= 0)
				return *this;
			return bigint(value + std::string(shift, '0'));
		}
		bigint &operator<<=(int shift)
		{
			if (shift <= 0)
				return *this;
			value = value + std::string(shift, '0');
			return *this;
		}
		bigint operator>>(int shift) const
		{
			if (shift <= 0 || (int)value.size() <= shift)
			{
				return bigint("0");
			}
			return bigint(value.substr(0, value.size() - shift));
		}
		bigint &operator>>=(int shift)
		{
			if (shift <= 0 || shift >= value.size())
			{
				value = "0";
				return *this;
			}
			value = value.substr(0, value.size() - shift);
			return *this;
		}
		bigint operator<<(const bigint &other) const
		{
			return *this << stringToULL(other.value);
		}
		bigint operator>>(const bigint &other) const
		{
			return *this >> stringToULL(other.value);
		}
		bigint &operator>>=(const bigint &other)
		{
			return *this >>= stringToULL(other.value);
		}
		bigint &operator<<=(const bigint &other)
		{
			return *this <<= stringToULL(other.value);
		}

		bigint operator+(const bigint &other) const
		{
			return bigint(AddStrings(value, other.value));
		}
		bigint operator+(unsigned long long val) const
		{
			return bigint(AddStrings(value, std::to_string(val)));
		}
		bigint &operator+=(const bigint &other)
		{
			value = AddStrings(value, other.value);
			return *this;
		}
		bigint &operator+=(unsigned long long val)
		{
			value = AddStrings(value, std::to_string(val));
			return *this;
		}
		bigint &operator++()
		{
			*this += 1;
			return *this;
		}
		bigint operator++(int)
		{
			bigint tmp(*this);
			*this += 1;
			return tmp;
		}

		bool operator<(const bigint &other) const
		{
			if (value.size() != other.value.size())
				return (value.size() < other.value.size());
			return (value < other.value);
		}
		bool operator>(const bigint &other) const
		{
			if (value.size() != other.value.size())
				return (value.size() > other.value.size());
			return (value > other.value);
		}
		bool operator<=(const bigint &other) const
		{
			return !(*this > other);
		}
		bool operator>=(const bigint &other) const
		{
			return !(*this < other);
		}
		bool operator==(const bigint &other) const
		{
			return (value == other.value);
		}
		bool operator!=(const bigint &other) const
		{
			return (value != other.value);
		}

		friend std::ostream &operator<<(std::ostream &os, const bigint &other)
		{
			os << other.value;
			return os;
		}
};