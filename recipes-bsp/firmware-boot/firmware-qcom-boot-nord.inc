DESCRIPTION = "QCOM NHLOS Firmware for Qualcomm Nord platform"
LICENSE = "LICENSE.qcom-2"
LIC_FILES_CHKSUM = "file://${UNPACKDIR}/${BOOTBINARIES}/LICENSE.qcom-2.txt;md5=TODO_FILL_IN_NORD_LICENSE_MD5SUM"

FW_ARTIFACTORY = "artifactory-las.qualcomm.com/artifactory/lint-lv-local/nord-test"
BOOTBINARIES = "NORD_bootbinaries"

SRC_URI = " \
    https://${FW_ARTIFACTORY}/${BOOTBINARIES}.zip;name=bootbinaries \
    "

QCOM_BOOT_IMG_SUBDIR = "nord"

include firmware-qcom-boot-common.inc
