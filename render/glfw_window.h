#ifndef NOCHE_GLFW_WINDOW_H
#define NOCHE_GLFW_WINDOW_H

#include <render/window.h>
#include <GLFW/glfw3.h>

namespace bomb
{
class GlfwWindow: inherit Window
{
public:
  GlfwWindow(uint16_t width = 1280, uint16_t height = 720);

private:
  GLFWwindow* window;

  uint16_t width;
  uint16_t height;
};
}

#endif //NOCHE_GLFW_WINDOW_H
