#ifndef NOCHE_PLATFORM_H
#define NOCHE_PLATFORM_H

#ifdef NOCHE_WINDOWS
#ifdef NOCHE_DLL
#define NOCHE_API __declspec(dllexport)
#else
#define NOCHE_API __declspec(dllimport)
#endif
#else
#error Noche only support Windows now!
#endif

#endif //NOCHE_PLATFORM_H
