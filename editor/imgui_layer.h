#ifndef NOCHE_IMGUI_LAYER_H
#define NOCHE_IMGUI_LAYER_H

#include <bomb.h>
#include <editor/layer.h>
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

namespace bomb
{
class imgui_layer: inherit layer
{
public:
  imgui_layer(const std::string& name = "imgui");

  virtual void on_attach() override;
  virtual void on_detach() override;
  virtual void on_update() override;
};
}

#endif //NOCHE_IMGUI_LAYER_H
