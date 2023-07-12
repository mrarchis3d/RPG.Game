#pragma once

#include "CoreMinimal.h"
#include "MenuInterface.generated.h"

struct FServerData;
UINTERFACE(MinimalAPI)
class UMenuInterface: public UInterface
{
	GENERATED_BODY()
};

/**
* Handle various menu functions
*/

class RPG_API IMenuInterface
{
	GENERATED_BODY()
public:
	virtual void Join(const FServerData& InServerData) =0;
	virtual void StartGame() =0;
	virtual void LoadMainMenu()=0;
	virtual void LoadLoginMenu()=0;
};
