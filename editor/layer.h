#ifndef NOCHE_LAYER_H
#define NOCHE_LAYER_H

#include <noche.h>

namespace bomb
{
using namespace std;

class Layer
{
public:
  Layer(const string& name): name{name} { }
  virtual ~Layer() = default;

  virtual void on_attach() = 0;
  virtual void on_detach() = 0;
  virtual void on_update() = 0;

  const string name;
};
}

#endif //NOCHE_LAYER_H
