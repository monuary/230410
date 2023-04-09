#include<iostream>
using namespace std;

class Point
{
	int xpos, ypos;
public:
	Point(int x=0,int y=0):xpos(x),ypos(y){}
	void Show()const { cout << "[" << xpos << ", " << ypos << "]" << endl; }
	Point operator*(int times)
	{
		Point pos(xpos * times, ypos * times);
		return pos;
	}
	friend Point operator*(int times, Point& ref);	//멤버 함수 정의로는 자동으로 포인터가 첫 번째로 사용된다. 따라서 friend 선언을 해야 한다.
};

Point operator*(int times, Point& ref) { return ref * times; }	//첫 번째로 정의했던 operator를 사용하여 정의

int main()
{
	Point pos(1, 2);
	pos.Show();
	Point cpy = pos * 3;
	cpy.Show();
	cpy = 2 * pos * 3;
	cpy.Show();
	return 0;
}