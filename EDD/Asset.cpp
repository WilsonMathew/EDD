#include "Asset.h";
#include <iostream>;

using namespace std;

void Asset::setAssetId(string _id)
{
	assetId = _id;
}

void Asset::setAssetName(string _name)
{
	assetName = _name;
}

void Asset::setAssetDesc(string _desc)
{
	assetDesc = _desc;
}

string Asset::getAssetId() 
{
	return assetId;
}

string Asset::getAssetName()
{
	return assetName;
}

string Asset::getAssetDesc()
{
	return assetDesc;
}