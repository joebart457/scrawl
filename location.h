#pragma once


class location {
public:
	location()
		:_x{ 0 }, _y{ 0 }{}
	location(unsigned int x, unsigned int y)
		:_x{ x }, _y{ y }{}
	~location() {}


	unsigned int x() const { return _x; }
	unsigned int y() const { return _y; }

private:
	unsigned int _x{ 0 };
	unsigned int _y{ 0 };
};