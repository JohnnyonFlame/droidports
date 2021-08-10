cmake_minimum_required(VERSION 3.2)

set(VITA_APP_NAME "GMLoader")
set(VITA_TITLEID  "JFLM00001")
set(VITA_VERSION  "01.00")

set(PORT_BRIDGE_SOURCES
    "bridges/freetype_bridge.c"
    "bridges/openal_bridge.c"
    "bridges/zip_bridge.c"
)