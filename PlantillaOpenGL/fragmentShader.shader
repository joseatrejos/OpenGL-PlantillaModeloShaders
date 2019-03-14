// La primer linea debe ser la versi�n
#version 330 core

// Atributos de entrada (vienen desde el Vertex Shader)
in vec4 fragmentColor;

// Atributos de salida (van hacia el b�fer)
out vec4 salidaColor;

// Funci�n main
void main()
{
	salidaColor = fragmentColor;
}