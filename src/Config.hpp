#ifndef TR_CONFIG_HPP
#define TR_CONFIG_HPP

#ifdef TR_SOURCE
#define TR_DLL __declspec(dllexport)
#else
#define TR_DLL __declspec(dllimport)
#endif

#endif
