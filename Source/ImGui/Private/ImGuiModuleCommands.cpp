// Distributed under the MIT License (MIT) (see accompanying LICENSE file)

#include "ImGuiModuleCommands.h"

#include "ImGuiModuleProperties.h"
#include "Utilities/DebugExecBindings.h"


const TCHAR* const FImGuiModuleCommands::ToggleInput = TEXT("ImGui.ToggleInput");
const TCHAR* const FImGuiModuleCommands::SetInput = TEXT("ImGui.SetInput");
const TCHAR* const FImGuiModuleCommands::ToggleKeyboardNavigation = TEXT("ImGui.ToggleKeyboardNavigation");
const TCHAR* const FImGuiModuleCommands::SetKeyboardNavigation = TEXT("ImGui.SetKeyboardNavigation");
const TCHAR* const FImGuiModuleCommands::ToggleGamepadNavigation = TEXT("ImGui.ToggleGamepadNavigation");
const TCHAR* const FImGuiModuleCommands::SetGamepadNavigation = TEXT("ImGui.SetGamepadNavigation");
const TCHAR* const FImGuiModuleCommands::ToggleKeyboardInputSharing = TEXT("ImGui.ToggleKeyboardInputSharing");
const TCHAR* const FImGuiModuleCommands::SetKeyboardInputSharing = TEXT("ImGui.SetKeyboardInputSharing");
const TCHAR* const FImGuiModuleCommands::ToggleGamepadInputSharing = TEXT("ImGui.ToggleGamepadInputSharing");
const TCHAR* const FImGuiModuleCommands::SetGamepadInputSharing = TEXT("ImGui.SetGamepadInputSharing");
const TCHAR* const FImGuiModuleCommands::ToggleMouseInputSharing = TEXT("ImGui.ToggleMouseInputSharing");
const TCHAR* const FImGuiModuleCommands::ToggleDemo = TEXT("ImGui.ToggleDemo");
const TCHAR* const FImGuiModuleCommands::SetDemo = TEXT("ImGui.SetDemo");

FImGuiModuleCommands::FImGuiModuleCommands(FImGuiModuleProperties& InProperties)
	: Properties(InProperties)
	, ToggleInputCommand(ToggleInput,
		TEXT("Toggle ImGui input mode."),
		FConsoleCommandDelegate::CreateRaw(this, &FImGuiModuleCommands::ToggleInputImpl))
	, SetInputCommand(SetInput,
		TEXT("Set ImGui keyboard navigation."),
		FConsoleCommandWithArgsDelegate::CreateRaw(this, &FImGuiModuleCommands::SetInputImpl))
	, ToggleKeyboardNavigationCommand(ToggleKeyboardNavigation,
		TEXT("Toggle ImGui keyboard navigation."),
		FConsoleCommandDelegate::CreateRaw(this, &FImGuiModuleCommands::ToggleKeyboardNavigationImpl))
	, SetKeyboardNavigationCommand(SetKeyboardNavigation,
		TEXT("Set ImGui keyboard navigation."),
		FConsoleCommandWithArgsDelegate::CreateRaw(this, &FImGuiModuleCommands::SetKeyboardNavigationImpl))
	, ToggleGamepadNavigationCommand(ToggleGamepadNavigation,
		TEXT("Toggle ImGui gamepad navigation."),
		FConsoleCommandDelegate::CreateRaw(this, &FImGuiModuleCommands::ToggleGamepadNavigationImpl))
	, SetGamepadNavigationCommand(SetGamepadNavigation,
		TEXT("Set ImGui gamepad navigation."),
		FConsoleCommandWithArgsDelegate::CreateRaw(this, &FImGuiModuleCommands::SetGamepadNavigationImpl))
	, ToggleKeyboardInputSharingCommand(ToggleKeyboardInputSharing,
		TEXT("Toggle ImGui keyboard input sharing."),
		FConsoleCommandDelegate::CreateRaw(this, &FImGuiModuleCommands::ToggleKeyboardInputSharingImpl))
	, SetKeyboardInputSharingCommand(SetKeyboardInputSharing,
		TEXT("Set ImGui keyboard input sharing."),
		FConsoleCommandWithArgsDelegate::CreateRaw(this, &FImGuiModuleCommands::SetKeyboardInputSharingImpl))
	, ToggleGamepadInputSharingCommand(ToggleGamepadInputSharing,
		TEXT("Toggle ImGui gamepad input sharing."),
		FConsoleCommandDelegate::CreateRaw(this, &FImGuiModuleCommands::ToggleGamepadInputSharingImpl))
	, SetGamepadInputSharingCommand(SetGamepadInputSharing,
		TEXT("Set ImGui gamepad input sharing."),
		FConsoleCommandWithArgsDelegate::CreateRaw(this, &FImGuiModuleCommands::SetGamepadInputSharingImpl))
	, ToggleMouseInputSharingCommand(ToggleMouseInputSharing,
		TEXT("Toggle ImGui mouse input sharing."),
		FConsoleCommandDelegate::CreateRaw(this, &FImGuiModuleCommands::ToggleMouseInputSharingImpl))
	, ToggleDemoCommand(ToggleDemo,
		TEXT("Toggle ImGui demo."),
		FConsoleCommandDelegate::CreateRaw(this, &FImGuiModuleCommands::ToggleDemoImpl))
	, SetDemoCommand(SetDemo,
		TEXT("Set ImGui mouse input sharing."),
		FConsoleCommandWithArgsDelegate::CreateRaw(this, &FImGuiModuleCommands::SetDemoImpl))
{
}

void FImGuiModuleCommands::SetKeyBinding(const TCHAR* CommandName, const FImGuiKeyInfo& KeyInfo)
{
	DebugExecBindings::UpdatePlayerInputs(KeyInfo, CommandName);
}

void FImGuiModuleCommands::ToggleInputImpl()
{
	Properties.ToggleInput();
}

void FImGuiModuleCommands::SetInputImpl(const TArray<FString>& Args)
{
	bool bIsEnabled = false;
	if (Args.Num() > 0)
	{
		LexFromString(bIsEnabled, *Args[0]);
	}
	Properties.SetInputEnabled(bIsEnabled);
}

void FImGuiModuleCommands::ToggleKeyboardNavigationImpl()
{
	Properties.ToggleKeyboardNavigation();
}

void FImGuiModuleCommands::SetKeyboardNavigationImpl(const TArray<FString>& Args)
{
	bool bIsEnabled = false;
	if (Args.Num() > 0)
	{
		LexFromString(bIsEnabled, *Args[0]);
	}
	Properties.SetKeyboardNavigationEnabled(bIsEnabled);
}

void FImGuiModuleCommands::ToggleGamepadNavigationImpl()
{
	Properties.ToggleGamepadNavigation();
}

void FImGuiModuleCommands::SetGamepadNavigationImpl(const TArray<FString>& Args)
{
	bool bIsEnabled = false;
	if (Args.Num() > 0)
	{
		LexFromString(bIsEnabled, *Args[0]);
	}
	Properties.SetGamepadNavigationEnabled(bIsEnabled);
}

void FImGuiModuleCommands::ToggleKeyboardInputSharingImpl()
{
	Properties.ToggleKeyboardInputSharing();
}

void FImGuiModuleCommands::SetKeyboardInputSharingImpl(const TArray<FString>& Args)
{
	bool bIsEnabled = false;
	if (Args.Num() > 0)
	{
		LexFromString(bIsEnabled, *Args[0]);
	}
	Properties.SetKeyboardInputShared(bIsEnabled);
}

void FImGuiModuleCommands::ToggleGamepadInputSharingImpl()
{
	Properties.ToggleGamepadInputSharing();
}

void FImGuiModuleCommands::SetGamepadInputSharingImpl(const TArray<FString>& Args)
{
	bool bIsEnabled = false;
	if (Args.Num() > 0)
	{
		LexFromString(bIsEnabled, *Args[0]);
	}
	Properties.SetGamepadInputShared(bIsEnabled);
}

void FImGuiModuleCommands::ToggleMouseInputSharingImpl()
{
	Properties.ToggleMouseInputSharing();
}

void FImGuiModuleCommands::ToggleDemoImpl()
{
	Properties.ToggleDemo();
}

void FImGuiModuleCommands::SetDemoImpl(const TArray<FString>& Args)
{
	bool bIsEnabled = false;
	if (Args.Num() > 0)
	{
		LexFromString(bIsEnabled, *Args[0]);
	}
	Properties.SetShowDemo(bIsEnabled);
}
