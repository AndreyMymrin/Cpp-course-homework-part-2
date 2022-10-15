#include "figures.h"

double geometric_shapes::oblique_multiplication(point p_1, point p_2, point p_3)
{
	return (p_2 - p_1).x * (p_3 - p_1).y - (p_2 - p_1).y * (p_3 - p_1).x;
}
bool geometric_shapes::is_cross(point p_1, point p_2, point p_3, point p_4)
{
	if (oblique_multiplication(p_1, p_2, p_3) * oblique_multiplication(p_1, p_2, p_4) >= 0 &&
		oblique_multiplication(p_3, p_4, p_1) * oblique_multiplication(p_3, p_4, p_2) >= 0)
		return 1;
	else return 0;
}