#pragma once
struct point {
	double x;
	double y;
	point operator + (point SecPoi) {
		return { x + SecPoi.x, y + SecPoi.y };
	}
	point operator - (point SecPoi) {
		return { x - SecPoi.x, y - SecPoi.y };
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
		std::cout << "(" << x << "; " << y << ")\n";
	}
	point operator * (double k) {
		return { x * k,y * k };
	}
	double distance() {
		return sqrt(x * x + y * y);
	}

	friend std::ostream& operator << (std::ostream& out_stream, const point& A) {
		out_stream << "(" << A.x << "; " << A.y << ")";
		return out_stream;
	}
	friend std::istream& operator >> (std::istream& in_stream, point& A) {
		in_stream >> A.x >> A.y;
		return in_stream;
	}
};
