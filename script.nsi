!define APPNAME "MediaKeys"
!define COMPANYNAME "woodruffw-software"
!define DESCRIPTION "Emulates volume control on keyboards without volume keys."
!define VERSIONMAJOR 1.0
!define ABOUTURL "https://github.com/woodruffw"

LicenseData "LICENSE"
Name "${COMPANYNAME} - ${APPNAME}"
Icon "icon.ico"
outFile "install.exe"
InstallDir "$PROGRAMFILES\${COMPANYNAME}\${APPNAME}"

!include LogicLib.nsh

page license
page directory
page instfiles
uninstPage uninstConfirm
uninstPage instfiles

section "install"
	setOutPath $INSTDIR
	file "MediaKeys.exe"
	file "MediaKeys.c"
	file "LICENSE"
	file "README.txt"
	writeRegStr HKEY_LOCAL_MACHINE "Software\Microsoft\Windows\CurrentVersion\Run" \
	"MediaKeys" "$INSTDIR\MediaKeys.exe"
	writeUninstaller "$INSTDIR\uninst.exe"
sectionEnd

section "uninstall"
	delete $INSTDIR\MediaKeys.exe
	delete $INSTDIR\MediaKeys.c
	delete $INSTDIR\LICENSE
	delete $INSTDIR\README.txt
	delete $INSTDIR\uninst.exe
	rmDir $INSTDIR
sectionEnd
