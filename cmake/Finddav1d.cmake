#[=======================================================================[.rst:
Finddav1d
-------

Finds the dav1d library. dav1d is an AV1 cross-platform decoder, open-source, and focused on speed and correctness.
https://code.videolan.org/videolan/dav1d

Imported Targets
^^^^^^^^^^^^^^^^

This module provides the following imported targets, if found:

``dav1d::dav1d``
  The dav1d library

Result Variables
^^^^^^^^^^^^^^^^

This module defines the following variables:

``dav1d_FOUND``
  Boolean indicating whether (the requested version of) dav1d was found.
``dav1d_VERSION``
  The version of the dav1d library which was found.
``dav1d_INCLUDE_DIRS``
  Include directories needed to use dav1d.
``dav1d_LIBRARIES``
  Libraries needed to link to dav1d.

Cache Variables
^^^^^^^^^^^^^^^

The following cache variables may also be set:

``dav1d_INCLUDE_DIR``
  The directory containing ``dav1d.h``.
``dav1d_LIBRARY``
  The path to the dav1d library.

#]=======================================================================]

find_package(PkgConfig)
if(PkgConfig_FOUND)
    pkg_check_modules(PC_dav1d dav1d)
endif()

find_path(dav1d_INCLUDE_DIR
    NAMES dav1d.h
    HINTS ${PC_dav1d_INCLUDE_DIRS}
    PATH_SUFFIXES dav1d
)

find_library(dav1d_LIBRARY
    NAMES dav1d
    HINTS ${PC_dav1d_LIBRARY_DIRS}
)

set(dav1d_VERSION ${PC_dav1d_VERSION})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(dav1d
    REQUIRD_VARS
        dav1d_LIBRARY
        dav1d_INCLUDE_DIR
    # VERSION_VAR
    #     dav1d_VERSION
)

if(dav1d_FOUND)
    set(dav1d_LIBRARIES ${dav1d_LIBRARY})
    set(dav1d_INCLUDE_DIRS ${dav1d_INCLUDE_DIR})
    set(dav1d_DEFINITIONS ${PC_dav1d_CFLAGS_OTHER})
endif()


if(dav1d_FOUND AND NOT TARGET dav1d::dav1d)
    add_library(dav1d::dav1d UNKNOWN IMPORTED)
    set_target_properties(dav1d::dav1d PROPERTIES
        IMPORTED_LOCATION "${dav1d_LIBRARY}"
        INTERFACE_COMPILE_OPTIONS "${PC_dav1d_CLFAGS_OTHER}"
        INTERFACE_INCLUDE_DIRECTORIES "${dav1d_INCLUDE_DIR}"
    )
endif()
