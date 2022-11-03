#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include "my_point.h"

namespace geometric_shapes {

	class triangle;
	class circle;
	class square;
	
	double oblique_multiplication(point p_1, point p_2, point p_3);
	bool is_cross(point p_1, point p_2, point p_3, point p_4);

	class shapes 
	{

	public:
		virtual double area() = 0;
		virtual double perimeter() = 0;
		virtual bool is_point_inside(point p_t) = 0;
		virtual void move(point rad_vec) = 0;
		virtual bool is_intersection(square& sq) { return 0; };
		virtual bool is_intersection(circle& sq) { return 0; };
		virtual bool is_intersection(triangle& sq) { return 0; };
		virtual std::vector<point> take_vertexes() { return {}; };
	};

	class triangle: public virtual shapes
	{
	private:
		point vertex_first;
		point vertex_second;
		point vertex_third;
	public:
		
		triangle(point v1, point v2, point v3) : 
			vertex_first(v1), vertex_second(v2), vertex_third(v3){
			if (area() == 0) {
				std::cout << "Something wrong in triangle's vertexes\n";
			}
		}
		std::vector<point> take_vertexes();
		double area();
		double perimeter();
		bool is_point_inside(point p_t);
		void move(point rad_vec);

		bool is_intersection(square& sq);
		bool is_intersection(triangle& tr);
		bool is_intersection(circle& circ);

		friend std::ostream& operator << (std::ostream& out_stream, triangle& tr) {

			std::vector<point> TrianPointsVector = tr.take_vertexes();
			for (auto i : TrianPointsVector) {
				out_stream << i << " ";
			}
			return out_stream;
		}
		friend std::istream& operator >> (std::istream& in_stream, triangle& tr) {
			in_stream >> tr.vertex_first >> tr.vertex_second >> tr.vertex_third;
			return in_stream;
		}
	};

	class circle: public virtual shapes
	{
	private:
		point centre_point;
		int radius;
	public:

		circle(point centre, int R) : centre_point(centre), radius(R) {
			if (radius == 0)
				std::cout << "Radius equals zero! ERROR\n";
		}
		double area();
		double perimeter();
		bool is_point_inside(point p_t);
		void move(point rad_vec);
		point central_point();

		bool is_intersection(square& sq);
		bool is_intersection(triangle& tr);
		bool is_intersection(circle& circ);

		friend std::ostream& operator << (std::ostream& out_stream, const circle& cir) {
			out_stream << "Central point: " << cir.centre_point << "\nRadius: " << cir.radius;
			return out_stream;
		}
		friend std::istream& operator >> (std::istream& in_stream, circle& cir) {
			in_stream >> cir.centre_point >> cir.radius;
			return in_stream;
		}
		friend bool triangle::is_intersection(circle& circ);
	};

	class square: public virtual shapes
	{
	private:
		point vertex_first;
		point vertex_third;

	public:
		
		square(point v1, point v2) : 
			vertex_first(v1), vertex_third(v2) {
			if (area() == 0) {
				std::cout << "Something wrong in square's vertexes\n";
			}
		}
		std::vector<point> take_vertexes();
		double area();
		double perimeter();
		bool is_point_inside(point p_t);
		void move(point rad_vec);

		bool is_intersection(circle& circ);
		bool is_intersection(triangle& tr);
		bool is_intersection(square& sq);

		friend std::ostream& operator << (std::ostream& out_stream, square& sq) {
			std::vector<point> SquarePointsVector = sq.take_vertexes();
			for (auto i : SquarePointsVector) {
				out_stream << i << " ";
			}
			return out_stream;
		}
		friend std::istream& operator >> (std::istream& in_stream, square& sq) {
			in_stream >> sq.vertex_first >> sq.vertex_third;
			return in_stream;
		}
		friend bool circle::is_intersection(square& sq);
		friend bool triangle::is_intersection(square& sq);
	};
}