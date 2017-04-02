#ifndef UTILS
#define UTILS

#include <stdlib.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)

// Malloc utils, to get the memory space and verify it.
#define MALLOC(t, n) (t *) malloc((n) * sizeof(t))
#define MCHECK(x, m) if(!x){perror("MALLOC ERROR"); if(m)perror(m); exit(EXIT_FAILURE);}
#define MMALLOC(p, t, n, m) p = MALLOC(t, n); MCHECK(p, m);

// Realloc utils, to get the memory space and verify it.
#define REALLOC(t, p, n) (t *) realloc(p, (n) * sizeof(t))
#define RCHECK(x, m) if(!x){perror("REALLOC ERROR"); if(m)perror(m); exit(EXIT_FAILURE);}
#define RREALLOC(p, t, n, m) p = REALLOC(t, p, n); RCHECK(p, m);

// Define functions for Visual studio or UNIX (else)
#ifdef _MSC_VER
	#define STRDUP(t) _strdup(t)
	#define STRCMPI(b, t) _strcmpi(b, t)
	#define FOPEN(v, n, m, e, f) if(fopen_s(&v, n, m) != 0){throw CException(e, (char *) f);}
#else
	#define STRDUP(t) strdup(t)
	#define STRCMPI(b, t) strcasecmp(b, t)
	#define FOPEN(v, n, m, e, f) v = fopen(n, m); if(v == nullptr){throw CException(e, (char *) f);}
#endif

#define MISSING_VERTEX_INDEX_EXCEPTION 8792
#define MISSING_ARC_INDEX_EXCEPTION 8793
#define ARC_ALREADY_EXISTING_EXCEPTION 8794
#define VERTEX_ALREADY_EXISTING_EXCEPTION 8794

#endif
