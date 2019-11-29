#ifndef TIMESLIDE_UTILS_H
#define TIMESLIDE_UTILS_H

#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>

enum timeslide_unique_type {
  timeslide_unique_year,
  timeslide_unique_month,
  timeslide_unique_week,
  timeslide_unique_day,
  timeslide_unique_hour,
  timeslide_unique_minute,
  timeslide_unique_second,
  timeslide_unique_millisecond
};

enum timeslide_unique_type as_unique_type(int type);

#endif