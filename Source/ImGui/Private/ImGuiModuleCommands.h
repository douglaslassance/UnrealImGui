// Distributed under the MIT License (MIT) (see accompanying LICENSE file)

#pragma once

#include <HAL/IConsoleManager.h>


struct FImGuiKeyInfo;
class FImGuiModuleProperties;

// Manges ImGui module console commands.
class FImGuiModuleCommands
{
public:

	static const TCHAR* const ToggleInput;
	static const TCHAR* const SetInput;
	static const TCHAR* const ToggleKeyboardNavigation;
	static const TCHAR* const SetKeyboardNavigation;
	static const TCHAR* const ToggleGamepadNavigation;
	static const TCHAR* const SetGamepadNavigation;
	static const TCHAR* const ToggleKeyboardInputSharing;
	static const TCHAR* const SetKeyboardInputSharing;
	static const TCHAR* const ToggleGamepadInputSharing;
	static const TCHAR* const SetGamepadInputSharing;
	static const TCHAR* const ToggleMouseInputSharing;
	static const TCHAR* const ToggleDemo;
	static const TCHAR* const SetDemo;

	FImGuiModuleCommands(FImGuiModuleProperties& InProperties);

	void SetKeyBinding(const TCHAR* CommandName, const FImGuiKeyInfo& KeyInfo);

private:

	void ToggleInputImpl();
	void SetInputImpl(const TArray<FString>& Args);
	void ToggleKeyboardNavigationImpl();
	void SetKeyboardNavigationImpl(const TArray< FString >& Args);
	void ToggleGamepadNavigationImpl();
	void SetGamepadNavigationImpl(const TArray< FString >& Args);
	void ToggleKeyboardInputSharingImpl();
	void SetKeyboardInputSharingImpl(const TArray< FString >& Args);
	void ToggleGamepadInputSharingImpl();
	void SetGamepadInputSharingImpl(const TArray< FString >& Args);
	void ToggleMouseInputSharingImpl();
	void ToggleDemoImpl();
	void SetDemoImpl(const TArray< FString >& Args);

	FImGuiModuleProperties& Properties;

	FAutoConsoleCommand ToggleInputCommand;
	FAutoConsoleCommand SetInputCommand;
	FAutoConsoleCommand ToggleKeyboardNavigationCommand;
	FAutoConsoleCommand SetKeyboardNavigationCommand;
	FAutoConsoleCommand ToggleGamepadNavigationCommand;
	FAutoConsoleCommand SetGamepadNavigationCommand;
	FAutoConsoleCommand ToggleKeyboardInputSharingCommand;
	FAutoConsoleCommand SetKeyboardInputSharingCommand;
	FAutoConsoleCommand ToggleGamepadInputSharingCommand;
	FAutoConsoleCommand SetGamepadInputSharingCommand;
	FAutoConsoleCommand ToggleMouseInputSharingCommand;
	FAutoConsoleCommand ToggleDemoCommand;
	FAutoConsoleCommand SetDemoCommand;
};
