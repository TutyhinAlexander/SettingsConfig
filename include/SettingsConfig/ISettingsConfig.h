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
				
			virtual bool GetInt(const char* path, int& result) = 0;
			virtual int GetInt(const char* path) = 0;
			virtual	void SetInt(const char* path, int value) = 0;

			virtual bool GetFloat(const char* path, float& result) = 0;
			virtual	float GetFloat(const char* path) = 0;
			virtual	void SetFloat(const char* path, float value) = 0;
			
			virtual bool GetBool(const char* path, bool& result) = 0;
			virtual	bool GetBool(const char* path) = 0;
			virtual	void SetBool(const char* path, bool value) = 0;			
				
			virtual bool GetString(const char* path, const char* result) = 0;
			virtual bool GetString(const char* path, std::string& result) = 0;
			virtual	const char* GetString(const char* path) = 0;
			virtual	void SetString(const char* path, const char* value) = 0;
			virtual	void SetString(const char* path, std::string value) = 0;
	};
}

#endif // __ISETTINGS_CONFIG_H_
