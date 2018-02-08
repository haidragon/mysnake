#ifndef POINT_H
#define POINT_H

class AllenPoint
{
public:
	AllenPoint() {}
	AllenPoint(const int x, const int y) : x(x), y(y) {}
	void Print();
	void PrintCircular();
	void Clear();
	void ChangePosition(const int x, const int y);
	bool operator== (const AllenPoint& point) { return (point.x == this->x) && (point.y == this->y); }
	int GetX() { return this->x; }
	int GetY() { return this->y; }
private:
	int x, y;
};
#endif // POINT_H
