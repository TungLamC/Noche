#ifndef NOCHE_APPLICATION_H
#define NOCHE_APPLICATION_H

#include <bomb.h>
#include <editor/layer.h>
#include <render/window.h>

namespace bomb
{
using namespace std;

class Application
{
public:
  static void static_constructor()
  {
    running = true;
    layers = {};
  }

  static void push_layer(Layer* layer);

  static void run();

private:
  static bool running;

  static vector<Layer*> layers;

  static unique_ptr<Window> window;
};

static_construct(Application);
using application = Application;
}



#endif //NOCHE_APPLICATION_H
