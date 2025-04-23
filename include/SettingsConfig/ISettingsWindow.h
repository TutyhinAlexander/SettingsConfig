#ifndef __ISETTINGS_WINDOW_H_
#define __ISETTINGS_WINDOW_H_

#include <string>

namespace Tools
{
	typedef void(*TrackbarCallback) (int pos, void *userdata);
	typedef void(*ButtonCallback) (int state, void *userdata);
	
	class ISettingsWindow
	{
		public:
			//virtual void ShowWindow() = 0;
			virtual void AddButton(const char* btnName, ButtonCallback onChangeCallback, void* userData) = 0;
			virtual void AddCheckbox(const char* chkName, bool& setting, ButtonCallback onChangeCallback = NULL, void* userData = NULL) = 0;
			virtual void AddTrackbar(const char* settingName, int& setting, int maxVal, TrackbarCallback onChangeCallback = NULL, void* userData = NULL) = 0;
			virtual void AddTrackbar(const char* settingName, float& setting, float maxVal, int precision = 2, TrackbarCallback onChangeCallback = NULL, void* userData = NULL) = 0; // 10^(precision) multiplier for translate to int and back
	};
}

#endif // __ISETTINGS_WINDOW_H_
