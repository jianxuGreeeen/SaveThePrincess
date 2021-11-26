#include "ResourceDB.h"
#include "../Resource/WeaponResource.h"
#include "../Resource/ActorResource.h"
#include "../Resource/LevelResource.h"
#include "../Objects/ResourceFile.h"

/// <summary>
/// </summary>
/// <param name="File"></param>
/// <returns></returns>
bool ResourceDB::Load(const std::string& FilePath) {
	bool startedLoad = false;

	std::exception_ptr exception;
	bool validationSuccess = false;
	// Idea is to use a helper class to read in the file 
	// and turn that into resources. 
	// Here, we would theoretically end up with the data
	// mentioned in the pdf:

	// Character    Health      Armor       Weapon          Movement
	// Player       100         100         Shotgun         Ground
	// Princess     80          0           None            Ground
	// Boss         500         100         Fireball/Axe    Ground/Air
	// Squab        50          0           Bomb            Air
	// Turtle       60          50          Shell Rock      Ground
	// Puffer       60          20          Poison Touch    Water
	
	ResourceFile File(FilePath);
	try {
		File.Open();
		while (File.HasNextResource()) {
			Resource* presource = File.LoadNextResource();
			AddResourceToDB(presource);
		}
		File.Close();

		validationSuccess = ValidateResourceOfType(ResourceClass::ActorResource);
		validationSuccess &= ValidateResourceOfType(ResourceClass::WeaponResource);
		validationSuccess &= ValidateResourceOfType(ResourceClass::LevelResource);

		validationSuccess &= FindAndCachePlayer();
		validationSuccess &= FindAndCacheLevelList();
	}
	catch (std::exception e) {
		exception = std::current_exception();
		File.Close();
	}

	return exception != nullptr && validationSuccess;
}