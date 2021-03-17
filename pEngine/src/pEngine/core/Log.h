#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace pEngine {

	class DLL_API log {
	public:
		static void Init();
		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define PE_CORE_TRACE(...) ::pEngine::log::GetCoreLogger()->trace(__VA_ARGS__)
#define PE_CORE_INFO(...) ::pEngine::log::GetCoreLogger()->info(__VA_ARGS__)
#define PE_CORE_WARN(...) ::pEngine::log::GetCoreLogger()->warn(__VA_ARGS__)
#define PE_CORE_ERROR(...) ::pEngine::log::GetCoreLogger()->error(__VA_ARGS__)
#define PE_CORE_CRITICAL(...) ::pEngine::log::GetCoreLogger()->critical(__VA_ARGS__)


#define PE_TRACE(...) ::pEngine::log::GetClientLogger()->trace(__VA_ARGS__)
#define PE_INFO(...) ::pEngine::log::GetClientLogger()->info(__VA_ARGS__)
#define PE_WARN(...) ::pEngine::log::GetClientLogger()->warn(__VA_ARGS__)
#define PE_ERROR(...) ::pEngine::log::GetClientLogger()->error(__VA_ARGS__)
#define PE_CRITICAL(...) ::pEngine::log::GetClientLogger()->critical(__VA_ARGS__)
