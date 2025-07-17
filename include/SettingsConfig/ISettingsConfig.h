#ifndef __ISETTINGS_CONFIG_H_
#define __ISETTINGS_CONFIG_H_

#include <string>

namespace Tools
{
	class ISettingsConfig
	{
		public:
			virtual bool Load(const char* configFilePath) = 0;
			virtual	void Save(const char* configFilePath) = 0;
				
			virtual bool GetInt(const char* path, int& result, int defaultVal) = 0;
			virtual int GetInt(const char* path, int defaultVal) = 0;
			virtual	void SetInt(const char* path, int value) = 0;

			virtual bool GetFloat(const char* path, float& result, float defaultVal) = 0;
			virtual	float GetFloat(const char* path, float defaultVal) = 0;
			virtual	void SetFloat(const char* path, float value) = 0;
			
			virtual bool GetBool(const char* path, bool& result, bool defaultVal) = 0;
			virtual	bool GetBool(const char* path, bool defaultVal) = 0;
			virtual	void SetBool(const char* path, bool value) = 0;			
				
			virtual bool GetString(const char* path, const char* result, const char* defaultVal) = 0;
			virtual bool GetString(const char* path, std::string& result, std::string defaultVal) = 0;
			virtual	const char* GetString(const char* path, const char* defaultVal) = 0;
			virtual	void SetString(const char* path, const char* value) = 0;
			virtual	void SetString(const char* path, std::string value) = 0;
			
			//   inventory = ({id = 0; name = "item1"; price = 10; rare = false;}, {id = 1; name = "item1"; price = 20; rare = true;} );
			virtual int GetDataArrayLength(const char* path) = 0;
			virtual int GetDataArrayItemIntField(const char* arrayPath, int itemIndex, const char* fieldName, int defVal) = 0;
			virtual float GetDataArrayItemFloatField(const char* arrayPath, int itemIndex, const char* fieldName, float defVal) = 0;
			virtual bool GetDataArrayItemBoolField(const char* arrayPath, int itemIndex, const char* fieldName, bool defVal) = 0;
			virtual const char* GetDataArrayItemStringField(const char* arrayPath, int itemIndex, const char* fieldName, const char* defVal) = 0;
	};
}

#endif // __ISETTINGS_CONFIG_H_
