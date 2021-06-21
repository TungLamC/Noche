#include <debug/log.h>

namespace lam
{
log::log() 
{
  spdlog::set_pattern("%^%Y-%m-%d-%H %H:%M:%S.%e [%n]: %v%$");
  logger.spdlogger = spdlog::stdout_color_mt("ENGINE");
  logger.spdlogger->set_level(spdlog::level::trace);
}

log log::logger;
}
