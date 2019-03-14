#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "Shader.h"
#include "Vertice.h"

using namespace std;

void dibujar();
void actualizar();
void inicializarTriangulo();
void inicializarCuadrado();
void inicializarChichenItza();
void inicializarChichenItza1();
void inicializarChichenItza2();
void inicializarChichenItza3();
void inicializarChichenItzaPiso();

Shader *shader;
GLuint posicionID;
GLuint colorID;

vector<Vertice> triangulo;
GLuint vertexArrayTrianguloID;
GLuint bufferTrianguloID;

vector<Vertice> cuadrado;
GLuint vertexArrayCuadradoID;
GLuint bufferCuadradoID;

vector<Vertice> chichenItza;
GLuint vertexArrayChichenItzaID;
GLuint bufferChichenItzaID;

vector<Vertice> chichenItza2;
GLuint vertexArrayChichenItzaID2;
GLuint bufferChichenItzaID2;

vector<Vertice> chichenItza3;
GLuint vertexArrayChichenItzaID3;
GLuint bufferChichenItzaID3;

vector<Vertice> chichenItzaPiso;
GLuint vertexArrayChichenItzaIDPiso;
GLuint bufferChichenItzaIDPiso;

int main()
{
	// Creamos una ventana
	GLFWwindow *window;

	// Si no se puede inicializar glfw, finalizamos la ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	// Si se pudo iniciar GLFW, entonces inicializamos la ventana
	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);
	
	// Si no podemos iniciar la ventana, terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	// Una vez establecido el contexto, activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL << std::endl;

	//inicializarTriangulo();
	//inicializarCuadrado();
	inicializarChichenItza();
	inicializarChichenItza1();
	inicializarChichenItza2();
	inicializarChichenItza3();
	//inicializarChichenItzaPiso();

	const char *rutaVertex = "VertexShader.shader";
	const char *rutaFragment = "FragmentShader.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	// Mapeo de atributos
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");

	// Desenlazar el shader
	shader -> desenlazar();

	// Crear un vertex array (triángulo)
	glGenVertexArrays(1, &vertexArrayTrianguloID);
	glBindVertexArray(vertexArrayTrianguloID);
	// Crear un vertex buffer (triángulo)
	glGenBuffers(1, &bufferTrianguloID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferTrianguloID);
	// Llenado del buffer (triángulo)
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * triangulo.size(), triangulo.data(), GL_STATIC_DRAW);
								// Memoria consumida * Número de elementos (vértices) que tiene el vector

	// Habilitar atributos del Shader (cuadrado)
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	// Especificar a OpenGL cómo se va a comunicar (cuadrado)
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));
	// Vertex Array + Búffer (cuadrado)
	glGenVertexArrays(1, &vertexArrayCuadradoID);
	glBindVertexArray(vertexArrayCuadradoID);
	glGenBuffers(1, &bufferCuadradoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadradoID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cuadrado.size(), cuadrado.data(), GL_STATIC_DRAW);

	// Habilitar atributos del Shader (chichen itzá)
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	// Especificar a OpenGL cómo se va a comunicar (chichen itzá)
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));
	// Vertex Array + Búffer (chichen itzá)
	glGenVertexArrays(1, &vertexArrayChichenItzaID);
	glBindVertexArray(vertexArrayChichenItzaID);
	glGenBuffers(1, &bufferChichenItzaID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferChichenItzaID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * chichenItza.size(), cuadrado.data(), GL_STATIC_DRAW);

	// Habilitar atributos del Shader (chichen itzá2)
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	// Especificar a OpenGL cómo se va a comunicar (chichen itzá2)
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));
	// Vertex Array + Búffer (chichen itzá2)
	glGenVertexArrays(1, &vertexArrayChichenItzaID2);
	glBindVertexArray(vertexArrayChichenItzaID2);
	glGenBuffers(1, &bufferChichenItzaID2);
	glBindBuffer(GL_ARRAY_BUFFER, bufferChichenItzaID2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * chichenItza2.size(), cuadrado.data(), GL_STATIC_DRAW);

	// Habilitar atributos del Shader (chichen itzá3)
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	// Especificar a OpenGL cómo se va a comunicar (chichen itzá2)
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));
	// Vertex Array + Búffer (chichen itzá2)
	glGenVertexArrays(1, &vertexArrayChichenItzaID3);
	glBindVertexArray(vertexArrayChichenItzaID3);
	glGenBuffers(1, &bufferChichenItzaID3);
	glBindBuffer(GL_ARRAY_BUFFER, bufferChichenItzaID3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * chichenItza3.size(), cuadrado.data(), GL_STATIC_DRAW);

	// Habilitar atributos del Shader (chichen itzá Piso)
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	// Especificar a OpenGL cómo se va a comunicar (chichen itzá Piso)
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));
	// Vertex Array + Búffer (chichen itzá Piso)
	glGenVertexArrays(1, &vertexArrayChichenItzaIDPiso);
	glBindVertexArray(vertexArrayChichenItzaIDPiso);
	glGenBuffers(1, &bufferChichenItzaIDPiso);
	glBindBuffer(GL_ARRAY_BUFFER, bufferChichenItzaIDPiso);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * chichenItzaPiso.size(), cuadrado.data(), GL_STATIC_DRAW);

	// Habilitar atributos del Shader (Triangulo)
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	// Especificar a OpenGL cómo se va a comunicar (Triangulo)
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));
	// Soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		
		// Establecer region de dibujo
		glViewport(0, 0, 1024, 768);

		// Establece el color de borrado
		glClearColor(.23, 0.3, 0.3, 1);

		// Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Rutina de dibujo
		dibujar();
		actualizar();

		// Cambiar los buffers
		glfwSwapBuffers(window);

		// Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

void dibujar()
{
	// Elegir el Shader
	shader -> enlazar();

		// Elegir un vertex array
		glBindVertexArray(vertexArrayTrianguloID);

			// Dibujar
			glDrawArrays(GL_TRIANGLES, 0, triangulo.size());

			// Dibujar Cuadrado
			glBindVertexArray(vertexArrayCuadradoID);
			glDrawArrays(GL_POLYGON, 0, cuadrado.size());

			// Dibujar Chichen Itzá
			glBindVertexArray(vertexArrayChichenItzaID);
			glDrawArrays(GL_LINES, 0, chichenItza.size());

		// Soltar el vertex array
		glBindVertexArray(0);

	// Soltar el Shader
	shader -> desenlazar();
}

void actualizar()
{
	
}

void inicializarTriangulo() 
{
	Vertice v1 =
	{
		vec3(0.0f, 0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};
	Vertice v2 =
	{
		vec3(0.3f, -0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};
	Vertice v3 =
	{
		vec3(-0.3f, -0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	triangulo.push_back(v1);
	triangulo.push_back(v2);
	triangulo.push_back(v3);
}

void inicializarCuadrado() 
{
	Vertice v1 =
	{
		vec3(1.0f, 0.0f, 0.0f),
		vec4(0.4f, 0.5f, 0.2f, 1.0f)
	};
	Vertice v2 =
	{
		vec3(0.5f, 0.0f, 0.0f),
		vec4(0.4f, 0.5f, 0.2f, 1.0f)
	};
	Vertice v3 =
	{
		vec3(0.5f, 0.5f, 0.0f),
		vec4(0.4f, 0.5f, 0.2f, 1.0f)
	};
	Vertice v4 =
	{
		vec3(1.0f, 0.5f, 0.0f),
		vec4(0.4f, 0.5f, 0.2f, 1.0f)
	};

	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarChichenItza()
{
	for (int c = 0; c < 9; c++) {
		Vertice v1 =
		{
			vec3(-0.95f + (c * 0.10555556f), -0.95f + (c * .1583333f), 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
		Vertice v2 =
		{
			vec3(0.95f - (c * 0.10555556f), -0.95f + (c * .1583333f), 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
		Vertice v3 =
		{
			vec3(0.95f - (c * 0.10555556f), -0.95f + ((c + 1) * .1583333f), 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
		Vertice v4 =
		{
			vec3(-0.95f + (c * 0.10555556f), -0.95f + ((c + 1) * .1583333f), 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
		cuadrado.push_back(v1);
		cuadrado.push_back(v2);
		cuadrado.push_back(v3);
		cuadrado.push_back(v4);
	}	/*
	
	Vertice v9 =
		{
			vec3(-0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v10 =
		{
			vec3(0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v11 =
		{
			vec3(0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v12 =
		{
			vec3(-0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	cuadrado.push_back(v9);
	cuadrado.push_back(v10);
	cuadrado.push_back(v11);
	cuadrado.push_back(v12);
	
	Vertice v13 =
		{
			vec3(-0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v14 =
		{
			vec3(0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v15 =
		{
			vec3(0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v16 =
		{
			vec3(-0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
		cuadrado.push_back(v13);
		cuadrado.push_back(v14);
		cuadrado.push_back(v15);
		cuadrado.push_back(v16);
	
		
	Vertice v17 =
		{
			vec3(-0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v18 =
		{
			vec3(0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v19 =
		{
			vec3(0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v20 =
		{
			vec3(-0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	cuadrado.push_back(v17);
	cuadrado.push_back(v18);
	cuadrado.push_back(v19);
	cuadrado.push_back(v20);
	
			Vertice v21 =
		{
			vec3(-0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
			};
	Vertice v22 =
		{
			vec3(0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v23 =
		{
			vec3(0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v24 =
		{
			vec3(-0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	cuadrado.push_back(v21);
	cuadrado.push_back(v22);
	cuadrado.push_back(v23);
	cuadrado.push_back(v24);
	
	Vertice v25 =
		{
			vec3(-0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v26 =
		{
			vec3(0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v27 =
		{
			vec3(0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v28 =
		{
			vec3(-0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	cuadrado.push_back(v25);
	cuadrado.push_back(v26);
	cuadrado.push_back(v27);
	cuadrado.push_back(v28);
	
			Vertice v29 =
		{
			vec3(-0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v30 =
		{
			vec3(0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v31 =
		{
			vec3(0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v32 =
		{
			vec3(-0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	cuadrado.push_back(v29);
	cuadrado.push_back(v30);
	cuadrado.push_back(v31);
	cuadrado.push_back(v32);
	
	Vertice v33 =
		{
			vec3(-0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v34 =
		{
			vec3(0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v35 =
		{
			vec3(0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v36 =
		{
			vec3(-0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	cuadrado.push_back(v33);
	cuadrado.push_back(v34);
	cuadrado.push_back(v35);
	cuadrado.push_back(v36);
			
	Vertice v37 =
		{
			vec3(-0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v38 =
		{
			vec3(0.95f, -0.95f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v39 =
		{
			vec3(0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	Vertice v40 =
		{
			vec3(-0.95f, -0.7388889f, 0.0f),
			vec4(0.4f, 0.5f, 0.2f, 1.0f)
		};
	cuadrado.push_back(v37);
	cuadrado.push_back(v38);
	cuadrado.push_back(v39);
	cuadrado.push_back(v40);*/
}


void inicializarChichenItza1() 
{

}

void inicializarChichenItza2()
{

}

void inicializarChichenItza3()
{

}

void inicializarChichenItzaPiso()
{
	Vertice v41 =
	{
		vec3(-1.0f, -1.0, 0.0f),
		vec4(0.86f, 0.72f, 0.53f, 1.0f)
	};
	Vertice v42 =
	{
		vec3(1.0f, -1.0, 0.0f),
		vec4(0.86f, 0.72f, 0.53f, 1.0f)
	};
	Vertice v43 =
	{
		vec3(1.0f, -0.95f, 0.0f),
		vec4(0.86f, 0.72f, 0.53f, 1.0f)
	};
	Vertice v44 =
	{
		vec3(-1.0f, -0.95f, 0.0f),
		vec4(0.86f, 0.72f, 0.53f, 1.0f)
	};
	cuadrado.push_back(v41);
	cuadrado.push_back(v42);
	cuadrado.push_back(v43);
	cuadrado.push_back(v44);
}