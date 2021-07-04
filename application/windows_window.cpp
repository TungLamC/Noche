#include <noche.h>
#include <glad/glad.h>
#include <event/event.h>
#include <event/key_event.h>
#include <event/mouse_event.h>
#include <event/window_event.h>
#include <application/windows_window.h>
#include <imgui.h>

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
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
//    glViewport(0, 0,1280, 720);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
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
        glfwSetErrorCallback([](int error, const char* description) {
            Log::Info("GLFW ERROR: {0}", description);
        });
        int success = glfwInit();
        ASSERT(success, "Could not initialize GLFW!");
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        window = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
        glfwSetWindowUserPointer(window, &data);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Counld not initialize glad!");
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

