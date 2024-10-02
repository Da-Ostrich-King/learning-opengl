#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
// function called on window resize
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

int main (int argc, char* argv[]) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // begin initializing glfw window
    GLFWwindow* window = glfwCreateWindow(1366, 768, "HELLO WORLD", NULL, NULL);
    if (window == NULL) {
        std::cout << "FATAL: failed to create glfw window\n";
        glfwTerminate();
        return 1;
    }
    // make the context (i dont really know what that means)
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "FATAL: failed to initialize GLAD\n";
        return 1;
    }
    // set the viewport size
    glViewport(0, 0, 1366, 768);

    // set the function to be called on the resize of the given window
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    // finished window initialization
    // main event loop
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // cleanly dispose of resources
    glfwTerminate();
    return 0;
}