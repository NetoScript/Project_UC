
void ShowMenu(GLFWwindow* Window) {

	std::cout << "Show Menu\n";
	glfwSetWindowAttrib(Window, GLFW_MOUSE_PASSTHROUGH, false);
}

void HideMenu(GLFWwindow* Window) {

	std::cout << "Hiding Menu\n";
	glfwSetWindowAttrib(Window, GLFW_MOUSE_PASSTHROUGH, true);
}