#include <noche.h>
#include <glad/glad.h>
#include <event/event.h>
#include <event/key_event.h>
#include <event/mouse_event.h>
#include <event/window_event.h>
#include <application/windows_window.h>

namespace Noche
{
static bool glfw_initialized = false;

Window* Window::Create(const WindowProps& props) 
{
    return new WindowsWindow(props);
}

WindowsWindow::WindowsWindow(const WindowProps& props)
{
    Initialize(props);
}

WindowsWindow::~WindowsWindow()
{
    Shutdown();
}

void WindowsWindow::OnUpdate()
{
    glClearColor(1.0, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();
    glfwSwapBuffers(window);
}

void WindowsWindow::Initialize(const WindowProps& props)
{
    data.title = props.title;
    data.width = props.width;
    data.height = props.height;
    Log::Info("Creating window {0} {1} {2}", props.title, props.width, props.height);
    if (!glfw_initialized)
    {
        int success = glfwInit();
        ASSERT(success, "Could not initialize GLFW!");
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
//        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
        window = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(window);
        glfwSetWindowUserPointer(window, &data);
        ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Counld not initialize glad!");
        glfwSetErrorCallback([](int error, const char* description) {
            Log::Info("GLFW ERROR: {0}", description);
        });
        glfw_initialized = true;

        glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowResizeEvent event(width, height);
            data.width = width;
            data.height = height;
            data.callback(event);
        });

        glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.callback(event);
        });

        glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int modes) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyPressEvent event(key, 0);
                    data.callback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressEvent event(key, 1);
                    data.callback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleaseEvent event(key);
                    data.callback(event);
                    break;
                }
            }
        });
        
        glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int modes) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch (action)
            {
                case GLFW_PRESS:
                {
                    MouseClickEvent event(button);
                    data.callback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseReleaseEvent event(button);
                    data.callback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(window, [](GLFWwindow* window, real64 x, real64 y) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseScrollEvent event((real32)x, (real32)y);
            data.callback(event);
        });

        glfwSetCursorPosCallback(window, [](GLFWwindow* window, real64 x, real64 y) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseMoveEvent event(x, y);
            data.callback(event);
        });
    }
}

void WindowsWindow::Shutdown()
{
    glfwDestroyWindow(window);
}

}

