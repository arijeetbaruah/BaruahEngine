// BaruahEngine.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <BaruahEngine.h>

class SandboxApp : public BaruahEngine::Application
{
public:
	SandboxApp();
	~SandboxApp();
};

BaruahEngine::Application* BaruahEngine::CreateApplication()
{
	return new SandboxApp();
}
