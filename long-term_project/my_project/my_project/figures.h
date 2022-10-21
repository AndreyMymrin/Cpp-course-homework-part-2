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

	class triangle
	{
	private:
		point vertex_first;
		point vertex_second;
		point vertex_third;
	public:
		std::vector<point> TrianPointsVector = { vertex_first,vertex_second,vertex_third };
		triangle(point v1, point v2, point v3) :
			vertex_first(v1), vertex_second(v2), vertex_third(v3) {
			if (area() == 0) {
				std::cout << "Something wrong in triangle's vertexes\n";
			}
		}
		void take_vertexes(std::vector<point>* tpv);
		double area();
		double perimeter();
		void print_vertexes();
		bool is_point_inside(point p_t);
		void move(point rad_vec);

		bool intersection_with_square(square& sq);
		bool intersection_with_triangle(triangle& tr);
		bool intersection_with_circle(circle& circ);

		//friend std::ostream& operator << (std::ostream& out_stream, const triangle& tr);
		friend std::ostream& operator << (std::ostream& out_stream, const geometric_shapes::triangle& tr) {
			for (auto i : tr.TrianPointsVector) {
				out_stream << i << " ";
			}
			return out_stream;
		}

		friend std::istream& operator >> (std::istream& in_stream, geometric_shapes::triangle& tr) {
			in_stream >> tr.vertex_first >> tr.vertex_second >> tr.vertex_third;
			return in_stream;
		}
		//friend bool circle::intersection_with_triangle(triangle& tr);
		//friend bool square::intersection_with_triangle(triangle& tr);
	};

	class circle
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

		bool intersection_with_square(square& sq);
		bool intersection_with_triangle(triangle& tr);
		bool intersection_with_circle(circle& circ);

		friend std::ostream& operator << (std::ostream& out_stream, const geometric_shapes::circle& cir) {
			out_stream << "Central point: " << cir.centre_point << "\nRadius: " << cir.radius;
			return out_stream;
		}
		friend std::istream& operator >> (std::istream& in_stream, geometric_shapes::circle& cir) {
			in_stream >> cir.centre_point >> cir.radius;
			return in_stream;
		}

		//friend bool square::intersection_with_circle(circle& circ);
		friend bool triangle::intersection_with_circle(circle& circ);
	};

	class square
	{
	private:
		point vertex_first;
		point vertex_second;
		point vertex_third;
		point vertex_fourth;
	public:
		std::vector<point> SquarePointsVector = { vertex_first,vertex_second,
			vertex_third, vertex_fourth };
		square(point v1, point v3) :
			vertex_first(v1), vertex_third(v3) {
			if (area() == 0) {
				std::cout << "Something wrong in square's vertexes\n";
			}
		}
		void take_vertexes(std::vector<point>* spv);
		double area();
		double perimeter();
		void print_vertexes();
		bool is_point_inside(point p_t);
		void move(point rad_vec);

		bool intersection_with_circle(circle& circ);
		bool intersection_with_triangle(triangle& tr);
		bool intersection_with_square(square& sq);

		friend std::ostream& operator << (std::ostream& out_stream, geometric_shapes::square& sq) {
			sq.SquarePointsVector[1] = { 0.5 * (sq.vertex_third.x + sq.vertex_first.x + sq.vertex_first.y - sq.vertex_third.y),
										 0.5 * (sq.vertex_third.y + sq.vertex_third.x + sq.vertex_first.y - sq.vertex_first.x) } ;
			sq.SquarePointsVector[3] = { 0.5 * (sq.vertex_third.x + sq.vertex_first.x - sq.vertex_first.y + sq.vertex_third.y),
										 0.5 * (sq.vertex_third.y - sq.vertex_third.x + sq.vertex_first.y + sq.vertex_first.x) };
			for (auto i : sq.SquarePointsVector) {
				out_stream << i << " ";
			}
			return out_stream;
		}
		friend std::istream& operator >> (std::istream& in_stream, geometric_shapes::square& sq) {
			in_stream >> sq.vertex_first >> sq.vertex_third;
			return in_stream;
		}
		friend bool circle::intersection_with_square(square& sq);
		friend bool triangle::intersection_with_square(square& sq);
	};
}