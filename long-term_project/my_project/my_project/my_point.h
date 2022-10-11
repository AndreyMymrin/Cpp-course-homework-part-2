#pragma once
struct point {
	double x;
	double y;
	point operator + (point SecPoi) {
		return { this->x + SecPoi.x, this->y + SecPoi.y };
	}
	point operator - (point SecPoi) {
		return { this->x - SecPoi.x, this->y - SecPoi.y };
	}
	point operator += (point SecPoi) {
		*this = *this + SecPoi;
		return *this;
	}
	point operator -= (point SecPoi) {
		*this = *this - SecPoi;
		return *this;
	}
	void  print() {
		std::cout << "(" << this->x << "; " << this->y << ")\n";
	}

};
