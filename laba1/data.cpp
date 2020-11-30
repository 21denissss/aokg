#include "data.h"

// ������ ��������
vector<GraphicObject> graphicObjects = {
	{vec3(-4,0,0),0,vec3(0,0,1)},
	{vec3(4,0,0),180,vec3(1,0,0)},
	{vec3(0,0,4),270,vec3(1,1,1)},
	{vec3(0,0,-4),90,vec3(0,1,0)}
};

// ���������� ��� �������� ���

// ������
Camera camera(10.0, 50.0, 10);

PhongMaterial material;

vector<shared_ptr<PhongMaterial>> materials;

vector<shared_ptr<Mesh>> meshes;

int passabilityMap[21][21] = {
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,0,3,
	3,0,2,1,2,0,2,0,2,2,2,1,2,0,2,0,2,0,2,2,3,
	3,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,1,0,0,0,3,
	3,0,1,0,2,2,1,2,2,0,2,0,2,2,2,1,2,0,2,0,3,
	3,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,2,0,3,
	3,0,2,2,1,1,2,0,2,0,2,2,2,2,2,0,2,2,2,0,3,
	3,0,2,0,0,0,2,0,2,0,0,0,0,0,2,0,0,0,0,0,3,
	3,0,2,0,2,2,2,0,2,0,2,2,1,2,2,2,1,2,2,0,3,
	3,0,0,0,2,0,0,0,2,0,2,0,0,0,0,0,0,0,1,0,3,
	3,2,2,2,2,0,2,2,2,0,2,0,2,2,2,2,2,2,2,0,3,
	3,0,0,0,2,0,0,0,1,0,2,0,0,0,2,0,0,0,0,0,3,
	3,0,2,0,2,2,2,0,2,1,2,0,2,2,2,0,2,2,2,2,3,
	3,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,2,0,0,0,3,
	3,2,2,2,2,0,2,2,2,0,2,2,2,0,1,0,2,2,2,0,3,
	3,0,0,0,0,0,2,0,2,0,0,0,2,0,1,0,0,0,2,0,3,
	3,0,2,0,2,1,2,0,2,0,2,2,2,0,2,2,2,0,2,0,3,
	3,0,1,0,1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,3,
	3,0,2,1,2,0,2,2,2,2,2,0,2,0,2,0,2,2,2,2,3,
	3,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,0,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
};

Mesh test;

Light light;
// �������� �������� ������(������ � �������)
const float CAMERA_ROTATION_SPEED = 100.0;

const float CAMERA_ZOOM_SPEED = 20;

GraphicObject planeGraphicObject;

vector<ivec2>emptyPlaces;

// ������ ������� �������� ������������� �� �����
std::shared_ptr<GameObject> mapObjects[21][21];

shared_ptr<GameObject> player;


void init()
{
	light.setAmbient(vec4(0.4, 0.4, 0.4, 1.0));
	light.setDiffuse(vec4(1.0, 1.0, 1.0, 1.0));
	light.setSpecular(vec4(1.0, 1.0, 1.0, 1.0));
	light.setPosition(vec4(10.0, 10.0, 15.0, 1.0));
	// ������� ��� �������� ������� ��������
	GameObjectFactory gameObjectFactory;
	gameObjectFactory.init();

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			switch (passabilityMap[i][j]) {
			case 1:
				mapObjects[i][j] = gameObjectFactory.create(GameObjectType::LIGHT_OBJECT, i, j);
				break;
			case 2:
				mapObjects[i][j] = gameObjectFactory.create(GameObjectType::HEAVY_OBJECT, i, j);
				break;
			case 3:
				mapObjects[i][j] = gameObjectFactory.create(GameObjectType::BORDER_OBJECT, i, j);
				break;
			default:
				mapObjects[i][j] = nullptr;
				break;
			}
		}
	}
	// ������������� �������� �����
	player = gameObjectFactory.create(GameObjectType::PLAYER, 19, 1);

	// ������������� ���������
	planeGraphicObject.setPosition(vec3(0, 0, 0));
	shared_ptr<Mesh> planeMesh = make_shared<Mesh>();
	planeMesh->load("data\\meshes\\HighPolyPlane.obj");
	planeGraphicObject.setMesh(planeMesh);
	shared_ptr<PhongMaterial> planeMaterial = make_shared<PhongMaterial>();
	planeMaterial->load("data\\materials\\PlaneMaterial.txt");
	planeGraphicObject.setMaterial(planeMaterial);

}