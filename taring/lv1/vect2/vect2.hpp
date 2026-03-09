#pragma once

#include <iostream>

class vect2
{
	private: 
		int x, y;
	public:
		vect2() : x(0), y(0) {};
		vect2(int x, int y) : x(x), y(y) {};
		vect2(const vect2 &other) : x(other.x), y(other.y) {};
		vect2 &operator=(const vect2 &other)
		{
			if (this != &other)
			{
				x = other.x;
				y = other.y;
			}
			return *this;
		}
		int &operator[](int i)
		{
			return (i == 0 ? x : y);
		}
		int operator[](int i) const
		{
			return (i == 0 ? x : y);
		}
		vect2 operator+(const vect2 &other) const
		{
			return vect2(x + other.x, y + other.y);
		}
		vect2 operator-(const vect2 &other) const
		{
			return vect2(x - other.x, y - other.y);
		}
		vect2 operator*(int n) const
		{
			return vect2(x * n, y * n);
		}
		vect2 &operator+=(const vect2 &other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		vect2 &operator-=(const vect2 &other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
		vect2 &operator*=(int n)
		{
			x *= n;
			y *= n;
			return *this;
		}
		vect2 &operator++()
		{
			x++;
			y++;
			return *this;
		}
		vect2 operator++(int)
		{
			vect2 tmp(*this);
			x++;
			y++;
			return tmp;
		}
		vect2 &operator--()
		{
			x--;
			y--;
			return *this;
		}
		vect2 operator--(int)
		{
			vect2 tmp(*this);
			x--;
			y--;
			return tmp;
		}
		vect2 &operator-()
		{
			-x;
			-y;
			return *this;
		}
		bool operator==(const vect2 &other)
		{
			return (x == other.x && y == other.y);
		}
		bool operator!=(const vect2 &other)
		{
			return (x != other.x || y != other.y);
		}
		friend vect2 operator*(int n, const vect2 &other)
		{
			return vect2(n * other.x, n * other.y);
		}
		friend std::ostream &operator<<(std::ostream &os, const vect2 &other)
		{
			os << "{" << other.x << ", " << other.y << "}";
			return os;
		}
};