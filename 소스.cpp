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
	friend Point operator*(int times, Point& ref);	//��� �Լ� ���Ƿδ� �ڵ����� �����Ͱ� ù ��°�� ���ȴ�. ���� friend ������ �ؾ� �Ѵ�.
};

Point operator*(int times, Point& ref) { return ref * times; }	//ù ��°�� �����ߴ� operator�� ����Ͽ� ����

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