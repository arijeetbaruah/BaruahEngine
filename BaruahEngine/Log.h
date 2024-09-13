#pragma once

#include "Core.h"


#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace BaruahEngine
{
	class BARUAH_API Log
	{
	public:
		static void Initialize();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
};

//Core Log Marcos
#define BE_CORE_ERROR(...)	::BaruahEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BE_CORE_WARN(...)	::BaruahEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BE_CORE_INFO(...)	::BaruahEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BE_CORE_TRACE(...)	::BaruahEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)

//Client Log Marcos			
#define BE_ERROR(...)		::BaruahEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define BE_WARN(...)		::BaruahEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BE_INFO(...)		::BaruahEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define BE_TRACE(...)		::BaruahEngine::Log::GetClientLogger()->trace(__VA_ARGS__)

