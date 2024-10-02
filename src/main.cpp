#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <random>

struct Data {
    float red = 0;
    float green = 0;
    float blue = 0;
};


// function called on window resize
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void process_input(GLFWwindow* window, Data &data) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_REPEAT) {
        glfwSetWindowShouldClose(window, true);
    }

    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_R) == GLFW_REPEAT) {
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_REPEAT) {
            data.red -= 0.02;
        } else {
            data.red += 0.02;
        }
    } else if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_G) == GLFW_REPEAT) {
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_REPEAT) {
            data.green -= 0.02;
        } else {
            data.green += 0.02;
        }
    } else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_B) == GLFW_REPEAT) {
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_REPEAT) {
            data.blue -= 0.02;
        } else {
            data.blue += 0.02;
        }
    }
}

int main (int argc, char* argv[]) {

    std::mt19937 rand;
    std::uniform_int_distribution<int> distribution(0, 2);

    // init opengl
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
    
    Data data;
    data.red = 0;
    data.green = 0;
    data.blue = 0;
    // finished window initialization
    // main event loop
    while (!glfwWindowShouldClose(window)) {

        process_input(window, data);
        glClearColor(data.red, data.green, data.blue, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // cleanly dispose of resources
    glfwTerminate();
    return 0;
}