#ifndef NOCHE_LOG_H
#define NOCHE_LOG_H

#include <spdlog/spdlog.h>

namespace Noche
{
class Log
{
public:
  template<typename... Args>
  static void Trace(const char* format, const Args&... args)
  {
    logger.spdlogger->trace(format, args...);
  }

  template<typename... Args>
  static void Debug(const char* format, const Args&... args)
  {
    logger.spdlogger->debug(format, args...);
  }

  template<typename... Args>
  static void Info(const char* format, const Args&... args)
  {
    logger.spdlogger->info(format, args...);
  }

  template<typename... Args>
  static void Warn(const char* format, const Args&... args)
  {
    logger.spdlogger->warn(format, args...);
  }

  template<typename... Args>
  static void Error(const char* format, const Args&... args)
  {
    logger.spdlogger->error(format, args...);
  }

  template<typename... Args>
  static void Critical(const char* format, const Args&... args) 
  {
    logger.spdlogger->critical(format, args...);
  }

private:
  static Log logger;

private:
  Log();

  std::shared_ptr<spdlog::logger> spdlogger;
};
}

#endif //NOCHE_LOG_H
