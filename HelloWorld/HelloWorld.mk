##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=HelloWorld
ConfigurationName      :=Debug
WorkspacePath          :=/home/john/Dev/HelloWorld
ProjectPath            :=/home/john/Dev/HelloWorld
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=ubuntu-20.04.5
Date                   :=14/12/22
CodeLitePath           :=/home/john/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="HelloWorld.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdCXX_CMakeCXXCompilerId.cpp$(ObjectSuffix) $(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdC_CMakeCCompilerId.c$(ObjectSuffix) $(IntermediateDirectory)/src_Main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdCXX_CMakeCXXCompilerId.cpp$(ObjectSuffix): CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp $(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdCXX_CMakeCXXCompilerId.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/john/Dev/HelloWorld/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdCXX_CMakeCXXCompilerId.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdCXX_CMakeCXXCompilerId.cpp$(DependSuffix): CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdCXX_CMakeCXXCompilerId.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdCXX_CMakeCXXCompilerId.cpp$(DependSuffix) -MM CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp

$(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdCXX_CMakeCXXCompilerId.cpp$(PreprocessSuffix): CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdCXX_CMakeCXXCompilerId.cpp$(PreprocessSuffix) CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp

$(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdC_CMakeCCompilerId.c$(ObjectSuffix): CMakeFiles/3.16.3/CompilerIdC/CMakeCCompilerId.c $(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdC_CMakeCCompilerId.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/john/Dev/HelloWorld/CMakeFiles/3.16.3/CompilerIdC/CMakeCCompilerId.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdC_CMakeCCompilerId.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdC_CMakeCCompilerId.c$(DependSuffix): CMakeFiles/3.16.3/CompilerIdC/CMakeCCompilerId.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdC_CMakeCCompilerId.c$(ObjectSuffix) -MF$(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdC_CMakeCCompilerId.c$(DependSuffix) -MM CMakeFiles/3.16.3/CompilerIdC/CMakeCCompilerId.c

$(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdC_CMakeCCompilerId.c$(PreprocessSuffix): CMakeFiles/3.16.3/CompilerIdC/CMakeCCompilerId.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CMakeFiles_3.16.3_CompilerIdC_CMakeCCompilerId.c$(PreprocessSuffix) CMakeFiles/3.16.3/CompilerIdC/CMakeCCompilerId.c

$(IntermediateDirectory)/src_Main.cpp$(ObjectSuffix): src/Main.cpp $(IntermediateDirectory)/src_Main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/john/Dev/HelloWorld/src/Main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Main.cpp$(DependSuffix): src/Main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Main.cpp$(DependSuffix) -MM src/Main.cpp

$(IntermediateDirectory)/src_Main.cpp$(PreprocessSuffix): src/Main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Main.cpp$(PreprocessSuffix) src/Main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


