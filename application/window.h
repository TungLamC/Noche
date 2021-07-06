//#ifndef NOCHE_WINDOW_H
//#define NOCHE_WINDOW_H
//
//#include <common/alias.h>
//#include <event/event.h>
//
//namespace Noche
//{
//struct WindowProps
//{
//    string title;
//    uint32_t width;
//    uint32_t height;
//
//    WindowProps(const string& title = "Noche Engine", uint32_t width = 1280, uint32_t height = 720)
//        : title(title), width(width), height(height) { }
//};
//
//class Window
//{
//public:
//    using EventCallBack = std::function<void(Event&)>;
//
//    virtual ~Window() = default;
//
//    virtual void OnUpdate() = 0;
//
//    virtual uint32_t GetWidth() const = 0;
//    virtual uint32_t GetHeight() const = 0;
//
//    virtual void SetEventCallBack(const EventCallBack& callback) = 0;
//
//    static Window* Create(const WindowProps& props = WindowProps());
//};
//}
//
//#endif //NOCHE_WINDOW_H
