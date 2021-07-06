#include <render/glfw_window.h>
#include <debug/log.h>

namespace bomb
{
GlfwWindow::GlfwWindow(uint16_t width, uint16_t height): width(width), height(height)
{
  int success = glfwInit();
  ASSERT(success, "Could not initialize GLFW!")
  glfwSetErrorCallback([](int error, const char* descriptioin) {
    log::error("GLFW ERROR: {0} {1}", error, descriptioin);
  });
}
}
