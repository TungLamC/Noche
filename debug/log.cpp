#include <debug/log.h>

namespace bomb
{
Log::Log() 
{
  spdlog::set_pattern("%^%Y-%m-%d-%H %H:%M:%S.%e [%n]: %v%$");
  logger.spdlogger = spdlog::stdout_color_mt("ENGINE");
  logger.spdlogger->set_level(spdlog::level::trace);
}

Log Log::logger;
}
