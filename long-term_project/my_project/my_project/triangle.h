#pragma once
#include <cmath>
struct point {
	int x, y;
};

class triangle
{
	point vertex_first;
	point vertex_second;
	point vertex_third;

public:
	double square();
	double perimeter();
	void new_vertexes(point v1, point v2, point v3);
};

