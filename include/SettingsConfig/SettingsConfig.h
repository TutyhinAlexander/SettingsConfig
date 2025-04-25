#ifndef __SETTINGS_CONFIG_H_
#define __SETTINGS_CONFIG_H_

#include "Logger/Logger.h"
#include "SettingsConfig/ISettingsConfig.h"
#include <libconfig.h++>
#include <string>

using namespace std;
using namespace libconfig;
using namespace DebugTools;

namespace Tools
{
	class SettingsConfig : public ISettingsConfig
	{
		private:
			Config cfg;
			
			
			template<class T>
			bool GetValue(const char* path, T& result, T defaultVal)
			{
				bool success = cfg.lookupValue(path, result);
				if(!success)
					result = defaultVal;
				return success;
			}
			
			template<class T>
			T GetValue(const char* path)
			{
				try
				{
					return cfg.lookup(path);
				}
				catch(const SettingNotFoundException &nfex)
				{
					Logger::Log("Setting not found: '%s'\n", path);
				}
				catch(const SettingTypeException tex)
				{
					Logger::Log("Setting type exception: '%s'\n", path);
				}
				return T();
			}

			template<class T>
			void SetValue(const char* path, T value, Setting::Type type)
			{
				try
				{
					cfg.lookup(path) = value;
				}
				catch(SettingNotFoundException &ex)
				{
					Logger::Log("SettingsConfig::SetValue exception '%s' path: '%s'\n", ex.what(), ex.getPath());
					string srcPath(path);
					size_t found = srcPath.rfind('.');
					if (found != string::npos)
					{
						string parentPath = srcPath.substr(0, found);
						string settingName = srcPath.substr(found + 1);
						Logger::Log("SettingsConfig::SetValue parentPath '%s' settingName: '%s'\n", parentPath.c_str(), settingName.c_str());
			
						Setting& parentSetting = cfg.lookup(parentPath);
						parentSetting.add(settingName, type) = value;
					}
				}
			}
			
		public:
			bool Load(const char* configFilePath);
			void Save(const char* configFilePath);
			
			bool GetInt(const char* path, int& result, int defaultVal);
			int GetInt(const char* path, int defaultVal);
			void SetInt(const char* path, int value);
												
			bool GetFloat(const char* path, float& result, float defaultVal);
			float GetFloat(const char* path, float defaultVal);
			void SetFloat(const char* path, float value);
			
			bool GetBool(const char* path, bool& result, bool defaultVal);
			bool GetBool(const char* path, bool defaultVal);
			void SetBool(const char* path, bool value);
			
			bool GetString(const char* path, const char* result, const char* defaultVal);
			bool GetString(const char* path, string& result, string defaultVal);
			const char* GetString(const char* path, const char* defaultVal);
			void SetString(const char* path, const char* value);
			void SetString(const char* path, std::string value);
			
	};
}

#endif // __SETTINGS_CONFIG_H_
