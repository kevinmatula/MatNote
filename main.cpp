#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

// This is a function that is called every time a user tries to resize window
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
// This is a function that is called on every tick to check if input was
// provided.
void processInput(GLFWwindow *window);

const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

int main() {
  // Initialization (setting GLFW to version 3, and setting profile to
  // core_profile for some reason)
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Initializing Window
  GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT,
                                        "Rendering Window", NULL, NULL);

  if (window == NULL) {
    std::cout << "Failed to Display Window." << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  // Want to make sure GLAD is initalized before calling any OpenGL function
  // because GLAD manages function pointers
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

  // Here, we tell GLFW we want to call this function on every window resize
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // This while loop is also called the render loop, controls rendering.
  while (!glfwWindowShouldClose(window)) {

    processInput(window);

    // We want to clear the screen each frame
    // Clear color buffer using glClear, then color buffer filled with the color
    // configured by glClearColor!
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Swaps the color buffer and show it as output to the screen
    // I think this works by being a double buffer, as in something is always
    // drawn to the screen to reduce flickering
    glfwSwapBuffers(window);

    // Checks if any events are triggered, and updates the window state
    // by calling corresponding functions (that are registered via clalback
    // methods)
    glfwPollEvents();
  }
  // Delete and clean all of GLFW's resources!
  glfwTerminate();
  return 0;
}

// This method deals with window resizing
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

// This function deals with input processing
void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}
