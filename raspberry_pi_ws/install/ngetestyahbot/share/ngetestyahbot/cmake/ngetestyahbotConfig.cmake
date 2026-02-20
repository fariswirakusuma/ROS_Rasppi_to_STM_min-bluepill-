# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_ngetestyahbot_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED ngetestyahbot_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(ngetestyahbot_FOUND FALSE)
  elseif(NOT ngetestyahbot_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(ngetestyahbot_FOUND FALSE)
  endif()
  return()
endif()
set(_ngetestyahbot_CONFIG_INCLUDED TRUE)

# output package information
if(NOT ngetestyahbot_FIND_QUIETLY)
  message(STATUS "Found ngetestyahbot: 0.0.0 (${ngetestyahbot_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'ngetestyahbot' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${ngetestyahbot_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(ngetestyahbot_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${ngetestyahbot_DIR}/${_extra}")
endforeach()
