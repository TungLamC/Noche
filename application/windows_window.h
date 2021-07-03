#ifndef NOCHE_WINDOWS_WINDOW_H
#define NOCHE_WINDOWS_WINDOW_H

#include <common/alias.h>
#include <application/window.h>
#include <GLFW/glfw3.h>

namespace Noche
{
class WindowsWindow: inherit Window
{
public:
    WindowsWindow(const WindowProps& props);
    virtual ~WindowsWindow();

    virtual void OnUpdate() override;

    virtual uint32_t GetWidth() const override { return data.width; }
    virtual uint32_t GetHeight() const override { return data.height; }

    inline virtual void SetEventCallBack(const EventCallBack &callback) override { data.callback = callback; }

private:
    virtual void Initialize(const WindowProps& props);
    virtual void Shutdown();

public:
    GLFWwindow* window;

    struct WindowData
    {
        string title;
        uint32_t width;
        uint32_t height;
        EventCallBack callback;
    };

    WindowData data;
};
}

#endif //NOCHE_WINDOWS_WINDOW_H
