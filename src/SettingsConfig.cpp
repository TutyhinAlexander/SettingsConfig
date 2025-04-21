#include "SettingsConfig/SettingsConfig.h"
#include "Logger/Logger.h"

using namespace DebugTools;

namespace Tools
{
	bool SettingsConfig::Load(const char* configFilePath)
	{
		try
		{
			cfg.readFile(configFilePath);
			Logger::Log("SettingsConfig::Load Configuration successfully loaded from: '%s'\n", configFilePath);
		}
		catch(const FileIOException &fioex)
		{
			Logger::Log("SettingsConfig::Load I/O error while reading file.");
			return false;
		}
		catch(const ParseException &pex)
		{
			Logger::Log("SettingsConfig::Load Parse error at '%s' : %d - '%s'", pex.getFile(), pex.getLine(), pex.getError());
			return false;
		}
		return true;
	}
		
	void SettingsConfig::Save(const char* configFilePath)
	{
		try
		{
			cfg.writeFile(configFilePath);
			Logger::Log("SettingsConfig::Save Updated configuration successfully written to: '%s'\n", configFilePath);

		}
		catch(const FileIOException &fioex)
		{
			Logger::Log("SettingsConfig::Save I/O error while writing file: '%s'\n", configFilePath);
		}
	}
	
	bool SettingsConfig::GetInt(const char* path, int& result) 
	{
		bool success = cfg.lookupValue(path, result);
		Logger::Log("  '%s' = %d\n", path, result);
		return success;
	}
	
	int SettingsConfig::GetInt(const char* path)
	{
		return GetValue<int>(path);
	}
			
	void SettingsConfig::SetInt(const char* path, int value)
	{
		cfg.lookup(path) = value;
	}
	
	bool SettingsConfig::GetFloat(const char* path, float& result)
	{
		bool success = cfg.lookupValue(path, result);
		Logger::Log("  '%s' = %f\n", path, result);
		return success;
	}
												
	float SettingsConfig::GetFloat(const char* path)
	{
		return GetValue<float>(path);
	}
			
	void SettingsConfig::SetFloat(const char* path, float value)
	{
		cfg.lookup(path) = value;
	}
	
	bool SettingsConfig::GetBool(const char* path, bool& result)
	{
		bool success = cfg.lookupValue(path, result);
		Logger::Log("  '%s' = '%s'\n", path, result ? "true" : "false");
		return success;
	}
	
	bool SettingsConfig::GetBool(const char* path)
	{
		return GetValue<bool>(path);
	}
	
	void SettingsConfig::SetBool(const char* path, bool value)
	{
		cfg.lookup(path) = value;
	}
	
	bool SettingsConfig::GetString(const char* path, const char* result)
	{
		bool success = cfg.lookupValue(path, result);
		Logger::Log("  '%s' = '%s'\n", path, result);
		return success;
	}
	
	bool SettingsConfig::GetString(const char* path, std::string& result)
	{
		bool success = cfg.lookupValue(path, result);
		Logger::Log("  '%s' = '%s'\n", path, result.c_str());
		return success;
	}	
			
	const char* SettingsConfig::GetString(const char* path)
	{
		return GetValue<const char*>(path);
	}
			
	void SettingsConfig::SetString(const char* path, const char* value)
	{
		cfg.lookup(path) = value;
	}
	
	void SettingsConfig::SetString(const char* path, std::string value)
	{
		cfg.lookup(path) = value;
	}	

}
