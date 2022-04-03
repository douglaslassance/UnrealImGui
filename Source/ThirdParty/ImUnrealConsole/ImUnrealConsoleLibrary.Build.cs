using System.Collections.Generic;
using System.IO;
using UnrealBuildTool;

//=================================================================================================
// Imgui Unreal Console Command library
//
// Sources files for displaying a Dear Imgui window with all of the Unreal Console Commands
// listed. Can be filtered and executed.
//
// Original code can be found as part of the UnrealNetImgui library
// (Can be found here : https://github.com/sammyfreg/UnrealNetImgui)
//
// Code is actually compiled under ThirdPartyBuildImUnrealConsole.cpp
//=================================================================================================

public class ImUnrealConsoleLibrary : ModuleRules
{
#if WITH_FORWARDED_MODULE_RULES_CTOR
	public ImUnrealConsoleLibrary(ReadOnlyTargetRules Target) : base(Target)
#else
	public ImUnrealConsoleLibrary(TargetInfo Target)
#endif
	{
		Type = ModuleType.External;
	}
}
