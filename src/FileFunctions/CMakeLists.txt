add_library(filefunctions STATIC filefunctions.cxx getfile.cxx)
target_include_directories(filefunctions
                           INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include>
                           )