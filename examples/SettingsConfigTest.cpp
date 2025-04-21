// Example of using SettingsConfig library


#include "SettingsConfig/SettingsConfig.h"
#include "Logger/Logger.h"
#include <string>

using namespace Tools;
using namespace DebugTools;

const char* CONFIG_PATH = "settings.cfg";

void InitLogger()
{
	Logger::Log("InitLogger\n");
	LoggerParams params;
	params.useTimestamp = false;
	params.logToConsole = true;
	//params.fileName = "SCT";
	//params.maxLogFiles = 10;
	Logger::Init(params);
}


int main()
{
	InitLogger();
	Logger::Log("START...\n");	
	
	SettingsConfig sc;
	sc.Load(CONFIG_PATH);
	
	int intVal;
	float floatVal;
	std::string strVal;
	bool boolVal;
	
	Logger::Log("load data from '%s':\n", CONFIG_PATH);
	
	sc.GetInt("root.section.int_setting", intVal);
	Logger::Log("  intVal=%d\n", intVal);
	
	sc.GetFloat("root.section.float_setting", floatVal);
	Logger::Log("  floatVal=%f\n", floatVal);
	
	sc.GetString("root.section.string_setting", strVal);
	Logger::Log("  stringVal='%s'\n", strVal.c_str());
	
	sc.GetBool("root.section.bool_setting", boolVal);
	Logger::Log("  boolVal=%s\n", boolVal ? "true" : "false");
	
	
	Logger::Log("Save data to '%s':\n", CONFIG_PATH);
	intVal += 50;
	sc.SetInt("root.section.int_setting", intVal);
	sc.Save(CONFIG_PATH);
	
	
	Logger::Log("END\n");
	return 0;
}
