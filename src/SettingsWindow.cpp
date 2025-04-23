#include "SettingsConfig/SettingsWindow.h"
#include <cmath>
//#include <iostream>

using namespace cv;
using namespace std;

namespace Tools
{
    SettingsWindow::~SettingsWindow()
    {
	for(const auto& pair : floatSettings)
	    delete(pair.second);
	for(const auto& pair : boolSettings)
	    delete(pair.second);	    
    }
 
    void SettingsWindow::OnFloatTrackbarChanged(int pos, void *userdata)
    {
	FloatToIntInfo* info = (FloatToIntInfo*)userdata;
	*(info->srcValue) = (float)(info->value) / info->precisionCoeff;
	if(info->onChangeCallback != NULL)
	    info->onChangeCallback(pos, info->userData);
    }
    
    void SettingsWindow::OnCheckboxChanged(int state, void *userdata)
    {
	CheckboxInfo* info = (CheckboxInfo*)userdata;
	*(info->srcValue) = state == 1 ? true : false;
	if(info->onChangeCallback != NULL)
	    info->onChangeCallback(state, info->userData);
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
	createTrackbar(settingName, "", &info->value, maxVal, &SettingsWindow::OnFloatTrackbarChanged, (void*)info);
    }
    
    void SettingsWindow::AddButton(const char* btnName, ButtonCallback onChangeCallback, void* userData)
    {
	createButton(btnName, onChangeCallback, userData, QT_PUSH_BUTTON);
    }
    
    void SettingsWindow::AddCheckbox(const char* chkName, bool& setting, ButtonCallback onChangeCallback, void* userData)
    {
	CheckboxInfo* info = new CheckboxInfo(&setting, onChangeCallback, userData);
	boolSettings[chkName] = info;
	createButton(chkName, &SettingsWindow::OnCheckboxChanged, (void*)info, QT_CHECKBOX, setting);
    }

	
} // namespace DebugTools
