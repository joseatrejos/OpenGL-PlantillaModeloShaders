// La primera l�nea debe ser la versi�n
#version 330 core

// Atributos de entrada (vienen desde c++)
in vec3 posicion;
in vec4 color;

// Atributos de salida (van hacia el fragment shader)
out vec4 fragmentColor;

// Funcion main
void main()
{
	// Es la posici�n de salida del v�rtice
	// Es del tipo vec4 (necesita posicion en 'x', 'y', 'z' y 'w')
	gl_Position.xyz = posicion;
	gl_Position.w = 1.0;

	// Establecer valores de atributos de salida
	fragmentColor = color;
}