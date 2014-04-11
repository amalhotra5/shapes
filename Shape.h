#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include "GC.h"

class Shape {
  public:
    explicit Shape(GC::Colour colour): colour_(colour) {}
    virtual void draw(GC& gc) const = 0;
    virtual void save(std::ostream& os) const = 0;
  private:
    GC::Colour  colour_;
};

inline void
Shape::draw(GC& gc) const {
  gc.setColour(colour_);
}

inline void
Shape::save(std::ostream& os) const {
  os << colour_ << std::endl;
}
#endif
