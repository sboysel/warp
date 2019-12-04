#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* .Call calls */
extern SEXP timewarp_warp_group(SEXP, SEXP, SEXP, SEXP);
extern SEXP timewarp_warp_breaks(SEXP, SEXP, SEXP, SEXP);
extern SEXP timewarp_warp_changes(SEXP);
extern SEXP timewarp_warp_ranges(SEXP);
extern SEXP timewarp_class_type(SEXP);

// Defined below
SEXP timewarp_init_library(SEXP);

static const R_CallMethodDef CallEntries[] = {
  {"timewarp_warp_group",        (DL_FUNC) &timewarp_warp_group, 4},
  {"timewarp_warp_breaks",       (DL_FUNC) &timewarp_warp_breaks, 4},
  {"timewarp_warp_changes",      (DL_FUNC) &timewarp_warp_changes, 1},
  {"timewarp_warp_ranges",       (DL_FUNC) &timewarp_warp_ranges, 1},
  {"timewarp_class_type",        (DL_FUNC) &timewarp_class_type, 1},
  {"timewarp_init_library",      (DL_FUNC) &timewarp_init_library, 1},
  {NULL, NULL, 0}
};

void R_init_timewarp(DllInfo *dll)
{
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}

void timewarp_init_utils(SEXP ns);

SEXP timewarp_init_library(SEXP ns) {
  timewarp_init_utils(ns);
  return R_NilValue;
}