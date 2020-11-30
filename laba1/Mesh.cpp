#include "Mesh.h"




Mesh::Mesh()
{

}

// �������� ���� �� ����� � ��������� ������
void Mesh::load(std::string filename)
{
	// ������ ��� �������� �������������� ���������
	vector<vec3> v;
	// ������ ��� �������� ��������
	vector<vec3> n;
	// ������ ��� �������� ���������� ���������
	vector<vec2> t;
	// ������ ��� �������� �������� ���������, ��� ���������� ������
	vector<ivec3> fPoints;
	map<string, int> vertexToIndexTable;

	GLuint lastIndex = 0;

	int key = 0;

	ifstream fileInput;
	fileInput.open(filename);
	if (fileInput.is_open()) {
		while (!fileInput.eof()) {
			string st = "";
			float fl1, fl2, fl3;
			int int1, int2, int3;
			fileInput >> st;
			//cout << st << endl;
			//cout << st << endl;
			if (st == "v") {
				fileInput >> fl1;
				fileInput >> fl2;
				fileInput >> fl3;
				v.push_back(vec3(fl1, fl2, fl3));
				//cout << "v\t" << fl1 << '\t' << fl2 << '\t' << fl3 << '\t' << endl;
			}
			if (st == "vn") {
				fileInput >> fl1;
				fileInput >> fl2;
				fileInput >> fl3;
				n.push_back(vec3(fl1, fl2, fl3));
				//cout << "vn\t" << fl1 << '\t' << fl2 << '\t' << fl3 << '\t' << endl;
			}
			if (st == "vt") {
				fileInput >> fl1;
				fileInput >> fl2;
				fileInput >> fl3;
				t.push_back(vec3(fl1, fl2, fl3));
				//cout << "vt\t" << fl1 << '\t' << fl2 << '\t' << fl3 << '\t' << endl;
			}
			if (st == "f") {
				for (int i = 0; i < 3; i++) {
					fileInput >> st;

					auto findTemp = vertexToIndexTable.find(st);
					if (findTemp != vertexToIndexTable.end()) { // ���� ������� �������
						// �������� � ������ �������� ��������
						indices.push_back(findTemp->second);
					}
					else { // ���� �� ������� �������
						// �������� � � map
						vertexToIndexTable.insert(pair<string, int>(st, key));

						// �������� ������� � fPoints
						stringstream tempString;
						tempString << st;
						getline(tempString, st, '/');
						int1 = stoi(st);
						getline(tempString, st, '/');
						int2 = stoi(st);
						getline(tempString, st, ' ');
						int3 = stoi(st);
						fPoints.push_back(ivec3(int1, int2, int3));

						// �������� � � ������ ��������
						indices.push_back(key++);
					}
				}
			}
		}
	}
	fileInput.close();

	for (auto& f : fPoints) {
		Vertex temp;
		temp.coord[0] = v[f.x - 1].x;
		temp.coord[1] = v[f.x - 1].y;
		temp.coord[2] = v[f.x - 1].z;
		temp.texCoord[0] = t[f.y - 1].x;
		temp.texCoord[1] = t[f.y - 1].y;
		temp.normal[0] = n[f.z - 1].x;
		temp.normal[1] = n[f.z - 1].y;
		temp.normal[2] = n[f.z - 1].z;
		vertices.push_back(temp);
	}

	
}

// ����� ���� (�������� ���� ������ � OpenGL)
void Mesh::draw()
{
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	//GLuint buffersId[2] = { 0,0 };
	//glGenBuffers(2, buffersId);

	//glBindBuffer(GL_ARRAY_BUFFER, buffersId[0]);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersId[1]);

	//glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), vertices[0].coord);
	glNormalPointer(GL_FLOAT, sizeof(Vertex), vertices[0].normal);
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), vertices[0].texCoord);
	//glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, indices.data());

	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_