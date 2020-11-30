#include "GameObjectFactory.h"

void GameObjectFactory::init()
{
	//materials.push_back(make_shared<PhongMaterial>());
	//materials.back()->load("data/materials/material_1.txt");

	//materials.push_back(make_shared<PhongMaterial>());
	//materials.back()->load("data/materials/material_2.txt");

	//materials.push_back(make_shared<PhongMaterial>());
	//materials.back()->load("data/materials/material_3.txt");

	//materials.push_back(make_shared<PhongMaterial>());
	//materials.back()->load("data/materials/material_4.txt");

	auto filename = "data/GameObjectsDescription.json";
	ifstream f(filename);
	if (!f.is_open()) {
		cout << "Не уадется найти файл " << filename << endl;
		return;
	}

	string jsonString;
	getline(f, jsonString, static_cast<char>(0));
	f.close();

	Document document;
	document.Parse(jsonString.c_str());

	int key = 0;

	for (auto& obj : document.GetObject()) {
		//cout << obj.name.GetString() << " : ";
		auto meshName = document[obj.name.GetString()]["mesh"].GetString();
		meshes.push_back(make_shared<Mesh>());
		meshes.back()->load(meshName);
		auto materialObj = document[obj.name.GetString()]["material"].GetObject();
		materials.push_back(make_shared<PhongMaterial>());
		for (auto& objMaterial : materialObj) {
			if (objMaterial.value.IsArray())
			{
				//cout << objMaterial.name.GetString() << endl;
				auto arr = objMaterial.value.GetArray();
				vec4 tempVect = { arr[0].GetFloat(),arr[1].GetFloat(), arr[2].GetFloat(), arr[3].GetFloat() };
				if (objMaterial.name.GetString() == string("diffuse"))
					materials.back()->setDiffuse(tempVect);
				if (objMaterial.name.GetString() == string("ambient"))
					materials.back()->setAmbient(tempVect);
				if (objMaterial.name.GetString() == string("specular"))
					materials.back()->setSpecular(tempVect);
				if (objMaterial.name.GetString() == string("emission"))
					materials.back()->setEmission(tempVect);
				//cout << endl;
			}
			else
			{
				auto shininess = objMaterial.value.GetFloat();
				materials.back()->setShininess(shininess);
				//cout << shininess << endl;
			}
		}
		cout << obj.name.GetString() << endl;
		if (obj.name.GetString() == string("LightObject")) {
			thisMap.insert(pair<GameObjectType, int>(GameObjectType::LIGHT_OBJECT,key));
		}
		if (obj.name.GetString() == string("HeavyObject")) {
			thisMap.insert(pair<GameObjectType, int>(GameObjectType::HEAVY_OBJECT, key));

		}
		if (obj.name.GetString() == string("BorderObject")) {
			thisMap.insert(pair<GameObjectType, int>(GameObjectType::BORDER_OBJECT, key));

		}
		if (obj.name.GetString() == string("Player")) {
			thisMap.insert(pair<GameObjectType, int>(GameObjectType::PLAYER, key));

		}
		if (obj.name.GetString() == string("Bomb")) {
			thisMap.insert(pair<GameObjectType, int>(GameObjectType::BOMB, key));

		}
		if (obj.name.GetString() == string("Monster")) {
			thisMap.insert(pair<GameObjectType, int>(GameObjectType::MONSTER, key));

		}
		key++;
	}

	if (document.GetParseError() != 0) {
		cout << "неверный формат файла\n";
		return;
	}
}
// создание нового объекта заданного типа
std::shared_ptr<GameObject> GameObjectFactory::create(GameObjectType type, int x, int y)
{
	GraphicObject go;
	switch (type)
	{
	case GameObjectType::LIGHT_OBJECT:
		go.setMesh(meshes[thisMap[GameObjectType::LIGHT_OBJECT]]);
		go.setMaterial(materials[thisMap[GameObjectType::LIGHT_OBJECT]]);
		break;
	case GameObjectType::HEAVY_OBJECT:
		go.setMesh(meshes[thisMap[GameObjectType::HEAVY_OBJECT]]);
		go.setMaterial(materials[thisMap[GameObjectType::HEAVY_OBJECT]]);
		break;
	case GameObjectType::BORDER_OBJECT:
		go.setMesh(meshes[thisMap[GameObjectType::BORDER_OBJECT]]);
		go.setMaterial(materials[thisMap[GameObjectType::BORDER_OBJECT]]);
		break;
	case GameObjectType::PLAYER:
		go.setMesh(meshes[thisMap[GameObjectType::PLAYER]]);
		go.setMaterial(materials[thisMap[GameObjectType::PLAYER]]);
		break;
	case GameObjectType::BOMB:
		go.setMesh(meshes[thisMap[GameObjectType::BOMB]]);
		go.setMaterial(materials[thisMap[GameObjectType::BOMB]]);
		break;
	case GameObjectType::MONSTER:
		go.setMesh(meshes[thisMap[GameObjectType::MONSTER]]);
		go.setMaterial(materials[thisMap[GameObjectType::MONSTER]]);
		break;
	default:
		break;
	}

	shared_ptr<GameObject> newObject = make_shared<GameObject>();
	newObject->setGraphicObject(go);
	newObject->setPosition(x, y);
	return newObject;
}