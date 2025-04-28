#include "SettingsConfig/SettingsConfig.h"
#include "Logger/Logger.h"

using namespace DebugTools;
using namespace std;

namespace Tools
{
	bool SettingsConfig::Load(const char* configFilePath)
	{
		try
		{
			cfg.readFile(configFilePath);
			LOG("SettingsConfig::Load Configuration successfully loaded from: '%s'\n", configFilePath);
		}
		catch(const FileIOException &fioex)
		{
			LOG("SettingsConfig::Load I/O error while reading file.");
			return false;
		}
		catch(const ParseException &pex)
		{
			LOG("SettingsConfig::Load Parse error at '%s' : %d - '%s'", pex.getFile(), pex.getLine(), pex.getError());
			return false;
		}
		return true;
	}
		
	void SettingsConfig::Save(const char* configFilePath)
	{
		try
		{
			cfg.writeFile(configFilePath);
			LOG("SettingsConfig::Save Updated configuration successfully written to: '%s'\n", configFilePath);

		}
		catch(const FileIOException &fioex)
		{
			LOG("SettingsConfig::Save I/O error while writing file: '%s'\n", configFilePath);
		}
	}
	
	bool SettingsConfig::GetInt(const char* path, int& result, int defaultVal) 
	{
		return GetValue<int>(path, result, defaultVal);
	}
	
	int SettingsConfig::GetInt(const char* path, int defaultVal)
	{
		return GetValue<int>(path);
	}
			
	void SettingsConfig::SetInt(const char* path, int value)
	{
		SetValue<int>(path, value, Setting::TypeInt);
	}
	
	bool SettingsConfig::GetFloat(const char* path, float& result, float defaultVal)
	{
		return GetValue<float>(path, result, defaultVal);
	}
												
	float SettingsConfig::GetFloat(const char* path, float defaultVal)
	{
		return GetValue<float>(path);
	}
			
	void SettingsConfig::SetFloat(const char* path, float value)
	{
		SetValue<float>(path, value, Setting::TypeFloat);
	}
	
	bool SettingsConfig::GetBool(const char* path, bool& result, bool defaultVal)
	{
		return GetValue<bool>(path, result, defaultVal);
	}
	
	bool SettingsConfig::GetBool(const char* path, bool defaultVal)
	{
		return GetValue<bool>(path);
	}
	
	void SettingsConfig::SetBool(const char* path, bool value)
	{
		SetValue<bool>(path, value, Setting::TypeBoolean);
	}
	
	bool SettingsConfig::GetString(const char* path, const char* result, const char* defaultVal)
	{
		return GetValue<const char*>(path, result, defaultVal);
	}
	
	bool SettingsConfig::GetString(const char* path, string& result, string defaultVal)
	{
		return GetValue<string>(path, result, defaultVal);
	}	
			
	const char* SettingsConfig::GetString(const char* path, const char* defaultVal)
	{
		return GetValue<const char*>(path);
	}
			
	void SettingsConfig::SetString(const char* path, const char* value)
	{
		SetValue<const char*>(path, value, Setting::TypeString);
	}
	
	void SettingsConfig::SetString(const char* path, string value)
	{
		SetValue<string>(path, value, Setting::TypeString);
	}	

}
