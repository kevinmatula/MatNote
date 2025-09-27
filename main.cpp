#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
  // Initialization (setting GLFW to version 3, and setting profile to
  // core_profile for some reason)
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Initializing Window
  GLFWwindow *window =
      glfwCreateWindow(800, 600, "Rendering Window", NULL, NULL);

  if (window == NULL) {
    std::cout << "Failed to Display Window." << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  return 0;
}
