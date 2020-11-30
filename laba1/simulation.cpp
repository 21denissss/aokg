#include "simulation.h"

// ‘ункци€ симул€ции камеры
LARGE_INTEGER prevTimeSim, currTimeSim, incFrequncySim;

double getSimulationTime()
{

	QueryPerformanceCounter(&currTimeSim);
	QueryPerformanceFrequency(&incFrequncySim);
	float temp = double(currTimeSim.QuadPart - prevTimeSim.QuadPart) / double(incFrequncySim.QuadPart);
	prevTimeSim = currTimeSim;
	return temp;
}

void simulationCamera(float simulationTime)
{
	float tempSpeedRotation = CAMERA_ROTATION_SPEED * simulationTime;
	float tempSpeedZoom = CAMERA_ZOOM_SPEED * simulationTime;
	if (GetAsyncKeyState(VK_LEFT)) {
		camera.rotateLeftRight(-tempSpeedRotation);
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		camera.rotateLeftRight(tempSpeedRotation);
	}
	if (GetAsyncKeyState(VK_SUBTRACT)) {
		camera.zoomInOut(-tempSpeedZoom);
	}
	if (GetAsyncKeyState(VK_ADD)) {
		camera.zoomInOut(tempSpeedZoom);
	}
	if (GetAsyncKeyState(VK_UP)) {
		camera.rotateUpDown(tempSpeedRotation);
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		camera.rotateUpDown(-tempSpeedRotation);
	}
};

// функци€ вызываетс€ каждые 20 мс
void simulation()
{	
	float simulationTime = getSimulationTime();
	auto player = passabilityMap[19][1];
	simulationCamera(simulationTime);
	// left
	if (GetAsyncKeyState(0x41)) {
		/*player->*/
	}
	// устанавливаем признак того, что окно нуждаетс€ в перерисовке
	glutPostRedisplay();

};