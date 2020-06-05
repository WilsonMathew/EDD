#pragma once
#include <string>;

using namespace std;

class Asset
{
private:
	string assetId;
	string assetName;
	string assetDesc;
public:
	void setAssetId(string id);
	void setAssetName(string name);
	void setAssetDesc(string desc);

	string getAssetId();
	string getAssetName();
	string getAssetDesc();
};