#include <entry/application.h>

namespace bomb
{
void application::run()
{
  while (running)
  {
    for (auto layer : layers)
      layer->on_update();
    window->on_update();
  }
}
void Application::push_layer(Layer* layer)
{
  layers.emplace_back(layer);
  layer->on_attach();
}
}
