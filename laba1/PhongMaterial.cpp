#include "PhongMaterial.h"

// конструктор по умолчанию
PhongMaterial::PhongMaterial()
{

}

// задание параметров материала
void PhongMaterial::setAmbient(vec4 color)
{
	ambient = color;
}

void PhongMaterial::setDiffuse(vec4 color)
{
	diffuse = color;
}

void PhongMaterial::setSpecular(vec4 color)
{
	specular = color;
}

void PhongMaterial::setEmission(vec4 color)
{
	emission = color;
}

void PhongMaterial::setShininess(float p)
{
	shininess = p;
}

// загрузка параметров материала из внешнего текстового файла
void PhongMaterial::load(std::string filename)
{
	ifstream fileInput;
	fileInput.open(filename);
	if (fileInput.is_open()) {
		while (!fileInput.eof()) {
			string st = "";
			string st1, st2, st3, st4;
			float fl1, fl2, fl3, fl4;
			fileInput >> st;
			if (!st.find("diffuse:")) {
				fileInput >> fl1;
				fileInput >> fl2;
				fileInput >> fl3;
				fileInput >> fl4;
				setDiffuse(vec4(fl1, fl2, fl3, fl4));

			}
			if (!st.find("ambient:")) {
				fileInput >> fl1;
				fileInput >> fl2;
				fileInput >> fl3;
				fileInput >> fl4;
				setAmbient(vec4(fl1, fl2, fl3, fl4));

			}
			if (!st.find("specular:")) {
				fileInput >> fl1;
				fileInput >> fl2;
				fileInput >> fl3;
				fileInput >> fl4;
				setSpecular(vec4(fl1, fl2, fl3, fl4));

			}
			if (!st.find("emission:")) {
				fileInput >> fl1;
				fileInput >> fl2;
				fileInput >> fl3;
				fileInput >> fl4;
				setEmission(vec4(fl1, fl2, fl3, fl4));

			}
			if (!st.find("shininess:")) {
				fileInput >> fl1;
				setShininess(fl1);
			}
		}
	}
	fileInput.close();

}

// установка всех параметров материала
void PhongMaterial::apply()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, value_ptr(ambient));
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, value_ptr(diffuse));
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, value_ptr(specular));
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, value_ptr(emission));
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &shininess);
}