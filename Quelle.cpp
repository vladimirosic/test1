#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <initializer_list>

class Point
{
private:
	float mX, mY;
public:
	Point() :
		mX{ 0 },
		mY{ 0 }
	{}
	Point(float x, float y) :
		mX{ x },
		mY{ y }
	{}
	Point(Point const& p) :
		mX{ p.mX },
		mY{ p.mY }
	{}
	Point& operator=(Point const& rhs) {
		mX = rhs.mX;
		mY = rhs.mY;
		return *this;
	}
	float x() const
	{
		return mX;
	}
	float y() const
	{
		return mY;
	}
	void set_x( float xx) 
	{
		 mX = xx;
	}
	void set_y(float yy) 
	{
		mY = yy;
	}
	friend std::ostream&
		operator<<(std::ostream& os, Point const& p) {
		return os << "x = " << p.mX << " y = " << p.mY;
	}
};
class Kurve : public Point {
public:
	std::vector<Point> kur;
	

public:
	Kurve( std::initializer_list<Point> liste) : kur{ liste } {}
	Kurve( Point p)  {
		kur.push_back(p);
	}

	std::vector<Point>& get_kur() {
		return kur;
	}
};


class Segment
{
private:
	Point mA, mB;
public:
	Segment(Point A, Point B) :
		mA{ A }, mB{ B }
	{}
	float A() const		// Coefficient A: y = Ax + B
	{
		return (mA.y() - mB.y()) / (mA.x() - mB.x());
		// source: https://calculis.net/droite
					// A completer
	}
	float B() const		// Coefficient B: y = Ax + B
	{
		return mA.y() - A() * mA.x();
		// source: https://calculis.net/droite
					// A completer
	}
	Point intersection(Segment const& other)
	{
		float x = (other.B() - B()) / (A() - other.A());
					// source: https://calculis.net/intersection
					// A completer
		
					// A completer
		return Point{x , A() * x + B()};
	}
	std::string equation() const
	{
		return "y = " + std::to_string(A()) + "x + " + std::to_string(B());
	}
};
int main() {
	Point pA(0, 0);
	Point pB(2, pow(2, 2));
	

	Kurve parabole({ 0,0 });
	for (float i = 0; i < 100; i++)
		 parabole.kur.push_back({ i * 0.1f,pow(i * 0.1f,2.0f) });
	
	


	
	auto it = parabole.kur.begin();
	while (it != parabole.kur.end()) {
		std::cout << *it++ << std::endl;

	}

	Kurve hiperbole({ 0,0 });
	for (float i = 0; i < 100; i++)
		hiperbole.kur.push_back({ i * 0.1f,pow(i * 0.1f,.5f) });





	auto it_h = hiperbole.kur.begin();
	while (it_h!= hiperbole.kur.end()) {
		std::cout << *it_h++ << std::endl;

	}

	
	Point A(3.5f, 4.0f);
	Point B(-4.0f, 2.0f);
	Point C(2.0f, -2.0f);
	Point D(-2.0f, 5.0f);

	Segment Line1(A, B);
	std::cout << Line1.equation() << std::endl;
	Segment Line2(C, D);
	std::cout << Line2.equation() << std::endl;

	std::cout << Line1.intersection(Line2);	// Point d'intersection des deux lignes droites	
}