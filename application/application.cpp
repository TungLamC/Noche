#include <noche.h>
#include <event/window_event.h>
#include <application/application.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <functional>

namespace Noche
{
Application* Application::instance = nullptr;

Application::Application(): layer_stack()
{
    window = unique_ptr<Window>{Window::Create()};
    window->SetEventCallBack([&](Event& event) { this->OnEvent(event); });
    instance = this;
}

void Application::Run()
{
    while (running)
    {
        window->OnUpdate();
        for (auto layer: layer_stack)
            layer->OnUpdate();
    }
}
void Application::OnEvent(Event& event)
{
    Log::Info("{0}", event);
    EventDispatcher dispatcher(event);
    dispatcher.Dispatch<WindowCloseEvent>([&](Event& event) {
        running = false;
        return true;
    });
    for (auto layer: layer_stack)
    {
        if (event.handled) break;
        layer->OnEvent(event);
    }
}
void Application::PushLayer(Layer* layer)
{
    layer_stack.PushLayer(layer);
}
void Application::PushOverlay(Layer* layer)
{
    layer_stack.PushOverlay(layer);
}
}

