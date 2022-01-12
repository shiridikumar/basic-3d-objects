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
// int main(){
// 	float start[] = {1, 0, 0};

// 	glm::mat4 myMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(10.0f, 0.0f, 0.0f));
// 	int sides=8;
// 	float vertices[4*(sides+1)];
// 	vertices[0]=0;vertices[1]=0;vertices[2]=0;vertices[3]=0;
// 	vertices[4]=1;vertices[5]=0;vertices[6]=0;vertices[7]=0;
// 	float vertices_bottom[4*(sides+1)];

	

// 	int coun=8;
// 	for (int i = 1; i < sides; i++)
// 	{
// 		myMatrix = glm::mat4(1.0f);
// 		myMatrix = glm::rotate(myMatrix,  (i)*glm::radians((float)360/sides), glm::vec3(0.0f, 0.0f, 1.0f));
// 		glm::vec4 myVector(1.0f, 0.0f, 0.0f, 0.0f);
// 		glm::vec4 transformedVector = myMatrix * myVector;
// 		double dArray[4] = {0.0};
// 		const float *pSource = (const float *)glm::value_ptr(transformedVector);
// 		cout<<"(";
// 		for (int j = 0; j < 4; ++j)
// 		{
// 			vertices[coun++]=pSource[j];
// 			//cout << pSource[j] << ", ";
// 		}
// 		//cout<<")";
// 	}
// 	glm::mat4 transMatrix = glm::mat4(1.0f);
// 	transMatrix = glm::translate(transMatrix, glm::vec3(0.0f, 0.0f, 0.5f));
//     int ind=0;
// 	for(int i=0;i<sides*4;i+=4){
// 		float x=vertices[i],y=vertices[i+1],z=vertices[i+2],w=1.0f;
// 		glm::vec4 oldvec(x,y,z,w);
// 		glm::vec4 newvec=transMatrix*oldvec;
// 		const float *pSource1 = (const float *)glm::value_ptr(newvec);
// 		//cout<<"(";
// 		for (int j = 0; j < 4; ++j)
// 		{
// 			vertices_bottom[ind++]=pSource1[j];
// 			//cout<<pSource1[j]<<",";
// 		}
// 		//cout<<")";
// 		cout<<endl;
		
// 	}

// }



int main(int rgc ,char *argv[])
{
	//glfw: initialize and configure
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



	//----------------------------------------vertices top------------------------------------------------------------------------------
	//glm::mat4 myMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	int sides=atoi(argv[1]);
	float vertices[2*(3+4)*(sides+1)];
	double cp=1.0f/(2+sides+1);
	double ini=cp;
	float r=cp,g=cp,b=cp,alpha=0.0f;
	vertices[0]=0.5f;vertices[1]=0.0f;vertices[2]=-0.5f ;vertices[3]=ini;vertices[4]=ini;vertices[5]=ini;vertices[6]=alpha;//;vertices[3]=1;
	ini+=cp;
	vertices[7]=0.5f;vertices[8]=0.0f;vertices[9]=-0.5f ;vertices[10]=ini;vertices[11]=ini;vertices[12]=ini;vertices[13]=alpha;//;vertices[7]=1;
	ini+=cp;
	float vertices_bottom[3*(sides+1)];
    cout<<"(0,0,0)"<<endl<<"(-1,0,0)"<<endl;

	int coun=14;
    glm::mat4 myMatrix = glm::mat4(1.0f);
    glm::vec4 myVector(0.5f,0.0f,-0.5f,0.0f);
	myMatrix = glm::rotate(myMatrix,  glm::radians((float)360/sides), glm::vec3(0.0f, 0.0f, 1.0f));
	for (int i = 1; i < sides; i++)
	{
		myVector = myMatrix * myVector;
		double dArray[4] = {0.0};
		const float *pSource = (const float *)glm::value_ptr(myVector);
		cout<<"(";
		float x=pSource[0],y=pSource[1],z=pSource[2];
		for (int j = 0; j < 3; ++j)
		{
			vertices[coun++]=pSource[j];
			cout << pSource[j] << ", ";
		}
			vertices[coun++]=x;
			vertices[coun++]=y;
			vertices[coun++]=z;
			vertices[coun++]=alpha;
			ini+=cp;
		cout<<")";
        cout<<endl;
	}
    //------------------------------vertices bottom--------------------------------------------------------------
    cout<<"-----------------------"<<endl<<endl;
    
    cout<<endl;
	cout<<coun<<"*****************"<<endl;
	glm::mat4 transMatrix = glm::mat4(1.0f);
	transMatrix = glm::translate(transMatrix, glm::vec3(0.0f, 0.0f, 1.0f));
    int ind=coun;
	for(int i=0;i<(sides+1)*7;i+=7){
		float x=vertices[i],y=vertices[i+1],z=vertices[i+2],w=1.0f;
		glm::vec4 oldvec(x,y,z,w);
		glm::vec4 newvec=transMatrix*oldvec;
		const float *pSource1 = (const float *)glm::value_ptr(newvec);
		cout<<"(";
		for (int j = 0; j < 3; ++j)
		{
			vertices[ind++]=pSource1[j];

			cout<<pSource1[j]<<",";
		}
			vertices[ind++]=x;
			vertices[ind++]=y;
			vertices[ind++]=z;
			ini+=cp;
			vertices[ind++]=alpha;
		 cout<<")";
        cout<<" "<<"("<<x<<" ,"<<y<<" ,"<<z<<")"<<endl;
		cout<<endl;
		
	}
    cout<<"*******************"<<endl;
	unsigned int indices[2*3*sides +6*sides];
	 coun=0;
	int count =1;
	for(int i=0;i<sides;i++){
		indices[coun]=0;
		cout<<indices[coun]<<" ";coun++;
		indices[coun]=count;
		cout<<indices[coun]<<" ";coun++;
		indices[coun]=count+1;
		cout<<indices[coun]<<" ";coun++;
		count++;
		cout<<endl;
	}
    
    int pad=sides+1;
    count=1;
	indices[3*sides-1]=1;
    cout<<coun<<"*************"<<endl;
    for(int i=0;i<sides;i++){
        indices[coun]=pad;
        cout<<indices[coun]<<" ";
        coun++;
        indices[coun]=pad+count;
        cout<<indices[coun]<<" ";
        coun++;
        indices[coun]=pad+count+1;
        cout<<indices[coun]<<" ";
        count++;coun++;
        cout<<endl;
    }
    indices[6*sides-1]=pad+1;
    for(int i=0;i<6*(sides);i++){
        if(i%3==0){
            cout<<endl;
        }
        cout<<indices[i]<<" ,";
    }
    cout<<endl;
	int top_p=1;
	int bottom_p=pad+1;
	for(int i=0;i<sides;i++){
		indices[coun]=top_p;coun++;
		indices[coun]=bottom_p;coun++;
		indices[coun]=bottom_p+1;coun++;
		top_p++;bottom_p++;
	}
	indices[coun-1]=pad+1;

	top_p=1;
	bottom_p=pad+1;
	for(int i=0;i<sides;i++){
		indices[coun]=bottom_p+1;coun++;
		indices[coun]=top_p;coun++;
		indices[coun]=top_p+1;coun++;
		top_p++;
		bottom_p++;
	}
	cout<<"*********"<<endl;
	indices[coun-1]=1;
	indices[coun-3]=pad+1;
	for(int i=0;i<coun;i++){
		if(i%3==0){
			cout<<endl;
		}
		cout<<indices[i]<<", ";
	}
	cout<<endl;
	
	cout<<endl;
	for(int i=0;i<2*(3+4)*(sides+1);i+=7){
		cout<<vertices[i]<<" ,"<<vertices[i+1]<<" ,"<<vertices[i+2]<<endl;

	}
	cout<<endl;

	// int pad2=7*(sides+1)+14;
	// int colp=0;

	// for(int i=0;i<sides-1;i++){
	// 	cout<<vertices[colp+pad2+4]<<" "<<vertices[colp+4+7]<<endl;
	// 	vertices[colp+pad2+4]=vertices[colp+4+7];
	// 	vertices[colp+pad2+5]=vertices[colp+5+7];
	// 	cout<<vertices[colp+pad2+5]<<" "<<vertices[colp+5+7]<<endl;
	// 	vertices[colp+pad2+6]=vertices[colp+6+7];
	// 	cout<<vertices[colp+pad2+6]<<" "<<vertices[colp+6+7]<<endl;
	// 	colp+=7;
	// }
	// vertices[pad2-7+4]=vertices[colp+4+7];
	// vertices[pad2-7+5]=vertices[colp+5+7];
	// vertices[pad2-7+6]=vertices[colp+6+7];


	unsigned int EBO, VAO, VBO, VAO2, VBO2, EBO2, *VAOs;
	glGenVertexArrays(1, &VAO);

	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7* sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7* sizeof(float),
					  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindVertexArray(0);

	//*******************************************************

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::rotate(transform, glm::radians(115.0f),    //(float)glfwGetTime(),
								glm::vec3(1.0f, 0.0f, 0.0f));

		ourShader.use();
		unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE,
						   glm::value_ptr(transform));

		 glm::mat4 model = glm::mat4(1.0f);

		 //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, (float)glfwGetTime()*1.0f, glm::vec3(0.0f, 1.0f, 0.0f));

		// glm::mat4 view = glm::mat4(1.0f);
		// // note that we're translating the scene in the reverse direction of where we want to move
		// view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		// glm::mat4 projection;
		//  projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 10.0f);
		 int modelLoc = glGetUniformLocation(ourShader.ID, "model");
		 glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		// int modelLoc2 = glGetUniformLocation(ourShader.ID, "view");
		// glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(view));
		// int modelLoc3 = glGetUniformLocation(ourShader.ID, "projection");
		//  glUniformMatrix4fv(modelLoc3, 1, GL_FALSE, glm::value_ptr(projection));

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES,6*sides+6*sides, GL_UNSIGNED_INT,0 );

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}



void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}