#ifndef NOCHE_WINDOW_H
#define NOCHE_WINDOW_H

#include <common/alias.h>

namespace bomb
{
class Window
{
public:
  virtual void on_update() = 0;

  virtual uint16_t window_width() = 0;
  virtual uint16_t window_height() = 0;
};
}

#endif //NOCHE_WINDOW_H
