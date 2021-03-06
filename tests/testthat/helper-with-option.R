# withr::with_envvar()
with_envvar <- function (new, code) {
  old <- set_envvar(envs = new)
  on.exit(set_envvar(old))
  force(code)
}

set_envvar <- function(envs, action = "replace") {
  if (length(envs) == 0)
    return()
  stopifnot(is.named(envs))
  stopifnot(is.character(action), length(action) == 1)
  action <- match.arg(action, c("replace", "prefix", "suffix"))
  envs <- envs[!duplicated(names(envs), fromLast = TRUE)]
  old <- Sys.getenv(names(envs), names = TRUE, unset = NA)
  set <- !is.na(envs)
  both_set <- set & !is.na(old)
  if (any(both_set)) {
    if (action == "prefix") {
      envs[both_set] <- paste(envs[both_set], old[both_set])
    }
    else if (action == "suffix") {
      envs[both_set] <- paste(old[both_set], envs[both_set])
    }
  }
  if (any(set))
    do.call("Sys.setenv", as.list(envs[set]))
  if (any(!set))
    Sys.unsetenv(names(envs)[!set])
  invisible(old)
}

is.named <- function (x) {
  !is.null(names(x)) && all(names(x) != "")
}
