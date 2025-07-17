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
			
			template<class T>
			T GetDataArrayItemField(const char* arrayPath, int itemIndex, const char* fieldName, T defaultVal = T())
			{
				try
				{
					return cfg.lookup(arrayPath)[itemIndex].lookup(fieldName);
				}
				catch(const SettingNotFoundException &nfex)
				{
					Logger::Log("Setting not found: '%s' itemIndex=%d fieldName='%s'\n", arrayPath, itemIndex, fieldName);
				}
				catch(const SettingTypeException tex)
				{
					Logger::Log("Setting type exception: '%s' itemIndex=%d fieldName='%s'\n", arrayPath, itemIndex, fieldName);
				}
				return defaultVal;
			}
			
		public:
			virtual bool Load(const char* configFilePath);
			virtual void Save(const char* configFilePath);
			
			virtual bool GetInt(const char* path, int& result, int defaultVal);
			virtual int GetInt(const char* path, int defaultVal);
			virtual void SetInt(const char* path, int value);
												
			virtual bool GetFloat(const char* path, float& result, float defaultVal);
			virtual float GetFloat(const char* path, float defaultVal);
			virtual void SetFloat(const char* path, float value);
			
			virtual bool GetBool(const char* path, bool& result, bool defaultVal);
			virtual bool GetBool(const char* path, bool defaultVal);
			virtual void SetBool(const char* path, bool value);
			
			virtual bool GetString(const char* path, const char* result, const char* defaultVal);
			virtual bool GetString(const char* path, string& result, string defaultVal);
			virtual const char* GetString(const char* path, const char* defaultVal);
			virtual void SetString(const char* path, const char* value);
			virtual void SetString(const char* path, std::string value);
			
			virtual int GetDataArrayLength(const char* path);
			virtual int GetDataArrayItemIntField(const char* arrayPath, int itemIndex, const char* fieldName, int defVal);
			virtual float GetDataArrayItemFloatField(const char* arrayPath, int itemIndex, const char* fieldName, float defVal);
			virtual bool GetDataArrayItemBoolField(const char* arrayPath, int itemIndex, const char* fieldName, bool defVal);
			virtual const char* GetDataArrayItemStringField(const char* arrayPath, int itemIndex, const char* fieldName, const char* defVal);
	};
}

#endif // __SETTINGS_CONFIG_H_
