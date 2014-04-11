#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <sstream>
#include <typeinfo>
#include "Shape.h"
#include "Point.h"
#include "GC.h"

class Triangle: public Shape {
  public:
    explicit Triangle(const Point& v1 = Point(), const Point& v2 = Point(0,1),
                      const Point& v3 = Point(1,0), 
                      GC::Colour colour = GC::Default)
      : Shape(colour), v1_(v1), v2_(v2), v3_(v3) {}

	// draws a triangle on graphical context
    virtual void draw(GC& gc) const {
      Shape::draw(gc);
      std::ostringstream oss;
      oss << "[T: " << v1_ << ' ' << v2_ << ' ' << v3_ << "]\n";
      gc.draw(oss.str());
    }

    virtual void save(std::ostream& os) const {
      Shape::save(os);
      os << v1_ << ' ' << v2_ << ' ' << v3_ << std::endl;
    }

private:
  Point  v1_, v2_, v3_;
};

#endif
