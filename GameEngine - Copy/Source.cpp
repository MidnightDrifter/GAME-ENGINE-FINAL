#include <Windows.h>
#include "..\..\SDL\include\SDL.h"
#include "..\..\SDL\include\SDL_error.h"
#include "..\..\SDL\include\SDL_main.h"
#include "..\..\SDL\include\SDL_image.h"
#include <stdio.h>
#include <string>
#include "InputManager.h"
#include "ResourceManager.h"
#include "FramerateController.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Transform.h"
#include "Component.h"
#include "Controller.h"
#include "UpDown.h"
//#undef main

#define WINDOW_X_POS 500
#define WINDOW_Y_POS 100
#define WINDOW_NAME "FLOWEYTALE"
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 500
#define MAX_FRAMERATE 60  //In seconds
#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 365

 ResourceManager ResourceMgr = ResourceManager();
InputManager InputMgr = InputManager();
FramerateController FrameCrtl = FramerateController(60);

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
int main(int argc, char* argv[])
{
	std::string pic = "Resources\\darkpursuit.png";
	Sprite* image = new Sprite(pic);
	Controller* controller = new Controller();
	Transform* transform = new Transform(100, 100);
	UpDown* upDown = new UpDown();

	

	//SDL_Surface* upWinSurface = ResourceMgr.loadSurface("Resources\\darkpursuit.png");
	//SDL_Surface* downWinSurface = ResourceMgr.loadSurface("Resources\\dark_pursuit_small_down.png");
	//SDL_Surface* leftWinSurface = ResourceMgr.loadSurface("Resources\\dark_pursuit_small_left.png");
	//SDL_Surface* rightWinSurface = ResourceMgr.loadSurface("Resources\\dark_pursuit_small_right.png");

	GameObject zoroark = GameObject();
	zoroark.addComponent(image);
	zoroark.addComponent(controller);
	zoroark.addComponent(transform);
	//zoroark.addComponent(upDown);
	
	bool run = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
	{
		printf("Unable to initialize SDL. \n");
		exit(-1);
	}

	//Remember, position is based from the top left corner of the screen
	SDL_Window*  pWindow = SDL_CreateWindow(WINDOW_NAME, WINDOW_X_POS, WINDOW_Y_POS, WINDOW_WIDTH, WINDOW_HEIGHT, 0); //SDL_WINDOW_OPENGL);
	SDL_Surface* pWinSurface = SDL_GetWindowSurface(pWindow);
	int frameTime = 0;

	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == -1)
	{
		printf("Error, unable to initialize SDL_IMG\n");
		exit(222);
	}

	while (run)
	{
		frameTime = FrameCrtl.getFrameTime();
		FrameCrtl.FrameStart();

		
		InputMgr.Update();
//		SDL_Surface* pImage = upWinSurface;      //SDL_LoadBMP("darkpursuit.bmp");
	   //SDL_Surface* pImage = IMG_Load("Resources\\darkpursuit.png");
/*
		if (InputMgr.isKeyPressed(SDL_SCANCODE_DOWN))
		{
			pImage = downWinSurface;
		}

		if (InputMgr.isKeyPressed(SDL_SCANCODE_RIGHT))
		{
			pImage = rightWinSurface;
		}

		if (InputMgr.isKeyPressed(SDL_SCANCODE_LEFT))
		{
			pImage = leftWinSurface;
		}
		*/
		if (InputMgr.isKeyPressed(SDL_SCANCODE_ESCAPE))
		{
			run = false;
		}

		

		Sprite* spr = static_cast<Sprite*>(zoroark.getSprite());
		Transform* trs = static_cast<Transform*>(zoroark.getTransform());
		if (image->getSprite() == NULL)
		{
			exit(123);
		}
		
		/*if (spr->getSprite() == NULL)
		{

			printf("Error:  unable to load image %s. \n  Error log:  %s \n", "darkpursuit.png", SDL_GetError());
			exit(111);
		}
		*/
		

		
	//	SDL_Rect r = { trs->getX(), trs->getY(), IMAGE_WIDTH, IMAGE_HEIGHT };
		SDL_Rect r = { transform->getX(), transform->getY(), IMAGE_WIDTH, IMAGE_HEIGHT };
		// dynamic_cast<Transform*>(zoroark.getTransform())->getX()
		SDL_FillRect(pWinSurface, NULL, 0);
		SDL_BlitSurface(image->getSprite(),NULL, pWinSurface, &r);
		

		SDL_UpdateWindowSurface(pWindow);
		
		controller->Update(transform);
		//upDown->Update(transform);
		
		
		//zoroark.update();
		
		SDL_PumpEvents();
		FrameCrtl.FrameEnd();
	}
	exit(1);
}