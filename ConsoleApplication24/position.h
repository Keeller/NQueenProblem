#pragma once
class position
{
private:
	int x;
	int y;
public:
	position(int x, int y);
	~position();
	int get_x() const
	{
		return x;
	}
	void set_x(int x)
	{
		this->x = x;
	}
	void set_y(int y)
	{
		this->y = y;
	}
	bool operator ==(const position& pos)
	{
		return (((this->x == pos.get_x()) && (this->y == pos.get_y())) ? true : false);
	}
	int get_y() const
	{
		return y;
	}
};

