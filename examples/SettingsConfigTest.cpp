// Example of using SettingsConfig library


#include "SettingsConfig/SettingsConfig.h"
#include "SettingsConfig/SettingsWindow.h"
#include "Logger/Logger.h"
#include <string>

using namespace Tools;
using namespace DebugTools;

const char* CONFIG_PATH = "settings.cfg";

SettingsConfig sc;
int intVal;
float floatVal;
std::string strVal;
bool boolVal;

void InitLogger()
{
	LOG("InitLogger\n");
	LoggerParams params;
	params.useTimestamp = false;
	params.logToConsole = true;
	params.fileName = "SCT";
	params.maxLogFiles = 10;
	Logger::Init(params);
}

void OnSaveClicked(int state, void *userdata)
{
	LOG("Save data to '%s':\n", CONFIG_PATH);
	
	sc.SetInt("root.section.int_setting", intVal);
	sc.SetFloat("root.section.float_setting", floatVal);
	sc.SetBool("root.section.bool_setting", boolVal);
	
	sc.Save(CONFIG_PATH);	
}

int main()
{
	InitLogger();
	LOG("START...\n");	
	
	sc.Load(CONFIG_PATH);
	
	namedWindow("Image", WINDOW_NORMAL);	
	SettingsWindow ctrlBar;
	
	LOG("load data from '%s':\n", CONFIG_PATH);
	
	ctrlBar.AddButton("Save", OnSaveClicked, NULL);
	
	sc.GetInt("root.section.int_setting", intVal, 0);
	LOG("  intVal=%d\n", intVal);
	ctrlBar.AddTrackbar("Int Val:", intVal, 2000);
	
	sc.GetFloat("root.section.float_setting", floatVal, 0.0f);
	LOG("  floatVal=%f\n", floatVal);
	ctrlBar.AddTrackbar("Float Val(x100):", floatVal, 200.0f, 2);
	
	sc.GetString("root.section.string_setting", strVal, "");
	LOG("  stringVal='%s'\n", strVal.c_str());
	
	sc.GetBool("root.section.bool_setting", boolVal, false);
	LOG("  boolVal=%s\n", boolVal ? "true" : "false");
	ctrlBar.AddCheckbox("Bool Val:", boolVal);
	
	
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));
	while(true)
	{
		imshow("Image", img);		
		if(waitKey(1) == 27)
			break;
	}
	
	LOG("END\n");
	return 0;
}
