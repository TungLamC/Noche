#ifndef NOCHE_IMGUI_LAYER_H
#define NOCHE_IMGUI_LAYER_H

#include <noche.h>
#include <application/layer.h>
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

namespace Noche
{
class ImguiLayer: inherit Layer
{
public:
    ImguiLayer();
    virtual ~ImguiLayer();
 
    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnUpdate() override;
    virtual void OnEvent(const Event &event) override;

private:
    real32 time = 0.0f;
};
}

#endif //NOCHE_IMGUI_LAYER_H
