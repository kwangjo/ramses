ACME_MODULE(
    #==========================================================================
    # general module information
    #==========================================================================
    NAME                    ivi-gears
    TYPE                    BINARY
    ENABLE_INSTALL          ON

    #==========================================================================
    # files of this module
    #==========================================================================
    FILES_SOURCE            gears.c

    #==========================================================================
    # dependencies
    #==========================================================================
    DEPENDENCIES            EGL
                            OpenGL
                            wayland-client
                            wayland-egl
                            wayland-ivi-extension
)
