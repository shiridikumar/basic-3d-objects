#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "shader.h"
#include <bits/stdc++.h>
using namespace std;

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

int main()
{
	float start[] = {1, 0, 0};
	glm::mat4 myMatrix = glm::mat4(1.0f);
	//myMatrix = glm::translate(myMatrix, glm::vec3(1.0f, 0.0f, 0.0f));
	//glm::mat4 myMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(10.0f, 0.0f, 0.0f));
	int sides=6;
	float vertices[4*(sides+1)];
	vertices[0]=0;vertices[1]=0;vertices[2]=0;vertices[3]=0;
	int coun=4;
	for (int i = 0; i < sides; i++)
	{
		myMatrix = glm::mat4(1.0f);
		myMatrix = glm::rotate(myMatrix,  (i+1)*glm::radians((float)360/sides), glm::vec3(0.0f, 0.0f, 1.0f));
		glm::vec4 myVector(1.0f, 0.0f, 0.0f, 0.0f);
		glm::vec4 transformedVector = myMatrix * myVector;
		double dArray[4] = {0.0};
		const float *pSource = (const float *)glm::value_ptr(transformedVector);
		//cout<<"(";
		for (int i = 0; i < 4; ++i)
		{
			vertices[coun++]=pSource[i];
			//cout << pSource[i] << ", ";
		}
		//cout<<")";
		//cout << endl;
	}

}

/*int main()
{
	// glfw: initialize and configure
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	GLFWwindow *window =
		glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Akanksha", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	Shader ourShader("../src/vertex.shader", "../src/fragment.shader");
	float start[] = {1, 0, 0};
	float angle = 360 / 5;
	glm::mat4 myMatrix = glm::mat4(1.0f);
	//myMatrix = glm::translate(myMatrix, glm::vec3(1.0f, 0.0f, 0.0f));
	//glm::mat4 myMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(10.0f, 0.0f, 0.0f));
	for (int i = 0; i < 5; i++)
	{
		myMatrix = glm::rotate(myMatrix, (i + 1) * (float)(360 / 5) * glm::degrees(50.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		glm::vec4 myVector(1.0f, 0.0f, 0.0f, 0.0f);
		glm::vec4 transformedVector = myMatrix * myVector;
		double dArray[4] = {0.0};
		const float *pSource = (const float *)glm::value_ptr(transformedVector);
		for (int i = 0; i < 4; ++i)
		{
			cout << pSource[i] << " ";
		}
		cout << endl;
	}

	float vertices[] = {
		-0.5f, -0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, -0.5f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f,
		-0.5f, 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f,

		-0.5f, -0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.5f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f,
		-0.5f, 0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f,

		-0.5f, 0.5f, 0.5f, 1.0f,
		-0.5f, 0.5f, -0.5f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f,
		-0.5f, 0.5f, 0.5f, 1.0f,

		0.5f, 0.5f, 0.5f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f,

		-0.5f, -0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, -0.5f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f,

		-0.5f, 0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f,
		-0.5f, 0.5f, 0.5f, 0.0f,
		-0.5f, 0.5f, -0.5f, 0.0f};

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3};

	unsigned int EBO, VAO, VBO, VAO2, VBO2, EBO2, *VAOs;
	glGenVertexArrays(1, &VAO);

	glGenBuffers(1, &VBO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5* sizeof(float),
	//					  (void *)(3 * sizeof(float)));
	//glEnableVertexAttribArray(1);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO);
	glBindVertexArray(0);

	//*******************************************************

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::rotate(transform, 0.0f * (float)glfwGetTime(),
								glm::vec3(0.0f, 0.0f, 1.0f));

		ourShader.use();
		unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE,
						   glm::value_ptr(transform));

		glm::mat4 model = glm::mat4(1.0f);
		//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

		glm::mat4 view = glm::mat4(1.0f);
		// note that we're translating the scene in the reverse direction of where we want to move
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
		int modelLoc = glGetUniformLocation(ourShader.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int modelLoc2 = glGetUniformLocation(ourShader.ID, "view");
		glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(view));
		int modelLoc3 = glGetUniformLocation(ourShader.ID, "projection");
		glUniformMatrix4fv(modelLoc3, 1, GL_FALSE, glm::value_ptr(projection));

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}*/

/*void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}*/
