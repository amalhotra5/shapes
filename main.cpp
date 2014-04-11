/* Program that creates some shapes */
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "GC.h"
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;
using namespace std::placeholders;

void draw(const vector<Shape*>& v, GC& gc) {
  for_each(v.begin(), v.end(), bind(&Shape::draw,_1,gc));
}

int main() {
  GC              gc;
  vector<Shape*>  v;

  v.push_back(new Circle(Point(1,1), 2, GC::Red));
  v.push_back(new Triangle(Point(0,1), Point(1,1), Point(1,0), GC::Blue));
  v.push_back(new Triangle(Point(2,1), Point(1,2), Point(2,2), GC::Green));
  draw(v,gc);
  gc.reset();
}
