#ifndef ERROR_FUNCTION_H
    #define ERROR_FUNCTION_H
    void errMsg(const char *form,...);
    #ifdef __GNUC__
        #define NORETURN __attribute__ ((__noreturn__))
    #else
        #define NORETURN
    #endif 
    void errExit(const char *format,...) NORETURN;
    void err_exit(const char *format,...) NORETURN;
    void errExitEn(int errnum,const char* format,...) NORETURN;
    void fatal(const char *format,...)NORETURN;
    void usageErr(const char *format,...)NORETURN;
    void cmdLineErr(const char *format,...)NORETURN;
#endif