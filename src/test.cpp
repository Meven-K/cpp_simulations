#include <iostream>
#include <ostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
} 

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

float check(float a){
    a = a<1? a:1;
    return a>0? a:0;
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        // std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  
    
    float r1 = 0.5f;
    float r2 = 0.5f;
    float r3 = 0.5f;


    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        // RENDERING
        r1 = check(r1 - 0.0025 + static_cast <float> (rand()) / static_cast <float> (RAND_MAX/0.005));
        r2 = check(r2 - 0.0025 + static_cast <float> (rand()) / static_cast <float> (RAND_MAX/0.005));
        r3 = check(r3 - 0.0025 + static_cast <float> (rand()) / static_cast <float> (RAND_MAX/0.005));
        glClearColor(r1, r2, r3, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    } 

    glfwTerminate();
    return 0;
}