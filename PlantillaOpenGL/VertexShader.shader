// La primera línea debe ser la versión
#version 330 core

// Atributos de entrada (vienen desde c++)
in vec4 posicion;
in vec4 color;

// Uniforms
uniform mat4 transformaciones;

// Atributos de salida (van hacia el fragment shader)
out vec4 fragmentColor;

// Funcion main
void main()
{
	// Es la posición de salida del vértice
	// Es del tipo vec4 (necesita posicion en 'x', 'y', 'z' y 'w')
	gl_Position = transformaciones * posicion;

	// Establecer valores de atributos de salida
	fragmentColor = color;
}