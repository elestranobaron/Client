#include "pch.h"
#include "TileSet.h"
#include "TFCLandDef.h"


//////////////////////////////////////////////////////////////////////////////////////////
// DaP ajout
//////////////////////////////////////////////////////////////////////////////////////////
#include "SaveGame.h"
extern CSaveGame g_SaveGame;



// void Register(int COULEUR_SYSTEM, char *NOM_DANS_VSF, int GRANULARITY);

void TileSet::Mathieu(void) {

      Register(WOODEN, "Fence", 3, 2);

}




//////////////////////////////////////////////////////////////////////////////////////////
// DaP ajout
//////////////////////////////////////////////////////////////////////////////////////////
TileSet * TileSet::GetInstance()
{
	static TileSet instance;
	return &instance;
}

int TileSet::GetDONE()
{
	if (g_SaveGame.GetOptionsParam()->bEnable32FPS)
	{
		return 8;
	}
	return 4;
}

int TileSet::GetMOVX()
{
	if (g_SaveGame.GetOptionsParam()->bEnable32FPS)
	{
		return 4;
	}
	return 8;
}

int TileSet::GetMOVY()
{
	if (g_SaveGame.GetOptionsParam()->bEnable32FPS)
	{
		return 2;
	}
	return 4;
}

int TileSet::GetFPSFRAMING()
{
	if (g_SaveGame.GetOptionsParam()->bEnable32FPS)
	{
		return 2;
	}
	return 1;
}

int TileSet::GetFPS()
{
	if (g_SaveGame.GetOptionsParam()->bEnable32FPS)
	{
		return 34;
	}
		return 17;
}