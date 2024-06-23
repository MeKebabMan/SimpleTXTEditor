#include "../toml.h"
#include "../_headers_.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// MEMORY ALLOCATIONS HAVE BEEN USED HERE!!
// REMINDER TO CHECK FOR UNFREED MEMORY ALLOCATION 
// REMINDER TO CLEAN UP THE CODE!!!

// GET CSS PATH 1

const char *GET_CSS_PATH_1(const char *__TOML_CONFIG) {

  // MEMORY ALLOCATED! SHOULD BE FREED!!
  // 1: TOML_PTR
  // 2: toml

  FILE *TOML_PTR = fopen(__TOML_CONFIG, "r");
  if (TOML_PTR == H_NO) {
    printf("%s", __TOML_CONFIG);
    return H_NO;
  }

  char ERRBUFF[255];
  toml_table_t *toml = toml_parse_file(TOML_PTR, ERRBUFF, sizeof(ERRBUFF));
  if (toml == H_NO) {
    printf("%s", ERRBUFF);
    fclose(TOML_PTR);
    return H_NO;
  }

  toml_table_t *CSS_PROP = toml_table_in(toml, "CSS");
  if (CSS_PROP == H_NO) {
    toml_free(CSS_PROP);
    fclose(TOML_PTR);
    return H_NO;
  }

  toml_datum_t CSS_PATH = toml_string_in(CSS_PROP, "PATH");
  if (!CSS_PATH.ok) {
    toml_free(toml);
    fclose(TOML_PTR);
    return H_NO;
  }

  toml_free(toml);
  fclose(TOML_PTR);

  return (const char *)CSS_PATH.u.s;
}

// GET CSS PATH 2

const char *GET_CSS_PATH_2(const char *__TOML_CONFIG) {

  // MEMORY ALLOCATED! SHOULD BE FREED!!
  // 1: TOML_PTR 
  // 2: toml 

  FILE *TOML_PTR = fopen(__TOML_CONFIG, "r");
  if (TOML_PTR == H_NO) {
    return H_NO;
  }

  char ERRBUFF[255];
  toml_table_t *toml = toml_parse_file(TOML_PTR, ERRBUFF, sizeof(ERRBUFF));
  if (toml == H_NO) {
    printf("%s", ERRBUFF);
    fclose(TOML_PTR);
    return H_NO;
  }

  toml_table_t *CSS_PROP = toml_table_in(toml, "CSS");
  if (CSS_PROP == H_NO) {
    toml_free(toml);
    fclose(TOML_PTR);
    return H_NO;
  }

  toml_datum_t CSS_INSTALL_PATH = toml_string_in(CSS_PROP, "INSTALL");
  if (!CSS_INSTALL_PATH.ok) {
    toml_free(toml);
    fclose(TOML_PTR);
    return H_NO;
  }

  toml_free(toml);
  fclose(TOML_PTR);

  return (const char *)CSS_INSTALL_PATH.u.s;
}

// bool
H_BOOL UPDATE_TOML_BUTTON_OPTIONS(const char* __TOML_CONFIG, Button_Options_struct* _OPTIONS) {

	// MEMORY ALLOACTED! SHOULD BE FREED!! 
	// 1: TOML_PTR 
	// 2: buffer 
	// 3: toml 

	FILE* TOML_PTR = fopen(__TOML_CONFIG, "r");
	if (TOML_PTR == NULL) {
		return H_ERR;
	}

	const unsigned int buffer_size = 255;
	char* buffer = (char*)calloc(buffer_size, sizeof(char));
	if (buffer == NULL) {
		fclose(TOML_PTR);
		return H_ERR;
	}

	toml_table_t* toml = toml_parse_file(TOML_PTR, buffer, buffer_size);
	if (toml == NULL) {
		free(buffer);
		fclose(TOML_PTR);
		return H_ERR;
	}

	toml_table_t* BUTTON_PROP = toml_table_in(toml, "BUTTON");
	if (BUTTON_PROP == NULL) {
		toml_free(toml);
		free(buffer);
		fclose(TOML_PTR);
		return H_ERR;
	}

	// GET OPTIONS 
	toml_datum_t _USE_SAVEFILE = toml_bool_in(BUTTON_PROP, "USE_SAVEFILE");
	toml_datum_t _USE_OPENFILE = toml_bool_in(BUTTON_PROP, "USE_OPENFILE");
	toml_datum_t _USE_QUIT = toml_bool_in(BUTTON_PROP, "USE_QUIT");

	// SAFETY
	if (_USE_SAVEFILE.ok) {
		// BOOL SAFETY
		if (_USE_SAVEFILE.u.b == false || _USE_SAVEFILE.u.b == true) {
			_OPTIONS->use_savefile = _USE_SAVEFILE.u.b;	
		}
	}
	
	// SAFETY 
	if (_USE_OPENFILE.ok) {
		// BOOL SAFETY
		if (_USE_OPENFILE.u.b == false || _USE_OPENFILE.u.b == true) {
			_OPTIONS->use_openfile = _USE_OPENFILE.u.b;	
		}
	}

	// SAFETY 
	if (_USE_QUIT.ok) {
		// BOOL SAFETY
		if (_USE_QUIT.u.b == false || _USE_QUIT.u.b == true) {
			_OPTIONS->use_quit = _USE_QUIT.u.b;	
		}
	}

	free(buffer);
	toml_free(toml);
	fclose(TOML_PTR);

	return H_OK;
}
