#ifndef GC_H
#define GC_H

class GC {
  public:
    enum Colour { Default, Black, Red, Green, Yello, 
      Blue, Purple, Cyan, Grey };

    explicit GC(std::ostream& os = std::cout, Colour colour = Default)
      : out_(&os), colour_(colour) {}

    void setColour(Colour colour) {
      colour_ = colour;
    }

    void reset() {
      *out_ << "\033[0;37m" << '\n';
    }

    void draw(const std::string& s) {
      const char *colours[] = {
        "\033[0;37m",  // Default = Grey
        "\033[0;30m",  // Black
        "\033[0;31m",  // Red
        "\033[0;32m",  // Green
        "\033[0;33m",  // Yellow
        "\033[0;34m",  // Blue
        "\033[0;35m",  // Purple
        "\033[0;36m",  // Cyan
        "\033[0;37m",  // Grey
      };
      *out_ << colours[colour_] << s;
    }

  private:
    std::ostream  *out_;
    Colour         colour_;
};
#endif
