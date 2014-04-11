#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <sstream>
#include "Shape.h"
#include "Point.h"

// Circle inherits from shape
class Circle: public Shape {
  public:
    explicit Circle(const Point& centre = Point(), int radius = 1,
                    GC::Colour colour = GC::Default)
      : Shape(colour), centre_(centre), radius_(radius) {}

    virtual void draw(GC& gc) const {
      Shape::draw(gc);
      std::ostringstream  oss;
      oss << "[C: " << centre_ << ' ' << radius_ << "]\n";
      gc.draw(oss.str());
    }

    virtual void save(std::ostream& os) const {
      Shape::save(os);
      os << centre_ << ' ' << radius_ << std::endl;
    }

  private:
    Point  centre_;
    int    radius_;
};
#endif
