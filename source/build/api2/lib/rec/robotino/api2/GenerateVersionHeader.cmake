EXECUTE_PROCESS( COMMAND "date" "+%Y%m%d" TIMEOUT 2 OUTPUT_VARIABLE BUILDDATE )
STRING( SUBSTRING ${BUILDDATE} 0 8 BUILDDATE )

FILE( WRITE "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/robotino/api2/rec_robotino_api2_version.h.tmp"
"#define MajorVer 0
#define MinorVer 8
#define PatchVer 4
#define Suffix \"\"
#define BuildVer ${BUILDDATE}
#define BuildVerStr \"${BUILDDATE}\"
#define VersionString \"0.8.4 Build ${BUILDDATE}\"
#define MyAppName \"rec_robotino_api2\"
#define MyAppExeName \"\"
#define MyCompany      \"REC GmbH\"
#define MyPublisherURL \"www.servicerobotics.eu\"
#define MySupportURL   \"www.servicerobotics.eu\"
#define MyUpdatesURL   \"www.servicerobotics.eu\"
" )

IF( EXISTS "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/robotino/api2/rec_robotino_api2_version.h" )
	FILE( READ "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/robotino/api2/rec_robotino_api2_version.h" CURRENT_VERSION_FILE )
	FILE( READ "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/robotino/api2/rec_robotino_api2_version.h.tmp" TEMP_VERSION_FILE )
	IF( ${CURRENT_VERSION_FILE} STREQUAL ${TEMP_VERSION_FILE} )
	ELSE( ${CURRENT_VERSION_FILE} STREQUAL ${TEMP_VERSION_FILE} )
		CONFIGURE_FILE( "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/robotino/api2/rec_robotino_api2_version.h.tmp" "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/robotino/api2/rec_robotino_api2_version.h" COPYONLY )
	ENDIF( ${CURRENT_VERSION_FILE} STREQUAL ${TEMP_VERSION_FILE} )
ELSE( EXISTS "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/robotino/api2/rec_robotino_api2_version.h" )
	CONFIGURE_FILE( "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/robotino/api2/rec_robotino_api2_version.h.tmp" "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/robotino/api2/rec_robotino_api2_version.h" COPYONLY )
ENDIF( EXISTS "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/robotino/api2/rec_robotino_api2_version.h" )
