#ifndef __headers_h_
#define __headers_h_

// WARNING: USE CORRECTLY!
#define _FUNC(func) ((int*)(func))

// CREATE GTK APP
int CreateGTKAPP(const char* __appID, int* __FUNC, int argc, char** argv);

const char* GET_CSS_PATH_1(const char* __TOML_CONFIG);

const char* GET_CSS_PATH_2(const char* _TOML_CONFIG);

#endif // __headers_h_
