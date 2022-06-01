//#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#include <cassert>

using namespace std;

void glfw_error_cb(int error, const char* description) { cerr << "Error: " << description << endl; }
void assert_the(const auto val) { static_assert(sizeof(val) < 9u); if (!val) exit(1); }

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main()
{
	// intit
	if (glfwInit() != GLFW_TRUE) { cerr << "Fail: glfwInit()\n"; return 1; }
	glfwSetErrorCallback(glfw_error_cb);

	// proceed
	GLFWwindow* window = glfwCreateWindow(640, 480, "glfw tutorial", nullptr, nullptr);
	if (!window) { cerr << "Fail: glfwInit()\n"; return 1; }
	assert(window);
	assert_the(window);

	glfwSetKeyCallback(window, key_callback);
	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) {
		cout << 'a';
		//glfwPollEvents();
		glfwWaitEvents();
	}

	// terminate
	//system("pause");
	glfwDestroyWindow(window);
	glfwTerminate();
}