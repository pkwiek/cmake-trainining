#ifndef PLUGINEXAMPLE_COMPILEDEF_H
#define PLUGINEXAMPLE_COMPILEDEF_H

#if WIN32
    #if BUILD
            #define API __declspec(dllexport)
    #elif
            #define API __declspec(dllimport)
    #endif
#else
        #define API

#endif // PLUGINEXAMPLE_COMPILEDEF_H
