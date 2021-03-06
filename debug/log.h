#ifndef NOCHE_LOG_H
#define NOCHE_LOG_H

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace bomb
{
class Log
{
public:
  template<typename... Args>
  static void trace(const char* format, const Args&... args)
  {
    logger.spdlogger->trace(format, args...);
  }

  template<typename... Args>
  static void debug(const char* format, const Args&... args)
  {
    logger.spdlogger->debug(format, args...);
  }

  template<typename... Args>
  static void info(const char* format, const Args&... args)
  {
    logger.spdlogger->info(format, args...);
  }

  template<typename... Args>
  static void warn(const char* format, const Args&... args)
  {
    logger.spdlogger->warn(format, args...);
  }

  template<typename... Args>
  static void error(const char* format, const Args&... args)
  {
    logger.spdlogger->error(format, args...);
  }

  template<typename... Args>
  static void critical(const char* format, const Args&... args) 
  {
    logger.spdlogger->critical(format, args...);
  }

private:
  static Log logger;

private:
  Log();

  std::shared_ptr<spdlog::logger> spdlogger;
};

using log = Log;

#define ASSERT(condition, ...) \
    { if (!(condition)) { Noche::Log::Info("Assertion failed: {0} at {1} {2}", __VA_ARGS__, __FILE__, __LINE__); __debugbreak(); } }
}

#endif //NOCHE_LOG_H
