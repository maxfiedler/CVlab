EXECUTE_PROCESS( COMMAND "date" "+%Y%m%d" TIMEOUT 2 OUTPUT_VARIABLE BUILDDATE )
STRING( SUBSTRING ${BUILDDATE} 0 8 BUILDDATE )

FILE( WRITE "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/rpc/rec/rpc/rec_rpc_version.h.tmp"
"#define MajorVer 1
#define MinorVer 5
#define PatchVer 0
#define Suffix \"\"
#define BuildVer ${BUILDDATE}
#define BuildVerStr \"${BUILDDATE}\"
#define VersionString \"1.5.0 Build ${BUILDDATE}\"
#define MyAppName \"rec_rpc\"
#define MyAppExeName \"\"
#define MyCompany      \"REC GmbH\"
#define MyPublisherURL \"www.servicerobotics.eu\"
#define MySupportURL   \"www.servicerobotics.eu\"
#define MyUpdatesURL   \"www.servicerobotics.eu\"
" )

IF( EXISTS "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/rpc/rec/rpc/rec_rpc_version.h" )
	FILE( READ "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/rpc/rec/rpc/rec_rpc_version.h" CURRENT_VERSION_FILE )
	FILE( READ "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/rpc/rec/rpc/rec_rpc_version.h.tmp" TEMP_VERSION_FILE )
	IF( ${CURRENT_VERSION_FILE} STREQUAL ${TEMP_VERSION_FILE} )
	ELSE( ${CURRENT_VERSION_FILE} STREQUAL ${TEMP_VERSION_FILE} )
		CONFIGURE_FILE( "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/rpc/rec/rpc/rec_rpc_version.h.tmp" "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/rpc/rec/rpc/rec_rpc_version.h" COPYONLY )
	ENDIF( ${CURRENT_VERSION_FILE} STREQUAL ${TEMP_VERSION_FILE} )
ELSE( EXISTS "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/rpc/rec/rpc/rec_rpc_version.h" )
	CONFIGURE_FILE( "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/rpc/rec/rpc/rec_rpc_version.h.tmp" "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/rpc/rec/rpc/rec_rpc_version.h" COPYONLY )
ENDIF( EXISTS "/home/viki/WurzelWorkspace/src/build/api2/lib/rec/rpc/rec/rpc/rec_rpc_version.h" )
