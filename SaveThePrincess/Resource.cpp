#include "Resource.h"
#include "ResourceFile.h"

void Resource::Load(ResourceFile& aFile) {
	LoadID(aFile);
	LoadImpl(aFile);
}

void Resource::LoadID(ResourceFile& aFile) {

}