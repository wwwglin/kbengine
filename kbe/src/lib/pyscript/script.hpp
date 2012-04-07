/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 kbegine Software Ltd
Also see acknowledgements in Readme.html

You may use this sample code for anything you like, it is not covered by the
same license as the rest of the engine.
*/
#ifndef __KBENGINE_SCRIPT_H__
#define __KBENGINE_SCRIPT_H__
#include "helper/debug_helper.hpp"
#include "cstdkbe/cstdkbe.hpp"
#include "cstdkbe/singleton.hpp"
#include "scriptobject.hpp"
#include "scriptstdouterr.hpp"
#include "scriptstdouterrhook.hpp"

namespace KBEngine{ namespace script{

/** 脚本系统路径 */
#define SCRIPT_PATH												\
					L"../../res/script;"						\
					L"../../res/script/common;"					\
					L"../../res/script/common/lib-dynload;"		\
					L"../../res/script/common/Lib"

class Script
{						
public:	
	Script();
	virtual ~Script();
	
	/** 安装和卸载脚本模块 */
	virtual bool install(wchar_t* pythonHomeDir, std::wstring pyPaths, const char* moduleName);
	virtual bool uninstall(void);
	
	/** 获取脚本基础模块 */
	PyObject* getModule(void)const { return m_module_; }

	int Run_SimpleString(std::string command, std::string* retBufferPtr);


	int registerToModule(const char* attrName, PyObject* pyObj);

protected:
	PyObject* 					m_module_;
	ScriptStdOutErr*			m_pyStdouterr_;
	ScriptStdOutErrHook*		m_pyStdouterrHook_;	// 提供telnet 执行脚本回显用
} ;

}
}
#endif