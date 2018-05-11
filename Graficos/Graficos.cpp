// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"

#include <iostream>
#include <time.h>

#include "Vertice.h"
#include "Shader.h"
#include "Modelo.h"
#include "nave.h"

using namespace std;


GLfloat red, green, blue;

GLuint posicionID;
GLuint colorID;
GLuint ModeloID;
GLuint vistaID;
GLuint proyeccionID;

mat4 vista;
mat4 proyeccion;

Nave *nave;
Modelo *object;

Shader *shader;
//Declaración de ventana
GLFWwindow *window;

//Propiedades de la ventana
GLfloat ancho = 1024;
GLfloat alto = 768;

vec3 posicionCamara;
GLfloat x = 0.0f, y = 0.0f, z = 20.0f;

void actualizar() {
	int estadoderecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoderecha == GLFW_PRESS) {
		x = x + 0.01f;
		}
	

	int estadoizq = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoizq == GLFW_PRESS) {
		x = x - 0.01f;
	}

	int estadoarriba = glfwGetKey(window, GLFW_KEY_UP);
	if (estadoarriba == GLFW_PRESS) {
		y = y + 0.01f;
	}


	int estadoabajo = glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoabajo == GLFW_PRESS) {
		y = y - 0.01f;
	}

	int estadosi = glfwGetKey(window, GLFW_KEY_E);
	if (estadosi == GLFW_PRESS) {
		z = z + 0.01f;
	}


	int estadono = glfwGetKey(window, GLFW_KEY_Q);
	if (estadono == GLFW_PRESS) {
		z = z - 0.01f;
	}

	posicionCamara = vec3(x, y, z);

	vista = lookAt(posicionCamara,           //Posicion de la cámara 
		vec3(0.0f, 3.0f, 0.0f),              //Posicion del objetivo
		vec3(0.0f, 1.0f, 0.0f));             //Vector hacia arriba (rotación cámara)

	object->vista = vista;
		
};


void dibujar() {
	object->dibujar(GL_TRIANGLES);
	//figura2->dibujar(GL_POLYGON);
}



void inicializarFigura() {
	
}


void inicializarModelos() {
	object = new Modelo();
	srand(time(NULL));

//Inicio personaje
//De 1 a 4 pierna izq
	// 1
	object->vertices.push_back({ vec4(0.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(1.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.5f, 0.1f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//2
	object->vertices.push_back({ vec4(0.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.8f, -4.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.5f, 0.1f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//3
	object->vertices.push_back({ vec4(1.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.8f, -4.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.5f, 0.1f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//4
	object->vertices.push_back({ vec4(0.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.8f, -4.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(1.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

//De 5 a 8 pierna der
	// 5
	object->vertices.push_back({ vec4(-0.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-1.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-0.5f, 0.1f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//6
	object->vertices.push_back({ vec4(-0.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-0.8f, -4.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-0.5f, 0.1f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//7
	object->vertices.push_back({ vec4(-1.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-0.8f, -4.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-0.5f, 0.1f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//8
	object->vertices.push_back({ vec4(-0.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-0.8f, -4.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-1.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

//De 9 a 12 cuerpo
	//9
	object->vertices.push_back({ vec4(-1.0f, 0.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(1.0f, 0.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.0f, 3.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//10
	object->vertices.push_back({ vec4(-1.0f, 0.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.0f, 0.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.0f, 3.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//11
	object->vertices.push_back({ vec4(1.0f, 0.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.0f, 0.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.0f, 3.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//12
	object->vertices.push_back({ vec4(-1.0f, 0.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.0f, 0.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(1.0f, 0.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

//De 13 a 16 brazo izq
	//13
	object->vertices.push_back({ vec4(0.0f, 2.7f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(4.5f, 2.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(4.5f, 2.9f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//14
	object->vertices.push_back({ vec4(0.0f, 2.7f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(4.5f, 2.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(4.5f, 2.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(0.0f, 2.7f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(4.5f, 2.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(4.5f, 2.9f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(4.5f, 2.9f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(4.5f, 2.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(4.5f, 2.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(0.0f, 2.7f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-4.5f, 2.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-4.5f, 2.9f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(0.0f, 2.7f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-4.5f, 2.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-4.5f, 2.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(0.0f, 2.7f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-4.5f, 2.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-4.5f, 2.9f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-4.5f, 2.9f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-4.5f, 2.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-4.5f, 2.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

//Cabeza
	object->vertices.push_back({ vec4(0.0f, 3.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.6f, 4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-0.6f, 4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(0.6f, 4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.0f, 4.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.0f, 3.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(0.0f, 3.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-0.6f, 4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.0f, 4.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-0.6f, 4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.6f, 4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(0.0f, 4.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
//Fin del personaje

//Inicio del tren
	object->vertices.push_back({ vec4(-6.0f, -7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-18.0f, -7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-6.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-6.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-18.0f, -7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-18.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-6.0f, -7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-18.0f, -7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-6.0f, 5.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-18.0f, 5.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-18.0f, -7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-6.0f, 5.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-18.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-18.0f, -7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-18.0f, -7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-18.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-18.0f, -7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-18.0f, 5.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-6.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-18.0f, -7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-18.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-6.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-6.0f, -7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-6.0f, 5.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-6.0f, -7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-6.0f, -7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-6.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-6.0f, -7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-6.0f, -7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-18.0f, -7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-18.0f, -7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-18.0f, -7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-6.0f, -7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-18.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-12.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-15.0f, 7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-6.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-9.0f, 7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-12.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-9.0f, 7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-12.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-15.0f, 7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-18.0f, 5.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-12.0f, 5.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-15.0f, 7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-6.0f, 5.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-9.0f, 7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-12.0f, 5.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-9.0f, 7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-12.0f, 5.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-15.0f, 7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-18.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-18.0f, 5.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-15.0f, 7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-18.0f, 5.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-15.0f, 7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-15.0f, 7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	
	object->vertices.push_back({ vec4(-6.0f, 5.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-6.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-9.0f, 7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-9.0f, 7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-9.0f, 7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-6.0f, 5.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-9.0f, 7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-15.0f, 7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-9.0f, 7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(-15.0f, 7.0f, 20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-15.0f, 7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(-9.0f, 7.0f, -20.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
//Fin del tren

//Inicio letrero
	object->vertices.push_back({ vec4(6.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(16.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(6.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(16.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(6.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(6.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	
	object->vertices.push_back({ vec4(16.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(16.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(6.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	
	object->vertices.push_back({ vec4(6.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 5.0f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(6.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(6.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 1.5f, 0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//
	object->vertices.push_back({ vec4(6.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.5f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(16.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(15.5f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(6.5f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.5f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(15.5f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 1.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(15.5f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(6.0f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.5f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(16.0f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(15.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(6.5f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(15.5f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(15.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(6.0f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(6.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.0f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(6.5f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.5f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(6.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.5f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(6.5f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(16.0f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(16.0f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(16.0f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(15.5f, -4.5f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(15.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(15.5f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	object->vertices.push_back({ vec4(15.5f, -4.5f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(15.5f, 5.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vertices.push_back({ vec4(15.5f, 5.0f, -0.33f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	object->vista = vista;
	object->proyeccion = proyeccion;

}

void inicializarVista() {
	vista = lookAt(posicionCamara,           //Posicion de la cámara 
		vec3(0.0f, 3.0f, 0.0f),              //Posicion del objetivo
		vec3(0.0f, 1.0f, 0.0f));             //Vector hacia arriba (rotación cámara)
}

void inicializarProyeccion() {
	proyeccion =
		perspective(45.0f,   //Campo de visión (FoV)
			ancho / alto,    //Relación de aspecto (Aspect Ratio)
			0.1f,            //Near clipping (desde donde renderea)
			200.0f);         //Far clipping (asta donde renderea)
}

int main()
{
	//Inicialización de GLFW
	if (!glfwInit()) {
		//Si no se inició bien, terminar la ejecución
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verficar si se creó bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecución
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializó bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}


	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;

	red = green = blue = 0.5f;

	posicionCamara = vec3(x, y, z);

	inicializarVista();
	inicializarProyeccion();

	inicializarFigura();
	inicializarModelos();

	//crear instancia del shader
	const char * rutaVertex = "vShaderSimple.shader";
	const char * rutaFragment = "fShaderSimple.shader";

	shader = new  Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos 
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");
	ModeloID = glGetUniformLocation (shader->getID(), "modelo");
	vistaID = glGetUniformLocation(shader->getID(), "vista");
	proyeccionID = glGetUniformLocation(shader->getID(), "proyeccion");

	//Desenlazar el shader
	shader->desenlazarShader();

	

	object->shader = shader;
	object->inicializarVertexArray(posicionID, colorID,ModeloID,vistaID,proyeccionID);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla
		glClearColor(red, green, blue, 1);
		//Limpiar la pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar señales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

