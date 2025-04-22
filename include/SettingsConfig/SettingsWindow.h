#ifndef __SETTINGS_WINDOW_H_
#define __SETTINGS_WINDOW_H_

// Create controls window for existing openCV window
// Before creating any control you should create parent namedWindow first (see example)
// Note!!! This class doesn't work without parent namedWindow. It works like additional control panel for other window
// On runtime to open contrls panel use window top menu or press Ctrl+p

#include "SettingsConfig/ISettingsWindow.h"
#include <map>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

namespace Tools
{
    struct FloatToIntInfo
    {
	float* srcValue;
	int precisionCoeff; // = pow(10, precision)
	int value;
	TrackbarCallback onChangeCallback;
	void* userData;
	
	FloatToIntInfo(float* src, int pCoeff, int val, TrackbarCallback callback, void* data)
	{
	    srcValue = src;
	    precisionCoeff = pCoeff;
	    value = val;
	    onChangeCallback = callback;
	    userData = data;
	}
    };
    
    class SettingsWindow : public ISettingsWindow
    {
	private:
	    map<const char*, FloatToIntInfo*> floatSettings;
	    
	    static void onFloatTrackbarChanged(int pos, void *userdata);
	    
	public:
	    ~SettingsWindow();
	
	    void AddButton(const char* btnName, ButtonCallback onChangeCallback, void* userData);
	    void AddCheckbox(const char* chkName, ButtonCallback onChangeCallback, void* userData);
	    void AddTrackbar(const char* settingName, int& setting, int maxVal, TrackbarCallback onChangeCallback = NULL, void* userData = NULL);
	    void AddTrackbar(const char* settingName, float& setting, float maxVal, int precision = 2, TrackbarCallback onChangeCallback = NULL, void* userData = NULL); // 10^(precision) multiplier for translate to int and back
    };
} // namespace DebugTools

#endif // __SETTINGS_WINDOW_H_

