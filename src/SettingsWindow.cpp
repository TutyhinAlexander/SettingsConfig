#include "SettingsConfig/SettingsWindow.h"
#include <cmath>
#include <iostream>
#include <utility>

using namespace cv;
using namespace std;

namespace Tools
{
    SettingsWindow::~SettingsWindow()
    {
	for(const auto& pair : floatSettings)
	    delete(pair.second);
    }
 
    void SettingsWindow::onFloatTrackbarChanged(int pos, void *userdata)
    {
	pair<SettingsWindow*, const char*>* params = (pair<SettingsWindow*, const char*>*)userdata;
	const char* settingName = params->second;
	FloatToIntInfo* info = params->first->floatSettings[settingName];
	*(info->srcValue) = (float)(info->value) / info->precisionCoeff;
	if(info->onChangeCallback != NULL)
	{
	    info->onChangeCallback(pos, info->userData);
	}
    }
    
    void SettingsWindow::AddTrackbar(const char* settingName, int& setting, int maxVal, TrackbarCallback onChangeCallback, void* userData)
    {
	createTrackbar(settingName, "", &setting, maxVal, onChangeCallback, userData);
    }
	
    // 10^(precision) multiplier for translate to int and back
    void SettingsWindow::AddTrackbar(const char* settingName, float& setting, float maxSetting, int precision, TrackbarCallback onChangeCallback, void* userData)
    {
	int precisionCoeff = pow(10, precision);
	int val = (int)(setting * precisionCoeff);
	int maxVal = (int)(maxSetting * precisionCoeff);
	FloatToIntInfo* info = new FloatToIntInfo(&setting, precisionCoeff, val, onChangeCallback, userData);
	floatSettings[settingName] = info;
	pair<SettingsWindow*, const char*>* params = new std::pair<SettingsWindow*, const char*>(this, settingName);
	createTrackbar(settingName, "", &info->value, maxVal, &SettingsWindow::onFloatTrackbarChanged, (void*)params);
    }
    
    void SettingsWindow::AddButton(const char* btnName, ButtonCallback onChangeCallback, void* userData)
    {
	createButton(btnName, onChangeCallback, userData, QT_PUSH_BUTTON);
    }
    
    void SettingsWindow::AddCheckbox(const char* chkName, ButtonCallback onChangeCallback, void* userData)
    {
	createButton(chkName, onChangeCallback, userData, QT_CHECKBOX, *((bool*)userData));
    }

	
} // namespace DebugTools
